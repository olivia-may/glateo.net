<!DOCTYPE html>
@lingvo-cookie
<html>
    <head>
        @head-links
        <title>Demandoj kaj Respondoj</title>
    </head>
    <body>
        @header
        <article>
            <div id="content">
<?php
if ($_COOKIE['lingvo'] == 'en')
    echo '
<h1>Questions and Answers</h1>
<ul>
    <li><h2>Q. Why parentismo and not j-sistemo or something else?</h2>
    <p>A. The creator of j-sistemo, Markos Kramer, <a href="https://web.archive.org/web/20210211083523/https://lingvakritiko.com/2021/01/06/seksneutralaj-parencovortoj-rezultoj-de-opinisondo/">
    has stopped using it.</a> They use other systems. And 
    (Transir-faciliga) parentismo is comparatively well known 
    enough and would be easy for older Esperantists to pick up.</p></li>
    <li><h2>Q. Why riismo and not &#285iismo?</h2>
    <p>A. Ri is more popular as a general use pronoun. And with 
    &#285iismo it is sometimes difficult to know if one is 
    refering to an object or a person. Many LGBT Esperantists
    prefer riismo.</p>
</ul>';
else
    echo '
<h1>Demandoj kaj Respondoj</h1>
<ul>
    <li><h2>D. Kial parentismo kaj nek j-sistemo nek alia?</h2>
    <p>R. La kreinto de j-sistemo, Markos Kramer, <a href="https://web.archive.org/web/20210211083523/https://lingvakritiko.com/2021/01/06/seksneutralaj-parencovortoj-rezultoj-de-opinisondo/">
    forlasis gxin.</a> Ri uzas aliajn sistemojn. 
    (Transir-faciliga) parentismo estas pli konata ol aliaj
    kaj facilus por learnataj Esperantistoj por lerni</p></li>
    <li><h2>D. Kial riismo kaj ne &#285iismo?</h2>
    <p>R. Riismaj homoj estas pli multaj. Kun &#285iismo iame estas
    malfacila scii ke oni babilas pri objecto aux homo. 
    Riismo estas preferata laux GLAT-aj Esperantistoj.</p>
</ul>';
?>
            </div>@language-menu
        </article>
        @footer
    </body>
</html>
