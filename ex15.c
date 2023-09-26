#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHARACTERS 81
#define MAX_SIZE 2

struct menu_item_ {
    char name[50];
    double price;
};

int main() {
    FILE *file;
    char filename[MAX_CHARACTERS];
    char food[MAX_SIZE]= {0};
    int lines_read = 0;


    printf("Enter file: \n");
    fgets(filename, MAX_CHARACTERS, stdin);
    filename[strcspn(filename, "\n")] = '\0';

    file = fopen(filename, "r");

    if (file == NULL) {
        fprintf(stderr, "ERROR: No file '%s'\n", filename);
    }
    else {

    }
}