#define DICTIONARY_LEN 46
#define EN_TO_EO_LEN 8

// for 2 dimensional array `dictionary`
enum {
    EO1 = 0,
    EO2,
    EN,
};

// for "x_to_y" arrays
enum {
    FROM = 0,
    TO,
};

// pascal (length cached) strings
typedef char psc1b_str;

typedef struct {
    unsigned int len;
    char str[];
} psc4b_str;

// when adding new words, type \p before the string, ex: "\pHello World!",
// then run `pscv/pscv vortaro.h`.
// also run when changing an existing word's length

// organized by unicode order (alphabetically except for special chars)
const psc1b_str *dictionary[DICTIONARY_LEN][3] = {

    {"\005abado",           "\011(abad·o)",         "\026(gender-neutral) abbot"},
    {"\010adoltino",        "\016(adolt·in·o)",     "\005woman"},
    {"\011adoltiĉo",        "\017(adolt·iĉ·o)",     "\003man"},
    {"\006adolto",          "\012(adolt·o)",        "\005adult"},
    {"\004avuo",            "\010(avu·o)",          "\013grandparent"},
    {"\005duĉo",            "\011(duĉ·o)",          "\025(gender neutral) duke"},
    {"\004eŝo",             "\010(eŝ·o)",           "\006spouse"},
    {"\006femino",          "\012(femin·o)",        "\005woman"},
    {"\007fianceo",         "\013(fiance·o)",       "\030(gender neutral) fiancé"},
    {"\004filo",            "\010(fil·o)",          "\033child, (gender neutral) son"},
    {"\005grofo",           "\011(grof·o)",         "\015(title) count"},
    {"\006homino",          "\014(hom·in·o)",       "\005woman"},
    {"\007homiĉo",          "\015(hom·iĉ·o)",       "\003man"},
    {"\004homo",            "\010(hom·o)",          "\006person"},
    {"\003ina",             "\007(in·a)",           "\006female"},
    {"\003ine",             "\007(in·e)",           "\006female"},
    {"\003ino",             "\007(in·o)",           "\005woman"},
    {"\004iĉa",             "\010(iĉ·a)",           "\004male"},
    {"\004iĉe",             "\010(iĉ·e)",           "\004male"},
    {"\004iĉo",             "\010(iĉ·o)",           "\003man"},
    {"\003ipa",             "\007(ip·a)",           "\011nonbinary"},
    {"\003ipe",             "\007(ip·e)",           "\011nonbinary"},
    {"\003ipo",             "\007(ip·o)",           "\020nonbinary person"},
    {"\004kido",            "\010(kid·o)",          "\003kid"},
    {"\006kuzeno",          "\012(kuzen·o)",        "\006cousin"},
    {"\006monĥo",           "\012(monĥ·o)",         "\025(gender neutral) monk"},
    {"\006neeŝo",           "\014(ne·eŝ·o)",        "\020unmarried person"},
    {"\006nepoto",          "\012(nepot·o)",        "\012grandchild"},
    {"\005nievo",           "\011(niev·o)",         "\040nibling, (gender neutral) nephew"},
    {"\005ontio",           "\011(onti·o)",         "\026(gender neutral) uncle"},
    {"\007parento",         "\013(parent·o)",       "\006parent"},
    {"\013petolinfano",     "\021(petol·infan·o)",  "\014wicked child"},
    {"\011personino",       "\017(person·in·o)",    "\005woman"},
    {"\012personiĉo",       "\020(person·iĉ·o)",    "\003man"},
    {"\007persono",         "\013(person·o)",       "\006person"},
    {"\016plenkreskulino",  "\030(plen·kresk·ul·in·o)", "\005woman"},
    {"\017plenkreskuliĉo",  "\031(plen·kresk·ul·iĉ·o)", "\003man"},
    {"\014plenkreskulo",    "\024(plen·kresk·ul·o)", "\005adult"},
    {"\006prenso",          "\012(prens·o)",        "\027(gender neutral) prince"},
    {"\006rejĝo",           "\012(rejĝ·o)",         "\035regent, (gender neutral) king"},
    {"\002ri",              "\004(ri)",             "\044(singular) they, (gender neutral) he"},
    {"\006sahodo",          "\012(sahod·o)",        "\007sibling"},
    {"\007saluton",         "\012(salut·o)",        "\005hello"},
    {"\005sioro",           "\011(sior·o)",         "\054(gender neutral) sir, (gender neutral) ma'am"},
    {"\005viduo",           "\011(vidv·o)",         "\026(gender neutral) widow"},
    {"\004viro",            "\010(vir·o)",          "\003man"},
};

// unicode order
const psc1b_str *en_to_eo[EN_TO_EO_LEN][2] = {

    {"\002he",              "\006ri, li"},
    {"\005hello",           "\007saluton"},
    {"\002hi",              "\007saluton"},
    {"\003man",             "\075(adult) adoltiĉo, plenkreskuliĉo, viro; homiĉo, personiĉo"},
    {"\006person",          "\015homo, persono"},
    {"\003she",             "\007ri, ŝi"},
    {"\004they",            "\033(singular) ri; (plural) ili"},
    {"\005woman",           "\073(adult) adoltino, plenkreskulino, femino; homino, personino"},
};

// convert cx or ch, in `input_word`, to ĉ, etc.
void convert_to_proper_esperanto(char *input_word);

// search from Esperanto to `to_language`, English, etc.
psc4b_str *search_dictionary_eo(const int to_language,
    const char *input_word);

// search from English, etc., to Esperanto
psc4b_str *search_dictionary(const char *wl[][2], const int wordlist_len,
    const char *input_word);
