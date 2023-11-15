/*
 * Replace string in a file with another string, with a readable syntax
 * TODO: finish this program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/stat.h>

char *get_file_contents(const char *loc) {

    struct stat statinfo;
    FILE *file = fopen(loc, "r");
    char *file_contents = NULL;
    
    stat(loc, &statinfo);
    file_contents = (char *)malloc(statinfo.st_size * sizeof(char));
    if (!file_contents) {
        fprintf(stderr, "Failed to allocate memory to read %s\n", loc);
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

// looks at beginning of stream
bool is_stream_match_word(const char *stream, const char *word) {
    for (int j = 0; j < strlen(word); j++) {            
        if (stream[j] != word[j]) {
            return false;
        }
    }
    
    return true;
}

char *insert_string(char *insertee_string, const int index, const char *inserter_string) {
    char *new_string = 
        (char *)malloc((strlen(insertee_string) + strlen(inserter_string) + 2)
        * sizeof(char));
    int i, j;

    if (!new_string) {
        fprintf(stderr, "Failed to allocate memory to insert %s into stream\n",
            inserter_string);
        exit(2);
    }

    for (i = 0; i < index; i++) {
        new_string[i] = insertee_string[i];
    }
    for (j = 0; j < strlen(inserter_string); j++) {
        new_string[i + j] = inserter_string[j];
    }
    for (i; i < strlen(insertee_string) + 1; i++) {
        new_string[i + j] = insertee_string[i];
    }

    free(insertee_string);
    return new_string;
}

// beginning of stream
void remove_chars(char *stream, const int amount) {
    int i;
    for (i = 0; i < strlen(stream); i++) {
        stream[i] = stream[i + amount];
    }
}

// 0   1        2        3
// rpl OLD-TEXT NEW-TEXT FILE
int main(int argc, char **argv) {

    if (argc < 4) {
        
        printf("usage: rpl [-h]\n           OLD-TEXT NEW-TEXT FILE\n");

        if (argc > 1) {
            if (strcmp("-h", argv[1]) == 0 || strcmp("--help", argv[1]) == 0) {

                printf("Search and replace text in files.\n\npositional arguments:\n  OLD-TEXT\n  NEW-TEXT\n  FILE\n\noptional arguments:\n-h, --help\n");
                return 0;
            }
        }

        fprintf(stderr, "rpl: error: the following arguments are required: OLD-TEXT, NEW-TEXT, FILE\n");
    
        return 1;
    }
    if (access(argv[3], F_OK) != 0) {

        fprintf(stderr, "rpl: error: file not found '%s'\n", argv[3]);
        return 1;
    }

    char *stream = get_file_contents(argv[3]);
    
    for (int i = 0; i < strlen(stream) - strlen(argv[1]); i++) {
        if (is_stream_match_word(&stream[i], argv[1])) {
            remove_chars(&stream[i], strlen(argv[1]));
            stream = insert_string(stream, i, argv[2]);
        }
    }
    
    FILE *file = fopen(argv[3], "w");
    fprintf(file, "%s", stream);

    fclose(file);
    free(stream);
    return 0;
}
