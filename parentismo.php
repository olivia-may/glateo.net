<!DOCTYPE html>
@lingvo-cookie
<html>
    <head>
        @head-links
        <title>Parentismo</title>
    </head>     
    <body>
        @header
        <article>
            <div id="content">
                <h1>Parentismo</h1>
<?php
if ($_COOKIE['lingvo'] == 'en')
    echo '
<p>Parentismo is the idea of replacing the assumed male as default roots in
 the Fundamento with gender-neutral roots.<p>
<p> The roots defined in
<a href="https://www.akademio-de-esperanto.org/fundamento/universala_vortaro.html">La Universala Vortaro de la Fundamento</a> 
explicity as male are:</p>
<ol>
    <li>abato - abbot</li>
    <li>avo - grandfather</li>
    <li>bubo - wicked boy</li>
    <li>edzo - husband</li>
    <li>grafo - count</li>
    <li>fian&#265o - fianc&#233</li>
    <li>filo - son </li>
    <li>frato - brother</li>
    <li>frauxlo - bachelor</li>
    <li>knabo - boy</li>
    <li>kuzo - cousin</li>
    <li>monahxo - monk</li>
    <li>nepo - grandson</li>
    <li>nevo - nephew</li>
    <li>onklo - uncle</li>
    <li>patro - father</li>
    <li>princo - prince</li>
    <li>regxo - king</li>
    <li>duko - duke</li>
    <li>sinjoro - sir, mr</li>
    <li>vidvo - widower</li>
    <li>viro - man</li>
</ol>
<p>Gender-nonspecific alternatives to these roots.
Official roots or roots made from official roots are marked with a star &#9734.</p>
<ol>
    <li>Abado - abato</li>
    <li>Avuo - avo</li>
    <li>&#9734 petolinfano - bubo</li>
    <li>esxo - edzo</li>
    <li>grofo - grafo</li>
    <li>fianceo - fian&#265o</li>
    <li>fizo - filo</li>
    <li>sahodo - frato</li>
    <li>neesxo - frauxlo</li>
    <li>kido - knabo</li>
    <li>kuzeno - kuzo</li>
    <li>monhxo - monahxo</li>
    <li>nepoto - nepo</li>
    <li>nievo - nevo</li>
    <li>ontio - onklo</li>
    <li>parento - patro</li>
    <li>prenso - princo</li>
    <li>rejgxo - regxo</li>
    <li>du&#265o - duko</li>
    <li>sioro -sinjoro</li>
    <li>viduo - vidvo</li>
    <li>&#9734 adolto / &#9734 homo - viro</li>
</ol>
<p>All other words are not defined in the Fundamento, therefore they
can be used gender-neutrally without being kontrauxfundamenta.</p>
<h2>Example sentences</h2>
<p>Without <a = href="riismo.php">riismo</a> or parentismo:</p>
<ol>
    <li>
        Li estas mia patro.<br>
        Sxi estas mia patrino.<br>
        Tiu estas mia (?)patro.<br>
    </li>
    <li>
        Mi havas tri knabojn.<br>
        Mi havas tri knabinojn.<br>
        Mi havas tri geknabojn.<br>
    </li>
</ol>
<p>With riismo and parentismo:</p>
<ol>
    <li>
        Li estas mia parento.<br>
        Sxi estas mia parento.<br>
        Ri estas mia parento.<br>
    </li>
    <li>
        Mi havas tri kidojn.<br>
    </li>
</ol>';
else
    echo '
<p>Parentismo estas ideo por anstatauxigi la icxajn radikojn en la Fundamento
 kun genro-neuxtralaj radikoj.<p>
<p> La icxaj radikoj en 
<a href="https://www.akademio-de-esperanto.org/fundamento/universala_vortaro.html">La Universala Vortaro de la Fundamento</a> 
estas:</p>
<ol>
    <li>abato</li>
    <li>avo</li>
    <li>bubo</li>
    <li>edzo</li>
    <li>grafo</li>
    <li>fian&#265o</li>
    <li>filo</li>
    <li>frato</li>
    <li>frauxlo</li>
    <li>knabo</li>
    <li>kuzo</li>
    <li>monahxo</li>
    <li>nepo</li>
    <li>nevo</li>
    <li>onklo</li>
    <li>patro</li>
    <li>princo</li>
    <li>regxo</li>
    <li>duko</li>
    <li>sinjoro</li>
    <li>vidvo</li>
    <li>viro</li>
</ol>
<p>Jen la genro-neuxtralaj radikoj.
Oficialaj radikoj aux kunvortoj havas &#9734 stelon.</p>
<ol>
    <li>Abado - abato</li>
    <li>Avuo - avo</li>
    <li>&#9734 petolinfano - bubo</li>
    <li>esxo - edzo</li>
    <li>grofo - grafo</li>
    <li>fianceo - fian&#265o</li>
    <li>fizo - filo</li>
    <li>sahodo - frato</li>
    <li>neesxo - frauxlo</li>
    <li>kido - knabo</li>
    <li>kuzeno - kuzo</li>
    <li>monhxo - monahxo</li>
    <li>nepoto - nepo</li>
    <li>nievo - nevo</li>
    <li>ontio - onklo</li>
    <li>parento - patro</li>
    <li>prenso - princo</li>
    <li>rejgxo - regxo</li>
    <li>du&#265o - duko</li>
    <li>sioro -sinjoro</li>
    <li>viduo - vidvo</li>
    <li>&#9734 adolto / &#9734 homo - viro</li>
</ol>
<p>Aliaj vortoj aux radikoj ne estas en la Fundamento, do ili povas esti uzada
nekontrauxfundamente.</p>
<h2>Ekzemple jen frazoj</h2>
<p>Sen <a = href="riismo">riismo</a> aux parentismo:</p>
<ol>
    <li>
        Li estas mia patro.<br>
        Sxi estas mia patrino.<br>
        Tiu estas mia (?)patro.<br>
    </li>
    <li>
        Mi havas tri knabojn.<br>
        Mi havas tri knabinojn.<br>
        Mi havas tri geknabojn.<br>
    </li>
</ol>
<p>Kun riismo kaj parentismo:</p>
<ol>
    <li>
        Li estas mia parento.<br>
        Sxi estas mia parento.<br>
        Ri estas mia parento.<br>
    </li>
    <li>
        Mi havas tri kidojn.<br>
    </li>
</ol>';
?>
            </div>@language-menu
        </article>
        @footer
    </body>
</html>
