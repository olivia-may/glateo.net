<!DOCTYPE html>
@lingvo-cookie
<html>
    <head>
        @head-links
        <title>I&#265ismo kaj Ipismo</title>
    </head>
    <body>
        @header
        <article>
            <div id="content">
                <h1>I&#265ismo kaj Ipismo</h1>
<?php
if ($_COOKIE['lingvo'] == 'en')
    echo '
<p>I&#265ismo and Ipismo are the concepts of using gender/sex
markers for more than just female.
<h2>I&#265ismo</h2>
<p>I&#265ismo is the idea of using the male gender/sex marker -i&#265-. It is 
the opposite of the official female gender/sex marker -in-. It can be used on 
words that are already gender non-specific. Under this system, most nouns
that can have a gender are assumed to be gender-nonspecific, instead of 
assumed male as default. Some nouns are still assumed to be male by default
(viro, avo, patro). You could still add the suffix to these roots if you 
wanted, but it wouldn\'t change the meaning of the whole word. </p>
<h2>Ipismo</h2>
<p>The gender marker -ip- is for non-binary people (neduumuloj), people
who are neither male nor female. It is only used on humans.
<h2>Example words</h2>
<ul>
    <li>
        Amiko(j) (unspecified gender friend(s))<br>
        Amikino(j) (female friend(s))<br>
        Amiki&#265o(j) (male friend(s))<br>
        Amikipo(j) (non-binary friend(s))<br>
    </li>
    <li>
        Esperantisto(j) (unspecified gender Esperantist(s))<br>
        Esperantistino(j) (female Esperantist(s))<br>
        Esperantisti&#265o(j) (male Esperantist(s))<br>
        Esperantistipo(j) (non-binary Esperantist(s))<br>
    </li>
    <li>
        Homo(j) (person(people))<br>
        Homino(j) (woman(women))<br>
        Homi&#265o(j) (man(men))<br>
        Homipo(j) (non-binary person(people))<br>
    <li>
        Kato(j) (cat(s))<br>
        Katino(j) (momcat(s))<br>
        Kati&#265o(j) (tomcat(s))<br>
    </li>
    <li>
        Koko(j) (chicken(s))<br>
        Kokino(j) (hen(s)<br>
        Koki&#265o(j) (rooster(s))<br>
    </li>
    <li>
        Koramiko(j) (significant-other(s)/partner(s))<br>
        Koramikino(j) (girlfriend(s))<br>
        Koramiki&#265o(j) (boyfriend(s))<br>
        Koramikipo(j) (non-binary significant-other(s)/partners(s))<br>
    </li>
</ul>';
else
    echo '
<p>I&#265ismo kaj Ipismo estas konceptoj pri uzi genrajn/seksajn markilojn
 por viraj kaj neduumaj homoj.
<h2>I&#265ismo</h2>
<p>-I&#265- estas la vira genra/seksa markilo. Estas
kiel mala -in-. Oni povas uzi gxin por genro-neuxtralaj vortoj. 
Pro tiu sistemo, plej vortradikoj, kiu povas havi genron vivan,
alprenas genro-neuxtralecon, anstataux virecon. Iom da radikoj
ankoraux alprenas vira, ekz viro, avo, patro. Oni povus uzi 
-i&#265- por &#265i tiujn vortojn, sed ili havus la saman signifon.
<h2>Ipismo</h2>
<p>-Ip- estas markilo por neduumuloj, homoj kiu ne estas
i&#265aj aux inaj. Nur uzu gxin por homoj, &#265ar oni ne povas
demandi al bestoj se gxi estas neduuma.
<h2>Ekzemplaj vortoj</h2>
<ul>
    <li>
        Amiko(j) (nepreciza(j) genro(j))<br>
        Amikino(j)<br>
        Amiki&#265o(j) (vira(j) homo(j))<br>
        Amikipo(j) (neduuma(j))<br>
    </li>
    <li>
        Esperantisto(j) (nepreciza(j) genro(j))<br>
        Esperantistino(j)<br>
        Esperantisti&#265o(j) (vira(j) homo(j))<br>
        Esperantistipo(j) (neduuma(j))<br>
    </li>
    <li>
        Homo(j) (nepreciza(j) genro(j))<br>
        Homino(j)<br>
        Homi&#265o(j) (vira(j) homo(j))<br>
        Homipo(j) (neduuma(j))<br>
    <li>
        Kato(j) (nepreciza(j) sekso(j))<br>
        Katino(j)<br>
        Kati&#265o(j) (vira(j) sekso(j))<br>
    </li>
    <li>
        Koko(j) (nepreciza(j) sekso(j))<br>
        Kokino(j)<br>
        Koki&#265o(j) (vira(j) sekso(j))<br>
    </li>
    <li>
        Koramiko(j) (nepreciza(j) genro(j))<br>
        Koramikino(j)<br>
        Koramiki&#265o(j) (vira(j) homo(j))<br>
        Koramikipo(j) (neduuma(j))<br>
    </li>
</ul>';
?>
            </div>@language-menu
        </article>
        @footer
    </body>
</html>
