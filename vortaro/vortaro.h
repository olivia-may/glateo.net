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

    {"\005abado",           "\007abad·o",       "\026(gender-neutral) abbot"},
    {"\010adoltino",        "\014adolt·in·o",   "\005woman"},
    {"\011adoltiĉo",        "\015adolt·iĉ·o",   "\003man"},
    {"\006adolto",          "\010adolt·o",      "\005adult"},
    {"\004avuo",            "\006avu·o",        "\013grandparent"},
    {"\005duĉo",            "\007duĉ·o",        "\025(gender neutral) duke"},
    {"\004eŝo",             "\006eŝ·o",         "\006spouse"},
    {"\006femino",          "\010femin·o",      "\005woman"},
    {"\007fianceo",         "\011fiance·o",     "\030(gender neutral) fiancé"},
    {"\004filo",            "\006fil·o",        "\033child, (gender neutral) son"},
    {"\005grofo",           "\007grof·o",       "\015(title) count"},
    {"\006homino",          "\012hom·in·o",     "\005woman"},
    {"\007homiĉo",          "\013hom·iĉ·o",     "\003man"},
    {"\004homo",            "\006hom·o",        "\006person"},
    {"\003ina",             "\005in·a",         "\006female"},
    {"\003ine",             "\005in·e",         "\006female"},
    {"\003ino",             "\005in·o",         "\005woman"},
    {"\004iĉa",             "\006iĉ·a",         "\004male"},
    {"\004iĉe",             "\006iĉ·e",         "\004male"},
    {"\004iĉo",             "\006iĉ·o",         "\003man"},
    {"\003ipa",             "\005ip·a",         "\011nonbinary"},
    {"\003ipe",             "\005ip·e",         "\011nonbinary"},
    {"\003ipo",             "\005ip·o",         "\020nonbinary person"},
    {"\004kido",            "\006kid·o",        "\003kid"},
    {"\006kuzeno",          "\010kuzen·o",      "\006cousin"},
    {"\006monĥo",           "\010monĥ·o",       "\025(gender neutral) monk"},
    {"\006neeŝo",           "\012ne·eŝ·o",      "\020unmarried person"},
    {"\006nepoto",          "\010nepot·o",      "\012grandchild"},
    {"\005nievo",           "\007niev·o",       "\040nibling, (gender neutral) nephew"},
    {"\005ontio",           "\007onti·o",       "\026(gender neutral) uncle"},
    {"\007parento",         "\011parent·o",     "\006parent"},
    {"\013petolinfano",     "\017petol·infan·o","\014wicked child"},
    {"\011personino",       "\015person·in·o",  "\005woman"},
    {"\012personiĉo",       "\016person·iĉ·o",  "\003man"},
    {"\007persono",         "\011person·o",     "\006person"},
    {"\016plenkreskulino",  "\026plen·kresk·ul·in·o", "\005woman"},
    {"\017plenkreskuliĉo",  "\027plen·kresk·ul·iĉ·o", "\003man"},
    {"\014plenkreskulo",    "\022plen·kresk·ul·o", "\005adult"},
    {"\006prenso",          "\010prens·o",      "\027(gender neutral) prince"},
    {"\006rejĝo",           "\010rejĝ·o",       "\035regent, (gender neutral) king"},
    {"\002ri",              "\002ri",           "\044(singular) they, (gender neutral) he"},
    {"\006sahodo",          "\010sahod·o",      "\007sibling"},
    {"\007saluton",         "\010salut·o",      "\005hello"},
    {"\005sioro",           "\007sior·o",       "\054(gender neutral) sir, (gender neutral) ma'am"},
    {"\005viduo",           "\007vidv·o",       "\026(gender neutral) widow"},
    {"\004viro",            "\006vir·o",        "\003man"},
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
