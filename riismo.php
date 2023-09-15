<!DOCTYPE html>
@lingvo-cookie
<html>
    <head>
        @head-links
        <title>Riismo</title>
    </head>
    <body>
        @header
        <article>
            <div id="content">
                <h1>Riismo</h1>
<?php
if ($_COOKIE['lingvo'] == 'en')
    echo '
<p>Riismo is the idea of using the gender-nonspecific, third person
singular pronoun "Ri". You can use it to not have to assume 
someone\'s gender, address someone that doesn\'t want to be referred
to by a gendered pronoun, when you don\'t know the gender of someone,
or if you just don\'t like using gendered pronouns.</p>
<p>Ri is used more with younger and LGBT Esperantists. It is
becoming more recognized and more accepted as a pronoun.</p>
<h2>Example sentences</h2>
<ul>
    <li>Mi ne konas la genron de tiu homo, do mi uzas la pronomon
    "ri" por ri.</li>
    <li>Ri estas neduumulo, ri uzas la pronomon "ri".</li>
    <li>Se vi vidus homon, diru saluton al ri.</li>
    <li>Ri estas mia patro kaj ri estas mia patrino.</li>
    <li>Riaj kukoj estas bongustaj.</li>
    <li>Cxu vi vidas rin?</li>
    <li>Mi vidas riajn katojn kaj hundojn.</li>
    <li>Vi vidas rian domon.</li>
</ul>';
else
    echo '
<p>Riismo estas ideo por neprecizogenra tripersona
unuopa pronomo "Ri". Oni povas uzi gxin por ne devus supozi genron de iu.
 Por mencii iun, kiu ne volas sian genron esti supozata. Kiam oni ne konas
 ies genron. Ecx se vi ne sxatas uzi genratajn pronomojn</p>
<p>Plej da junaj GLAT-aj Esperantisoj uzas la pronomon ri. Gxi estas
plej konigxi kaj akceptigxi.</p>
<h2>Exzemplaj Frazoj</h2>
<ul>
    <li>Mi ne konas la genron de tiu homo, do mi uzas la pronomon
    "ri" por ri.</li>
    <li>Ri estas neduumulo, ri uzas la pronomon "ri".</li>
    <li>Se vi vidus homon, diru saluton al ri.</li>
    <li>Ri estas mia patro kaj ri estas mia patrino.</li>
    <li>Riaj kukoj estas bongustaj.</li>
    <li>Cxu vi vidas rin?</li>
    <li>Mi vidas riajn katojn kaj hundojn.</li>
    <li>Vi vidas rian domon.</li>
</ul>';
?>
            </div>@language-menu
        </article>
        @footer
    </body>
</html>
