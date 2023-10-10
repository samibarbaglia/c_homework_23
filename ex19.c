// got help with this code from milja h.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHARACTERS 81
#define MAX_SIZE 40

typedef struct menu_item_ {
    char name[50];
    double price;
} menu_item;

int name_sorting(const void *a, const void *b) {
    menu_item *menu1 = (menu_item *) a;
    menu_item *menu2 = (menu_item *) b;

    return strcmp(menu1->name, menu2->name);
}

int price_sorting(const void *a, const void *b) {
    menu_item *menu1 = (menu_item *) a;
    menu_item *menu2 = (menu_item *) b;

    return (menu1->price - menu2->price) > 0 ? 1 : -1;
}


int main() {
    FILE *file;
    char filename[MAX_CHARACTERS];
    char user_input[MAX_CHARACTERS];
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

    printf("Choose sorting order [1) Name, 2) Price]; \n");
    fgets(user_input, MAX_CHARACTERS, stdin);
    user_input[strcspn(user_input, "\n")] = '\0';

    if (strcmp(user_input, "1") == 0) {
        qsort(menu, menu_read, sizeof(menu_item), name_sorting);
    }
    else if (strcmp(user_input, "2") == 0) {
        qsort(menu, menu_read, sizeof(menu_item), price_sorting);
    }

    for (int i = 0; i < menu_read; i++) {
        printf("%-8.2lf %s\n", menu[i].price, menu[i].name);
    }
}