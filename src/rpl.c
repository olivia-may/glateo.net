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
    printf("%d\n", statinfo.st_size);
    file_contents = (char *)malloc(statinfo.st_size * sizeof(char));
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

    printf("%s", file_contents);
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

char *insert_string(char *insertee_string, int index, const char *inserter_string) {
    char *new_string = 
        (char *)malloc((strlen(insertee_string) + strlen(inserter_string) + 2)
            * sizeof(char));
    int i, j;

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
void remove_chars(char *stream, int amount) {
    int i;
    for (i = 0; i < strlen(stream); i++) {
        stream[i] = stream[i + amount];
    }
}

// 0       1            2          3
// replace "fromstring" "tostring" filename
int main(int argc, char **argv) {
    if (argc <= 3) {
        printf("Not enough arguments\n");
        return 0;
    }
    if (access(argv[3], F_OK) != 0) {
        printf("File not found '%s'\n", argv[3]);
        return 0;
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
