<!DOCTYPE html>
@lingvo-cookie
<html>
    <head>
        @head-links
        <title>Pri &#265i-tiu retpagaro</title>
    </head>     
    <body>
        @header
        <article>
            <div id="content">
<?php
if ($_COOKIE['lingvo'] == 'en')
    echo '
<h1>About This Website</h1>
<p>I made this website because I want Esperanto to be more inclusive.
I keep noticing there\'s not many women in the Esperanto community (at least
around me) and there is some bigotry in the general community. My hope is
this website will make the international language more inclusive and
accepting, and if there are people turning away from Esperanto because of
its perceived sexism, my hope is they will feel better after visiting this website.</p>
<h2>Cookies</h2>
<p>This website stores a cookie on your computer in order to remember which
language you chose to read the website in. Thats it, no other use of 
cookies.</p>
<h2>Thank you for visiting!</h2>';
else
    echo '
<h1>Pri cxi tiu retpagaro</h1>
<p>Mi faris cxi tiun retpagaron cxar mi volas Esperanton esti pli bonvene.
Mi rimarkis ke ne estas multaj hominoj en la Esperanta komunumo (almenaux ne
cxirkaux mi) kaj estas malameco en iuj partoj de la komunumo. Mia espero estas
ke tiu retpagaro plibonigus kaj pliakceptigus la internacian lingvonwill. Se estas
homoj, kiu foriris Esperanton cxar gxia kerimarkata seksismo, mia espero estas
ke ili fartos pli bone, post la vido de tiu retpagaro.</p>
<h2>Kuketoj</h2>
<p>Tiu retpagaro metas kuketon al via komputilo por scii kiun lingvon ke vi
volas legi la retpagaron. Estas tuta, ne alia uzo de kuketoj.</p>
<h2>Mi dankas vin por visiti!</h2>
';
?>
            </div>@language-menu
        </article>
        @footer
    </body>
</html>
