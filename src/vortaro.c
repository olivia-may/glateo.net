#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define EO_TO_EN_LEN 46
#define EN_TO_EO_LEN 7

typedef struct {
    const char *from;
    const char *to;
} wordlist;

const wordlist eo_to_en[EO_TO_EN_LEN] = {
    {"saluton", "(salut·o)\n  hello\n"},
    {"ino", "(in·o)\n  woman\n"},
    {"ina", "(in·a)\n  female\n"},
    {"ine", "(in·e)\n  female\n"},
    {"iĉo", "(iĉ·o)\n  man\n"},
    {"iĉa", "(iĉ·a)\n  male\n"},
    {"iĉe", "(iĉ·e)\n  male\n"},
    {"ipo", "(ip·o)\n  nonbinary person\n"},
    {"ipa", "(ip·a)\n  nonbinary\n"},
    {"ipe", "(ip·e)\n  nonbinary\n"},
    {"abado", "(abad·o)\n  (gender-neutral) abbot \n"},
    {"avuo", "(avu·o)\n  grandparent\n"},
    {"petolinfano", "(petol·infan·o)\n  wicked child\n"},
    {"eŝo", "(eŝ·o)\n  spouse\n"},
    {"grofo", "(grof·o)\n  (title) count\n"},
    {"fianceo", "(fiance·o)\n  (gender neutral) fiancé\n"},
    {"filo", "(fil·o)\n  child, (gender neutral) son\n"},
    {"sahodo", "(sahod·o)\n  sibling\n"},
    {"neeŝo", "(ne·eŝ·o)\n  unmarried person\n"},
    {"kido", "(kid·o)\n  kid\n"},
    {"kuzeno", "(kuzen·o)\n  cousin\n"},
    {"monĥo", "(monĥ·o)\n  (gender neutral) monk\n"},
    {"nepoto", "(nepot·o)\n  grandchild\n"},
    {"nievo", "(niev·o)\n  nibling, (gender neutral) nephew\n"},
    {"ontio", "(onti·o)\n  (gender neutral) uncle\n"},
    {"parento", "(parent·o)\n  parent\n"},
    {"prenso", "(prens·o)\n  (gender neutral) prince\n"},
    {"rejĝo", "(rejĝ·o)\n  regent, (gender neutral) king\n"},
    {"duĉo", "(duĉ·o)\n  (gender neutral) duke\n"},
    {"sioro", "(sior·o)\n  (gender neutral) sir, (gender neutral) ma'am\n"},
    {"viduo", "(vidv·o)\n  (gender neutral) widow\n"},
    {"adolto", "(adolt·o)\n  adult\n"},
    {"adoltino", "(adolt·in·o)\n  woman\n"},
    {"adoltiĉo", "(adolt·iĉ·o)\n  man\n"},
    {"plenkreskulo", "(plen·kresk·ul·o)\n  adult\n"},
    {"plenkreskulino", "(plen·kresk·ul·in·o)\n  woman\n"},
    {"plenkreskuliĉo", "(plen·kresk·ul·iĉ·o)\n  man\n"},
    {"homo", "(hom·o)\n  person\n"},
    {"homino", "(hom·in·o)\n  woman\n"},
    {"homiĉo", "(hom·iĉ·o)\n  man\n"},
    {"persono", "(person·o)\n  person\n"},
    {"personino", "(person·in·o)\n  woman\n"},
    {"personiĉo", "(person·iĉ·o)\n  man\n"},
    {"femino", "(fem·in·o)\n  woman\n"},
    {"viro", "(vir·o)\n  man\n"},
    {"ri", "(ri)\n  (singular) they, (gender neutral) he\n"},
};

const wordlist en_to_eo[EN_TO_EO_LEN] = {
    {"hi", "saluton\n"},
    {"person", "homo, persono\n"},
    {"woman", "(adult) adoltino, plenkreskulino, femino; homino, personino\n"},
    {"man", "(adult) adolti\u0109o, plenkreskuli\u0109o, viro; homi\u0109o, personi\u0109o\n"},
    {"he", "ri, li\n"},
    {"she", "ri, \u015di\n"},
    {"they", "(singular) ri; (plural) ili\n"},
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

void search_dictionary(const wordlist *wl, const int wordlist_len,
    char *input_word) {

    int i;
    int j;
    char *definition;

    definition = malloc(sizeof(char));
    definition[0] = '\0';

    for (i = 0; i < wordlist_len; i++) {

        for (j = 0; j < strlen(input_word); j++) {
            
            if (input_word[j] != wl[i].from[j]) break;
            
            if (j == strlen(input_word) - 1) {
            
                definition =
                    realloc(definition, 
                    (strlen(definition) + strlen(wl[i].to + 1)
                    * sizeof(char)));
                
                strcpy(&definition[strlen(definition)], wl[i].to);
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
        search_dictionary(eo_to_en, EO_TO_EN_LEN, argv[1]);
    }
    else {
        if (strcmp(argv[2], "en") == 0)
            search_dictionary(en_to_eo, EN_TO_EO_LEN, argv[1]);
        else {
            convert_to_proper_esperanto(argv[1]);
            search_dictionary(eo_to_en, EO_TO_EN_LEN, argv[1]);
        }
    }

    return 0;
}

