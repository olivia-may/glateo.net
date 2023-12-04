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

// organized by unicode order (alphabetically except for special chars)
const char *dictionary[DICTIONARY_LEN][3] = {

    {"abado",           "(abad·o)",         "(gender-neutral) abbot"},
    {"adoltino",        "(adolt·in·o)",     "woman"},
    {"adoltiĉo",        "(adolt·iĉ·o)",     "man"},
    {"adolto",          "(adolt·o)",        "adult"},
    {"avuo",            "(avu·o)",          "grandparent"},
    {"duĉo",            "(duĉ·o)",          "(gender neutral) duke"},
    {"eŝo",             "(eŝ·o)",           "spouse"},
    {"femino",          "(femin·o)",        "woman"},
    {"fianceo",         "(fiance·o)",       "(gender neutral) fiancé"},
    {"filo",            "(fil·o)",          "child, (gender neutral) son"},
    {"grofo",           "(grof·o)",         "(title) count"},
    {"homino",          "(hom·in·o)",       "woman"},
    {"homiĉo",          "(hom·iĉ·o)",       "man"},
    {"homo",            "(hom·o)",          "person"},
    {"ina",             "(in·a)",           "female"},
    {"ine",             "(in·e)",           "female"},
    {"ino",             "(in·o)",           "woman"},
    {"iĉa",             "(iĉ·a)",           "male"},
    {"iĉe",             "(iĉ·e)",           "male"},
    {"iĉo",             "(iĉ·o)",           "man"},
    {"ipa",             "(ip·a)",           "nonbinary"},
    {"ipe",             "(ip·e)",           "nonbinary"},
    {"ipo",             "(ip·o)",           "nonbinary person"},
    {"kido",            "(kid·o)",          "kid"},
    {"kuzeno",          "(kuzen·o)",        "cousin"},
    {"monĥo",           "(monĥ·o)",         "(gender neutral) monk"},
    {"neeŝo",           "(ne·eŝ·o)",        "unmarried person"},
    {"nepoto",          "(nepot·o)",        "grandchild"},
    {"nievo",           "(niev·o)",         "nibling, (gender neutral) nephew"},
    {"ontio",           "(onti·o)",         "(gender neutral) uncle"},
    {"parento",         "(parent·o)",       "parent"},
    {"petolinfano",     "(petol·infan·o)",  "wicked child"},
    {"personino",       "(person·in·o)",    "woman"},
    {"personiĉo",       "(person·iĉ·o)",    "man"},
    {"persono",         "(person·o)",       "person"},
    {"plenkreskulino",  "(plen·kresk·ul·in·o)", "woman"},
    {"plenkreskuliĉo",  "(plen·kresk·ul·iĉ·o)", "man"},
    {"plenkreskulo",    "(plen·kresk·ul·o)", "adult"},
    {"prenso",          "(prens·o)",        "(gender neutral) prince"},
    {"rejĝo",           "(rejĝ·o)",         "regent, (gender neutral) king"},
    {"ri",              "(ri)",             "(singular) they, (gender neutral) he"},
    {"sahodo",          "(sahod·o)",        "sibling"},
    {"saluton",         "(salut·o)",        "hello"},
    {"sioro",           "(sior·o)",         "(gender neutral) sir, (gender neutral) ma'am"},
    {"viduo",           "(vidv·o)",         "(gender neutral) widow"},
    {"viro",            "(vir·o)",          "man"},
};

// unicode order
const char *en_to_eo[EN_TO_EO_LEN][2] = {

    {"he",              "ri, li"},
    {"hello",           "saluton"},
    {"hi",              "saluton"},
    {"man",             "(adult) adoltiĉo, plenkreskuliĉo, viro; homiĉo, personiĉo"},
    {"person",          "homo, persono"},
    {"she",             "ri, ŝi"},
    {"they",            "(singular) ri; (plural) ili"},
    {"woman",           "(adult) adoltino, plenkreskulino, femino; homino, personino"},
};

// convert cx or ch, in `input_word`, to ĉ, etc.
void convert_to_proper_esperanto(char *input_word);

// search from Esperanto to `to_language`, English, etc.
char *search_dictionary_eo(const int to_language,
    const char *input_word);

// search from English, etc., to Esperanto
char *search_dictionary(const char *wl[][2], const int wordlist_len,
    const char *input_word);
