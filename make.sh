#!/usr/bin/env bash
text_files=(
    '.htaccess'
    'demandoj-kaj-respondoj.php'
    'retpagaro.css'
    'icxismo-kaj-ipismo.php'
    'hejmo.php'
    'parentismo.php'
    'reset.css'
    'riismo.php'
    'rimedoj.php'
    'vortaro.php'
)
binary_files=(
    'pride-flag.ico'
)

rm -rf glateo.net/
mkdir -p glateo.net
cp ${text_files[*]} ${binary_files[*]} glateo.net/
cd glateo.net/

for file_name in ${text_files[@]}; do
    rpl @lingvo-cookie '''<?php
if (!empty($_GET['lingvo'])) {
    $_COOKIE['lingvo'] = $_GET['lingvo'];
}
setcookie('lingvo', $_COOKIE['lingvo']);
?>''' $file_name
    rpl @head-links '''<link rel="icon" href="pride-flag.ico">
        <link rel="stylesheet" href="reset.css">
        <link rel="stylesheet" href="retpagaro.css">''' $file_name
    rpl @header '''<header>
            <h1>glateo.net</h1>
            <a href="demandoj-kaj-respondoj.php">Demandoj kaj Respondoj</a>
            <a href="hejmo.php">Hejmo</a>
            <a href="icxismo-kaj-ipismo.php">I&#265ismo kaj Ipismo</a>
            <a href="rimedoj.php">Listo de &#264iuj Rimedoj</a>
            <a href="parentismo.php">Parentismo</a>
            <a href="riismo.php">Riismo</a>
            <a href="vortaro.php">Vortaro (ne finata)</a>
        </header>''' $file_name
    rpl @language-menu '''<div id="language-menu">
                <a href='''"\"$file_name?lingvo=eo\""'''>Esperanto</a>
                <a href='''"\"$file_name?lingvo=en\""'''>English</a>
            </div>''' $file_name
    rpl @footer '''<footer>
        </footer>''' $file_name
done
