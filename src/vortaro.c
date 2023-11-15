#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DICTIONARY_LEN 46
#define EN_TO_EO_LEN 8

enum {
    EO1 = 0,
    EO2,
    EN,
};

enum {
    FROM = 0,
    TO,
};

// organized by unicode order (alphabetically except for special chars,
// first byte, then second byte)
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

void convert_to_proper_esperanto(char *input_word) {
    bool is_x_or_h;

    for (int i = 0; i < strlen(input_word) - 1; i++) {
        
        is_x_or_h = input_word[i + 1] == 'x' || input_word[i + 1] == 'h';
        
        if (input_word[i] == 'c' && is_x_or_h) {
            
            input_word[i] = 196;
            i++;
            input_word[i] = 137;
        }
        if (input_word[i] == 'g' && is_x_or_h) {
            
            input_word[i] = 196;
            i++;
            input_word[i] = 157;
        }
        if (input_word[i] == 'h' && is_x_or_h) {
            
            input_word[i] = 196;
            i++;
            input_word[i] = 165;
        }
        if (input_word[i] == 'j' && is_x_or_h) {
            
            input_word[i] = 196;
            i++;
            input_word[i] = 181;
        }
        if (input_word[i] == 's' && is_x_or_h) {
            
            input_word[i] = 197;
            i++;
            input_word[i] = 157;
        }
        if (input_word[i] == 'u' && is_x_or_h) {
            
            input_word[i] = 197;
            i++;
            input_word[i] = 173;
        }
    }
}

void search_dictionary_eo(const int language,
    const char *input_word) {

    int i, j;
    char *definition;
    int definition_len, eo2_len, language_len;

    definition = malloc(sizeof(char));
    definition[0] = '\0';

    for (i = 0; i < DICTIONARY_LEN; i++) {

        for (j = 0; j < strlen(input_word); j++) {
            
            if (dictionary[i][EO1][j] == '\0') break;        
            if (input_word[j] != dictionary[i][EO1][j]) break;        
            if (j == strlen(input_word) - 1) {
            
                definition_len = strlen(definition);
                eo2_len = strlen(dictionary[i][EO2]);
                language_len = strlen(dictionary[i][language]);

                definition =
                    realloc(definition, 
                    (definition_len + eo2_len + language_len + 4)
                    * sizeof(char));
                
                strcpy(&definition[definition_len], dictionary[i][EO2]);
                strcpy(&definition[definition_len + eo2_len], "\n  ");
                strcpy(&definition[definition_len + eo2_len + 3],
                    dictionary[i][language]);
                strcpy(&definition[definition_len + eo2_len + language_len + 3],
                    "\n");
            }
        }
    }

    if (definition[0] == '\0')
        printf("Word not found, \"%s\", try another word\n", input_word);
    else
        printf("%s", definition);

    free(definition);
}

void search_dictionary(const char *wl[][2], const int wordlist_len,
    const char *input_word) {

    int i, j;
    char *definition;
    int definition_len, from_len, to_len;

    definition = malloc(sizeof(char));
    definition[0] = '\0';

    for (i = 0; i < wordlist_len; i++) {

        for (j = 0; j < strlen(input_word); j++) {
            
            if (input_word[j] != wl[i][FROM][j]) break;
            
            if (j == strlen(input_word) - 1) {
            
                definition_len = strlen(definition);
                from_len = strlen(wl[i][FROM]);
                to_len = strlen(wl[i][TO]);
                
                definition =
                    realloc(definition, 
                    (definition_len + from_len + to_len + 4)
                    * sizeof(char));
                
                strcpy(&definition[definition_len], wl[i][FROM]);
                strcpy(&definition[definition_len + from_len], "\n  ");
                strcpy(&definition[definition_len + from_len + 3], wl[i][TO]);
                strcpy(&definition[definition_len + from_len + to_len + 3], "\n");
            }
        }
    }

    if (definition[0] == '\0')
        printf("Word not found, \"%s\", try another word\n", input_word);
    else
        printf("%s", definition);
    
    free(definition);
}

int main(int argc, char *argv[]) {

    if (argc == 1)
        return 0;
    else if (argc == 2) {
        convert_to_proper_esperanto(argv[1]);
        search_dictionary_eo(EN, argv[1]);
    }
    else {
        if (strcmp(argv[2], "en") == 0)
            search_dictionary(en_to_eo, EN_TO_EO_LEN, argv[1]);
        else {
            convert_to_proper_esperanto(argv[1]);
            search_dictionary_eo(EN, argv[1]);
        }
    }

    return 0;
}

