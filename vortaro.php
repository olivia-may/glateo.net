<!DOCTYPE html>
<html>
    <head>
        @head-links
        <title>Vortaro</title>
    <body>
        @header
        <article>
<?php 
$transllang = $_POST['translate-language'];
?>
            <form action="vortaro.php" method="post">
                <select name="translate-language">
                    <option value="en -> eo" <?php if (strcmp($transllang, 'en -> eo') == 0) echo 'selected="selected"';?>>English -> Esperanto</option>
                    <option value="eo -> en" <?php if (strcmp($transllang, 'eo -> en') == 0) echo 'selected="selected"';?>>Esperanto -> English</option>
                </select>
                <br>
                <input name="word" id="word" type="text">
                <button type="submit">Translate</button>
            </form>
<?php
$word = strtolower(htmlspecialchars($_POST['word']));
$translword = "\0";

if (strcmp($transllang, 'en -> eo') == 0) {
    if (strcmp($word, "hi") == 0 || strcmp($word, "hello") == 0)
        $translword = 'saluton, sal';
    else if (strcmp($word, "person") == 0)
        $translword = 'homo, persono';
    else if (strcmp($word, "woman") == 0)
        $translword = 'adoltino, plenkreskulino (adult woman); homino, personino; virino';
    else if (strcmp($word, "man") == 0)
        $translword = 'adolti&#265o, plenkreskuli&#265o (adult man); homi&#265o, personi&#265o; viro';
    else if (strcmp($word, "non binary") == 0 || strcmp($word, "non-binary") == 0
        || strcmp($word, "nonbinary") == 0 || strcmp($word, 
        "non binary person") == 0 || strcmp($word, "non-binary person") == 0
        || strcmp($word, "nonbinary person") == 0)
        $translword = 'neduuma, ipa; adoltipo, plenkreskulipo (adult); homipo, personipo';
}
if (strcmp($transllang, 'eo -> en') == 0) {
    if (strcmp($word, "saluton") == 0 || strcmp($word, "sal") == 0)
        $translword = 'hi, hello';
    else if (strcmp($word, "homo") == 0 || strcmp($word, "persono") == 0)
        $translword = 'person';
    else if (strcmp($word, "adoltino") == 0 || strcmp($word, 
        "plenkreskulino") == 0 || strcmp($word, 'virino') == 0)
        $translword = 'woman';
    else if (strcmp($word, "homino") == 0 || strcmp($word, 'personino') == 0)
        $translword = 'woman/girl';
}

if (strcmp($translword, "\0") == 0)
    echo "Word not found, try another word";
else
    echo "<p>$word</p><p>&emsp;$translword</p>";
?>
        </article>
    </body>
</html>
