#include <stdio.h>
#include <string.h>
#include <limits.h>

#define BUFFERMAX 1000

int main() {
    FILE *test;
    char filename[BUFFERMAX] = {0};
    int count = 0;
    int lines = 0;
    int highest = INT_MIN;
    int lowest = INT_MAX;

    printf("Enter file: \n");
    fgets(filename, BUFFERMAX, stdin);
    filename[strcspn(filename, "\n")] = '\0';
    test = fopen(filename, "r");

    if (test == NULL) {
        fprintf(stderr, "ERROR: No file '%s'\n", filename);
    }

    while (test != NULL) {
        while (fscanf(test, "%d", &count) == 1) {
            lines++;
            if (count < lowest) {
                lowest = count;
            } else if (count > highest) {
                highest = count;
            }
        } if (!feof(test)) {
            printf("!! ERROR READING FILE ON LINE %d !!\n", lines);
        }

        fclose(test);
        printf("---------------------\n");
        printf("Lines of numbers in total: %d\n", lines);
        printf("Highest number: %d\n", highest);
        printf("Lowest number: %d\n", lowest);
        test = NULL;
    }

    return 0;
}