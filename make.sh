#!/usr/bin/env sh
text_files='''
    .htaccess
    demandoj-kaj-respondoj
    glateo.css
    icxismo-kaj-ipismo
    hejmo
    parentismo
    reset.css
    riismo
    rimedoj
'''
binary_files='''
    pride-flag.ico
'''

rm -rf glateo.net/
mkdir -p glateo.net
cp $text_files $binary_files glateo.net/
cd glateo.net/

rpl @head-links '''<link rel="icon" href="pride-flag.ico">
        <link rel="stylesheet" href="reset.css">
        <link rel="stylesheet" href="glateo.css">''' $text_files
rpl @header '''<header>
            <h1>glateo.net</h1>
            <a href="demandoj-kaj-respondoj">Demandoj kaj Respondoj</a>
            <a href="hejmo">Hejmo</a>
            <a href="icxismo-kaj-ipismo">I&#265ismo kaj Ipismo</a>
            <a href="rimedoj">Listo de &#264iuj Rimedoj</a>
            <a href="parentismo">Parentismo</a>
            <a href="riismo">Riismo</a>
        </header>''' $text_files
rpl @footer '''<footer>
        </footer>''' $text_files
