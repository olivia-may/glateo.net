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

### Esperanto
cd $source_dir/glateo.net/eo
for file_name in ${html_files[@]}; do

    ../../src/rpl '@head-links' '''<link rel="icon" href="pride-flag.ico">
        <link rel="stylesheet" href="../reset.css">
        <link rel="stylesheet" href="../retpagaro.css">''' $file_name
    ../../src/rpl '@header' '''<header>
            <h1><a href="hejmo">glateo.net</a></h1>
            <a href="demandoj-kaj-respondoj">Demandoj kaj Respondoj</a>
            <a href="icxismo-kaj-ipismo">I&#265ismo kaj Ipismo</a>
            <a href="parentismo">Parentismo</a>
            <a href="riismo">Riismo</a>
            <a href="vortaro.php">Vortaro</a>
        </header>''' $file_name
    ../../src/rpl '@language-menu' '''<div id="language-menu">
                <a href='''"\"../eo/$file_name\""'''>Esperanto</a>
                <a href='''"\"../en/$file_name\""'''>English</a>
            </div>''' $file_name
    ../../src/rpl '@footer' '''<footer>
            <a href="pri">Pri</a>
            <a href="rimedoj">Listo de &#264iuj Rimedoj</a>
        </footer>''' $file_name

done

### English
cd $source_dir/glateo.net/en
for file_name in ${html_files[@]}; do

    ../../src/rpl '@head-links' '''<link rel="icon" href="pride-flag.ico">
        <link rel="stylesheet" href="../reset.css">
        <link rel="stylesheet" href="../retpagaro.css">''' $file_name
    ../../src/rpl '@header' '''<header>
            <h1><a href="hejmo">glateo.net</a></h1>
            <a href="demandoj-kaj-respondoj">Questions and Answers</a>
            <a href="icxismo-kaj-ipismo">I&#265ismo and Ipismo</a>
            <a href="parentismo">Parentismo</a>
            <a href="riismo">Riismo</a>
            <a href="vortaro.php">Dictionary</a>
        </header>''' $file_name
    ../../src/rpl '@language-menu' '''<div id="language-menu">
                <a href='''"\"../eo/$file_name\""'''>Esperanto</a>
                <a href='''"\"../en/$file_name\""'''>English</a>
            </div>''' $file_name
    ../../src/rpl '@footer' '''<footer>
            <a href="pri">About</a>
            <a href="rimedoj">List of all sources</a>
        </footer>''' $file_name

done
