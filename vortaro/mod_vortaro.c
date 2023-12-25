/* 
**  mod_vortaro.c -- Apache sample vortaro module
**  [Autogenerated via ``apxs -n vortaro -g'']
**
**  To play with this sample module first compile it into a
**  DSO file and install it into Apache's modules directory 
**  by running:
**
**    $ apxs -c -i mod_vortaro.c
**
**  Then activate it in Apache's apache2.conf file for instance
**  for the URL /vortaro in as follows:
**
**    #   apache2.conf
**    LoadModule vortaro_module modules/mod_vortaro.so
**    <Location /vortaro>
**    SetHandler vortaro
**    </Location>
**
**  Then after restarting Apache via
**
**    $ apachectl restart
**
**  you immediately can request the URL /vortaro and watch for the
**  output of this module. This can be achieved for instance via:
**
**    $ lynx -mime_header http://localhost/vortaro 
**
**  The output should be similar to the following one:
**
**    HTTP/1.1 200 OK
**    Date: Tue, 31 Mar 1998 14:42:22 GMT
**    Server: Apache/1.3.4 (Unix)
**    Connection: close
**    Content-Type: text/html
**  
**    The sample page from mod_vortaro.c
**
**
**  All code not generated by apxs or copied from the Apache project
**  is licensed under the GPL-3.
**
**  mod_vortaro - dictionary module for glateo.net
**  Copyright (C) 2023  Olivia May
**
**  This program is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <unistd.h>

#include "httpd.h"
#include "http_config.h"
#include "http_protocol.h"
#include "ap_config.h"
#include "apr_strings.h"
#include "vortaro.h"

// what language the user is using the website in
enum {
    ESPERANTO = 0,
    ENGLISH
};

char *eo_vortaro_page = NULL;

char *en_vortaro_page = NULL; 

psc4b_str *every_definition = NULL;

// From apache2 modguide
typedef struct {
    char *key;
    char *value;
} keyValuePair;
// End apache2 modguide

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

// warning, will not have nullchar
void inline vrtr_strcat(psc4b_str *dest, const psc1b_str *src) {
   
    for (int i = 0; i < src[0]; i++)
        dest->str[dest->len + i] = src[1 + i];

    dest->len += src[0];
}

psc4b_str *search_dictionary_eo(const int to_language,
    const char *input_word) {

    int i, j, input_word_len;
    psc4b_str *definition;

    definition = malloc(sizeof(int) + sizeof(char));
    definition->str[0] = '\0';
    definition->len = 0;

    input_word_len = strlen(input_word);

    for (i = 0; i < DICTIONARY_LEN; i++) {

        for (j = 0; j < input_word_len; j++) {
            
            if (dictionary[i][EO1][1 + j] == '\0') break;        
            if (input_word[j] != dictionary[i][EO1][1 + j]) break;
            if (j == input_word_len - 1) {
            
                // + 27 because of length of all below string literals + nullchar
                definition = realloc(definition, sizeof(int) +
                    (definition->len + dictionary[i][EO1][0] +
                    dictionary[i][EO2][0] + dictionary[i][to_language][0] + 29)
                    * sizeof(char));
                
                vrtr_strcat(definition, "\003<b>");
                vrtr_strcat(definition, dictionary[i][EO1]);
                vrtr_strcat(definition, "\006</b> (");
                vrtr_strcat(definition, dictionary[i][EO2]);
                vrtr_strcat(definition, "\013)<br>&emsp;"); // 11 len
                vrtr_strcat(definition, dictionary[i][to_language]);
                vrtr_strcat(definition, "\010<br><br>"); // 8 len

                // put nullchar on the end without adding to the len
                definition->str[definition->len] = '\0';
            }
        }
    }

    return definition;
}

psc4b_str *search_dictionary(const char *wl[][2], const int wordlist_len,
    const char *input_word) {

    int i, j;
    psc4b_str *definition;
    int input_word_len;

    definition = malloc(sizeof(int) + sizeof(char));
    definition->str[0] = '\0';
    definition->len = 0;

    input_word_len = strlen(input_word);

    for (i = 0; i < wordlist_len; i++) {

        for (j = 0; j < input_word_len; j++) {
            
            if (wl[i][FROM][1 + j] == '\0') break;
            if (input_word[j] != wl[i][FROM][1 + j]) break;
            
            if (j == input_word_len - 1) {
            
                // + 26 because of length of all below string literals + nullchar
                definition =
                    realloc(definition, sizeof(int) +
                    (definition->len + wl[i][FROM][0] + wl[i][TO][0] + 26)
                    * sizeof(char));
                
                vrtr_strcat(definition, "\003<b>"); // 3 len
                vrtr_strcat(definition, wl[i][FROM]);
                vrtr_strcat(definition, "\016</b><br>&emsp;"); // 14 len
                vrtr_strcat(definition, wl[i][TO]);
                vrtr_strcat(definition, "\010<br><br>"); // 8 len

                definition->str[definition->len] = '\0';
            }
        }
    }

    return definition;
}

// From apache2 modguide
keyValuePair *readPost(request_rec *r) {
    apr_array_header_t *pairs = NULL;
    apr_off_t len;
    apr_size_t size;
    int res;
    int i = 0;
    char *buffer;
    keyValuePair *kvp;

    res = ap_parse_form_data(r, NULL, &pairs, -1, HUGE_STRING_LEN);
    if (res != OK || !pairs) return NULL; /* Return NULL if we failed or if there are is no POST data */
    kvp = apr_pcalloc(r->pool, sizeof(keyValuePair) * (pairs->nelts + 1));
    while (pairs && !apr_is_empty_array(pairs)) {
        ap_form_pair_t *pair = (ap_form_pair_t *) apr_array_pop(pairs);
        apr_brigade_length(pair->value, 1, &len);
        size = (apr_size_t) len;
        buffer = apr_palloc(r->pool, size + 1);
        apr_brigade_flatten(pair->value, buffer, &size);
        buffer[len] = 0;
        kvp[i].key = apr_pstrdup(r->pool, pair->name);
        kvp[i].value = buffer;
        i++;
    }
    return kvp;
}
// End apache2 modguide

char *get_file_contents(const char *path, apr_pool_t *p) {
    FILE *file;
    char *file_contents;
    struct stat statinfo;
    long int size;

    file = fopen(path, "r");
    stat(path, &statinfo);
    // + 1 because null char
    file_contents = (char *)apr_palloc(p, (statinfo.st_size + 1) * sizeof(char));
    if (!file_contents) {
        fprintf(stderr, "apr_palloc failed\n");
        exit(2);
    }
    int i = 0;
    int ch;
    while (true) {
        ch = fgetc(file);
        if (ch < 0) break;
        file_contents[i] = ch;
        i++;
    }
    file_contents[i] = '\0';
    fclose(file);

    return file_contents;
}

/* The sample content handler */
static int vortaro_handler(request_rec *r) {
#define PRINT_PAGE(page, word_not_found_str) \
\
while (page[i] != '\0') { \
\
    if (!strncmp(&page[i], \
        /* 23 len of ?vrtr_xx_to_yy_selected */ \
        "?vrtr_eo_to_en_selected", 23)) { \
        if (!strcmp(r->method, "POST")) {\
            if (kvp->key) { \
                if (!strcmp(kvp[1].value, "eo_to_en")) { \
                    ap_rputs("selected=\"selected\"", r); \
                } \
            } \
        } \
        i += 23; \
    } \
    if (!strncmp(&page[i], \
        "?vrtr_en_to_eo_selected", 23)) { \
\
        if (!strcmp(r->method, "POST")) {\
            if (kvp->key) { \
                if (!strcmp(kvp[1].value, "en_to_eo")) { \
                    ap_rputs("selected=\"selected\"", r); \
                } \
            } \
        } \
        i += 23; \
    } \
\
    /* `16` len of ?vrtr_definition */ \
    if (!strncmp(&page[i], "?vrtr_definition", 16)) { \
\
        if (!strcmp(r->method, "POST")) { \
            if (kvp->key) { \
    \
                /* if "word".value is not only null char (no input) */ \
                if (kvp[0].value[0]) {\
    \
                    convert_to_proper_esperanto(kvp[0].value); \
        \
                    if (!strcmp(kvp[1].value, "eo_to_en")) { \
                        definition = search_dictionary_eo(EN, kvp[0].value); \
                    } \
                    else if (!strcmp(kvp[1].value, "en_to_eo")) { \
                        definition = search_dictionary(en_to_eo, EN_TO_EO_LEN, \
                            kvp[0].value); \
                    } \
        \
                    if (!definition->len) \
                        ap_rputs(word_not_found_str, r); \
                    else \
                        ap_rputs(definition->str, r); \
        \
                    free(definition); \
                } \
            } \
            else { \
                ap_rputs(every_definition->str, r); \
            } \
        } \
        i += 16; \
    } \
\
    ap_rputc(page[i], r); \
    i++; \
}

    int language;
    keyValuePair *kvp = NULL;
    psc4b_str *definition;
    int i = 0;

    if (!strcmp(r->uri, "/eo/vortaro")) {
        language = ESPERANTO;
    }
    else if (!strcmp(r->uri, "/en/vortaro")) {
        language = ENGLISH;
    }
    else
        return DECLINED;
    
    r->content_type = "text/html";
    
    if (!r->header_only) {
                
        if (!strcmp(r->method, "POST")) {
            kvp = readPost(r);
        }

        switch (language) {

            case ESPERANTO: {
                PRINT_PAGE(eo_vortaro_page,
                    "La vorto ne estis trovita, provu alian vorton.")
            } break;
            case ENGLISH:
                PRINT_PAGE(en_vortaro_page,
                    "Word not found, try another word.");
                break;
        }
    }
    return OK;
}

// TODO figure out why this function gets called twice, and make it
// not open the files twice
static void vortaro_register_hooks(apr_pool_t *p)
{
    int alloc_len = 0;
    int i;
    
    ap_hook_handler(vortaro_handler, NULL, NULL, APR_HOOK_MIDDLE);

    if (!access("/var/www/glateo.net/eo/vortaro", F_OK)) {
        eo_vortaro_page = get_file_contents("/var/www/glateo.net/eo/vortaro", p);
    }
    else
        fputs("Could not access /var/www/glateo.net/eo/vortaro/", stderr);

    if (!access("/var/www/glateo.net/en/vortaro", F_OK)) {
        en_vortaro_page = get_file_contents("/var/www/glateo.net/en/vortaro", p);
    }
    else
        fputs("Could not access /var/www/glateo.net/en/vortaro/", stderr);

    // eo to en
    for (i = 0; i < DICTIONARY_LEN; i++) {
        alloc_len += dictionary[i][EO1][0] + dictionary[i][EO2][0]
            + dictionary[i][EN][0] + 29;
    }
    // en to eo
    for (i = 0; i < EN_TO_EO_LEN; i++) {
        alloc_len += en_to_eo[i][TO][0] + en_to_eo[i][FROM][0] + 26;
    }

    // + 1 for null char
    every_definition = (psc4b_str *)apr_palloc(p, sizeof(int) + (alloc_len + 1) *
        sizeof(char));
    every_definition->len = 0;
    every_definition->str[0] = '\0';

    vrtr_strcat(every_definition, "\035<h2>Esperanto -> English</h2>");

    for (int i = 0; i < DICTIONARY_LEN; i++) {
        vrtr_strcat(every_definition, "\003<b>");
        vrtr_strcat(every_definition, dictionary[i][EO1]);
        vrtr_strcat(every_definition, "\006</b> (");
        vrtr_strcat(every_definition, dictionary[i][EO2]);
        vrtr_strcat(every_definition, "\013)<br>&emsp;");
        vrtr_strcat(every_definition, dictionary[i][EN]);
        vrtr_strcat(every_definition, "\010<br><br>");
    }

    vrtr_strcat(every_definition, "\035<h2>English -> Esperanto</h2>");

    for (int i = 0; i < EN_TO_EO_LEN; i++) {
        vrtr_strcat(every_definition, "\003<b>");
        vrtr_strcat(every_definition, en_to_eo[i][FROM]);
        vrtr_strcat(every_definition, "\016</b><br>&emsp;");
        vrtr_strcat(every_definition, en_to_eo[i][TO]);
        vrtr_strcat(every_definition, "\010<br><br>");
    }

    every_definition->str[every_definition->len - 4] = '\0';
}

/* Dispatch list for API hooks */
module AP_MODULE_DECLARE_DATA vortaro_module = {
    STANDARD20_MODULE_STUFF, 
    NULL,                  /* create per-dir    config structures */
    NULL,                  /* merge  per-dir    config structures */
    NULL,                  /* create per-server config structures */
    NULL,                  /* merge  per-server config structures */
    NULL,                  /* table of config file commands       */
    vortaro_register_hooks  /* register hooks                      */
};

