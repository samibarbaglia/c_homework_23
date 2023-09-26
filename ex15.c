#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHARACTERS 81
#define MAX_SIZE 40

typedef struct menu_item_ {
    char name[50];
    double price;
} menu_item;

int main() {
    FILE *file;
    char filename[MAX_CHARACTERS];
    menu_item menu[MAX_SIZE];
    int menu_read = 0;


    printf("Enter file: \n");
    fgets(filename, MAX_CHARACTERS, stdin);
    filename[strcspn(filename, "\n")] = '\0';

    file = fopen(filename, "r");

    if (file == NULL) {
        fprintf(stderr, "ERROR: No file '%s'\n", filename);
    }
    while (menu_read < MAX_SIZE && fscanf(file, "%[^;];%lf\n", menu[menu_read].name, &menu[menu_read].price) == 2) {
        menu_read++;
    } if (menu_read >= MAX_SIZE) {
        fprintf(stderr, "WARNING: More items than allowed. Extra items not printed.\n");
    }

    fclose(file);
    for (int i = 0; i < menu_read; i++) {
        printf("%-8.2lf %s\n", menu[i].price, menu[i].name);
    }
}