<!DOCTYPE html>
@lingvo-cookie
<html>
    <head>
        @head-links
        <title>GLAT-a Esperanto</title>
    </head>
    <body>
        @header
        <article>
            <div id='content'>
                <h1>Bonvenon al GLAT-a Esperanto!</h1>
<?php
if ($_COOKIE['lingvo'] == 'en')
    echo '
<p>GLAT-a Esperanto is what I call the Esperanto dialect that many LGBT
Esperantists use. This website\'s purpose is to teach anyone interested in
Esperanto new, unofficial words that are used. If you\'re an Esperanto
speaker you could use this website to enrich your Esperanto vocabulary
and speak Esperanto neseksisme.</p>
<ul>
    <li><a href="demandoj-kaj-respondoj.php">Demandoj kaj Respondoj</a> - Questions and
    Answers for why I chose the -ismoj I did.</li>
    <li><a href="icxismo-kaj-ipismo.php">I&#265ismo kaj Ipismo</a> -
    Learn about i&#265ismo and ipismo, the gender/sex marker
    symmetry proposed to be used in Esperanto.</li>
    <li><a href="rimedoj.php">Listo de &#264iuj Rimedoj</a> - List of
    all resources used for the information on this website, and
    a few extra resources for the curious.</li>
    <li><a href="parentismo.php">Parentismo</a> - Learn about parentismo,
    a proposal to replace the roots assumed male as default with
    gender-neutral roots.</li>
    <li><a href="riismo.php">Riismo</a> - Riismo, a gender neutral
    third person singular pronoun "ri".</li>
    <li><a href="vortaro.php">Vortaro (ne finata)</a> - The dictionary of this website (not finished)</li>
</ul>';
else # ciame Esperanto estas defauxlta
    echo '
<p>GLAT-a Esperanto mi nomas la dialekton ke GLAT-aj Esperantistoj uzas. 
Cxi-tiun retpagaro povas helpi onin por lerni novajn neoficialajn vortojn. Se
 vi estas Esperantisto, vi povus uzi cxi-tiun retpagaron por helpi vin grandigi
 viajn konvortojn kaj paroli Esperanton neseksisme.</p>
<ul>
    <li><a href="demandoj-kaj-respondoj.php">Demandoj kaj Respondoj</a> - Demandoj kaj respondoj por la -ismojn mi elektas.</li>
    <li><a href="icxismo-kaj-ipismo.php">I&#265ismo kaj Ipismo</a> -
    Lernu icxismon kaj ipismon, la genraj/seksaj sufiksoj esti uzi en Esperanto.</li>
    <li><a href="rimedoj.php">Listo de &#264iuj Rimedoj</a> - Listoj de cxiuj rimedoj el
la retpagaro, kaj plu.</li>
    <li><a href="parentismo.php">Parentismo</a> - Lernu parentismon, propono por
anstatauxigi la radikojn icxajn kun genraj neuxtralaj radikoj.</li>
    <li><a href="riismo.php">Riismo</a> - Lernu riismon, genra neuxtrala tripersona 
sola pronomo, "ri".</li>
    <li><a href="vortaro.php">Vortaro (ne finata)</a> - La vortaro de la retpagaro, ne finata.</li>
</ul>';
?>
            </div>@language-menu
        </article>
        @footer
    </body>
</html>
