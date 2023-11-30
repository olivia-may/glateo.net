#!/usr/bin/env bash

glateo_files=(
    '.htaccess'
    'reset.css'
    'retpagaro.css'
)
html_files=(
    'demandoj-kaj-respondoj'
    'icxismo-kaj-ipismo'
    'hejmo'
    'parentismo'
    'pri'
    'riismo'
    'rimedoj'
    'vortaro.php'
)
binary_files=(
    'pride-flag.ico'
)

source_dir=$(pwd)

rm -rf glateo.net/
mkdir -p $source_dir/glateo.net
mkdir -p $source_dir/glateo.net/eo
mkdir -p $source_dir/glateo.net/en

cp ${glateo_files[*]} ${binary_files[*]} $source_dir/glateo.net/
cd $source_dir/eo/
cp ${html_files[*]} $source_dir/glateo.net/eo/
cd $source_dir/en/
cp ${html_files[*]} $source_dir/glateo.net/en/

# for all languages of the site
function replace_keywords() {

    ../../src/rpl '@head-content' '''<meta charset="UTF-8">
        <link rel="icon" href="pride-flag.ico">
        <link rel="stylesheet" href="../reset.css">
        <link rel="stylesheet" href="../retpagaro.css">''' $1
    ../../src/rpl '@language-menu' '''<div id="language-menu">
                <a href='''"\"../eo/$1\""'''>Esperanto</a>
                <a href='''"\"../en/$1\""'''>English</a>
            </div>''' $1
}

### Esperanto
cd $source_dir/glateo.net/eo
for file_name in ${html_files[@]}; do

    replace_keywords $file_name

    ../../src/rpl '@header' '''<header>
            <h1><a href="hejmo">glateo.net</a></h1>
            <a href="demandoj-kaj-respondoj">Demandoj kaj Respondoj</a>
            <a href="icxismo-kaj-ipismo">Iĉismo kaj Ipismo</a>
            <a href="parentismo">Parentismo</a>
            <a href="riismo">Riismo</a>
            <a href="vortaro.php">Vortaro</a>
        </header>''' $file_name
    ../../src/rpl '@footer' '''<footer>
            <a href="pri">Pri</a>
            <a href="rimedoj">Listo de Ĉiuj Rimedoj</a>
        </footer>''' $file_name

done

### English
cd $source_dir/glateo.net/en
for file_name in ${html_files[@]}; do

    replace_keywords $file_name
    
    ../../src/rpl '@header' '''<header>
            <h1><a href="hejmo">glateo.net</a></h1>
            <a href="demandoj-kaj-respondoj">Questions and Answers</a>
            <a href="icxismo-kaj-ipismo">I&#265ismo and Ipismo</a>
            <a href="parentismo">Parentismo</a>
            <a href="riismo">Riismo</a>
            <a href="vortaro.php">Dictionary</a>
        </header>''' $file_name
    ../../src/rpl '@footer' '''<footer>
            <a href="pri">About</a>
            <a href="rimedoj">List of all sources</a>
        </footer>''' $file_name

done
