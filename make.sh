#!/usr/bin/env bash

glateo_files=(
    '.htaccess'
    'pride-flag.ico'
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

source_dir=$(pwd)

rm -rf glateo.net/
mkdir -p $source_dir/glateo.net
mkdir -p $source_dir/glateo.net/eo
mkdir -p $source_dir/glateo.net/en

cp ${glateo_files[*]} $source_dir/glateo.net/
cd $source_dir/eo/
cp ${html_files[*]} $source_dir/glateo.net/eo/
cd $source_dir/en/
cp ${html_files[*]} $source_dir/glateo.net/en/

# for all languages of the site
function replace_keywords() {

    ../../src/rpl '@head-content' '''<meta charset="UTF-8">
        <link rel="icon" href="../pride-flag.ico">
        <link rel="stylesheet" href="../reset.css">
        <link rel="stylesheet" href="../retpagaro.css">''' $1

    ../../src/rpl '@language-menu' '''<div id="language-menu">
                <a href='''"\"../eo/$1\""'''>Esperanto</a>
                <a href='''"\"../en/$1\""'''>English</a>
            </div>''' $1
            
    ../../src/rpl '@resources' '''<ul>
                <li><a href="https://tersiso.net/">
                TerSISO</a></li>
                <li><a href="https://lingvakritiko.com/2019/11/11/survoje-al-sekse-neutralaj-kaj-egalecaj-esprimoj-komparo-inter-la-j-sistemo-kaj-parentismo/">
                Parentismo de Markos Kramer de lingvakritiko.com</a></li>
                <li><a href="https://www.cyrilbrosch.net/bd/ghi-parentismo">
                Parentismo de Cyril Brosch de cyrilbrosch.net</a></li>
                <li><a href="https://www.akademio-de-esperanto.org/fundamento/universala_vortaro.html">
                La Universala Vortaro de la Fundamento</a></li>
                <li><a href="http://www.pvv.org/~ulflunde/Eo/icxismo.html">
                Iĉismo de Ulf Lunde de pvv.org</a></li>
                <li><a href="https://web.archive.org/web/20060924123828/http://www.rano.org/riismo2.html">
                Riisma Manifesto</a></li>
                <li><a href="https://lingvakritiko.com/2014/10/16/esperanto-kaj-sekso/">
                Esperanto kaj sekso de Markos Kramer de Lingva Kritiko</a></li>
                <li><a href="https://web.archive.org/web/20210211083523/https://lingvakritiko.com/2021/01/06/seksneutralaj-parencovortoj-rezultoj-de-opinisondo/">
                Seksneutralaj parencovortoj - rezultoj de opinisondo de 
                Markos Kramer de Lingva Kritiko</a></li>
            </ul>''' $1

    ../../src/rpl '@extra-resources' '''<ul>
                    <li><a href="https://www.youtube.com/watch?v=ZyxDjiT3lfw">Ri Liberas</a></li>
                </ul>''' $1

    ../../src/rpl '@parentismo-roots' '''<ol>
                    <li>abado - abato</li>
                    <li>avuo - avo</li>
                    <li>☆ petolinfano - bubo</li>
                    <li>eŝo - edzo</li>
                    <li>grofo - grafo</li>
                    <li>fianceo - fianĉo</li>
                    <li>fizo - filo</li>
                    <li>sahodo - frato</li>
                    <li>neeŝo - fraŭlo</li>
                    <li>kido - knabo</li>
                    <li>kuzeno - kuzo</li>
                    <li>monĥo - monaĥo</li>
                    <li>nepoto - nepo</li>
                    <li>nievo - nevo</li>
                    <li>ontio - onklo</li>
                    <li>parento - patro</li>
                    <li>prenso - princo</li>
                    <li>rejĝo - reĝo</li>
                    <li>duĉo - duko</li>
                    <li>sioro -sinjoro</li>
                    <li>viduo - vidvo</li>
                    <li>☆ adolto, ☆ plenkreskulo, ☆ homo - viro</li>
                </ol>''' $1

    ../../src/rpl '@parentismo-patrismo-example' '''<ol>
                    <li>
                        Li estas mia patro.<br>
                        Ŝi estas mia patrino.<br>
                        Tiu estas mia (?)patro.<br>
                    </li>
                    <li>
                        Mi havas tri knabojn.<br>
                        Mi havas tri knabinojn.<br>
                        Mi havas tri geknabojn.<br>
                    </li>
                    <li>
                        Unu kuzo kaj unu kuzino estas du gekuzoj.
                    </li>
                </ol>''' $1

    ../../src/rpl '@parentismo-example' '''<ol>
                    <li>
                        Li estas mia parento.<br>
                        Ŝi estas mia parento.<br>
                        Ri estas mia parento.<br>
                    </li>
                    <li>
                        Mi havas tri kidojn.<br>
                    </li>
                    <li>
                        Unu kuzeniĉo kaj unu kuzenino estas du gekuzenoj kaj du kuzenoj.
                    </li>
                </ol>''' $1
    
    ../../src/rpl '@riismo-example' '''<ul>
                    <li>Mi ne konas la genron de tiu homo, do mi uzas la pronomon
                    "ri" por ri.</li>
                    <li>Ri estas neduumulo, ri uzas la pronomon "ri".</li>
                    <li>Se vi vidus homon, diru saluton al ri.</li>
                    <li>Ri estas mia patro kaj ri estas mia patrino.</li>
                    <li>Riaj kukoj estas bongustaj.</li>
                    <li>Ĉu vi vidas rin?</li>
                    <li>Mi vidas riajn katojn kaj hundojn.</li>
                    <li>Vi vidas rian domon.</li>
                </ul>''' $1
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
