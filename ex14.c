#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHARACTERS 81
#define MAX_LINES 100

int main() {
    FILE *file;
    char filename[MAX_CHARACTERS];
    char lines[MAX_LINES][MAX_CHARACTERS] = {0};
    int lines_read = 0;

    printf("Enter file: \n");
    fgets(filename, MAX_CHARACTERS, stdin);
    filename[strcspn(filename, "\n")] = '\0';

    file = fopen(filename, "r");

    if (file == NULL) {
        fprintf(stderr, "ERROR: No file '%s'\n", filename);
    }

    while (lines_read < MAX_LINES && fgets(lines[lines_read], MAX_CHARACTERS, file)) {
        lines[lines_read][strcspn(lines[lines_read], "\n")] = '\0';
        for (int i = 0; lines[lines_read][i]; i++) {
            lines[lines_read][i] = toupper(lines[lines_read][i]);
        }
        lines_read++;
    } if (lines_read >= MAX_LINES) {
        fprintf(stderr, "WARNING: More lines than allowed. Extra lines deleted.\n");
    }

    fclose(file);
    file = fopen(filename, "w");

    for (int i = 0; i < lines_read; i++) {
        fprintf(file, "%s\n", lines[i]);
    } if (lines_read > 0) {
        printf("Conversion to CapsLock: DONE\n");
    }

    fclose(file);
}