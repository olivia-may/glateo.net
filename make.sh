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

# args: file_name
replace_keywords () {
    ../../src/rpl '@head-links' '''<link rel="icon" href="pride-flag.ico">
        <link rel="stylesheet" href="../reset.css">
        <link rel="stylesheet" href="../retpagaro.css">''' $1
    ../../src/rpl '@header' '''<header>
            <h1>glateo.net</h1>
            <a href="demandoj-kaj-respondoj">Demandoj kaj Respondoj</a>
            <a href="hejmo">Hejmo</a>
            <a href="icxismo-kaj-ipismo">I&#265ismo kaj Ipismo</a>
            <a href="rimedoj">Listo de &#264iuj Rimedoj</a>
            <a href="parentismo">Parentismo</a>
            <a href="pri">Pri (ne finita)</a>
            <a href="riismo">Riismo</a>
            <a href="vortaro.php">Vortaro (ne finita)</a>
        </header>''' $1
    ../../src/rpl '@language-menu' '''<div id="language-menu">
                <a href='''"\"../eo/$1\""'''>Esperanto</a>
                <a href='''"\"../en/$1\""'''>English</a>
            </div>''' $1
    ../../src/rpl '@footer' '''<footer>
        </footer>''' $1
}

rm -rf glateo.net/

mkdir -p $source_dir/glateo.net

mkdir -p $source_dir/glateo.net/eo

mkdir -p $source_dir/glateo.net/en

cp ${glateo_files[*]} ${binary_files[*]} $source_dir/glateo.net/

cd $source_dir/eo/

cp ${html_files[*]} $source_dir/glateo.net/eo/

cd $source_dir/en/

cp ${html_files[*]} $source_dir/glateo.net/en/

cd $source_dir/glateo.net/eo

for file_name in ${html_files[@]}; do
    replace_keywords $file_name
done

cd $source_dir/glateo.net/en

for file_name in ${html_files[@]}; do
    replace_keywords $file_name
done
