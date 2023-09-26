#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFFERMAX 80
#define MAX_LINES 100

int main() {
    FILE *file_input, *file_output;
    char filename[BUFFERMAX];
    char lines[MAX_LINES][BUFFERMAX] = {0};
    int lines_read = 0;

    printf("Enter file: \n");
    fgets(filename, BUFFERMAX, stdin);
    filename[strcspn(filename, "\n")] = '\0';
    file_input = fopen(filename, "r");

    if (file_input == NULL) {
        fprintf(stderr, "ERROR: No file '%s'\n", filename);
    }

    while (lines_read < MAX_LINES && fgets(lines[lines_read], BUFFERMAX, file_input)) {
        lines[lines_read][strcspn(lines[lines_read], "\n")] = '\0';
        for (int i = 0; lines[lines_read][i]; i++) {
            lines[lines_read][i] = toupper(lines[lines_read][i]);
        }
        lines_read++;
    }

    if (lines_read >= MAX_LINES) {
        fprintf(stderr, "WARNING: More lines than allowed. Extra lines deleted.\n");
    }

    fclose(file_input);
    file_output = fopen(filename, "w");

    for (int i = 0; i < lines_read; i++) {
        fprintf(file_output, "%s\n", lines[i]);
    }
    if (lines_read > 0) {
        printf("Conversion to CapsLock: DONE\n");
    }

    fclose(file_output);
}