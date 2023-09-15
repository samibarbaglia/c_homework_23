#include <stdio.h>
#include <string.h>

#define BUFFERMAX 1000

int replace_char(char *str, const char *repl) {
    if (strlen(repl) != 2) {
        printf("Invalid");
        return 0;
    }

    int amount_of_changes = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == repl[0]) {
            str[i] = repl[1];
            amount_of_changes += 1;
        }
    }
    return amount_of_changes;
}

int main() {
    char text[BUFFERMAX] = {0};
    int count;
    char new_char[3]; //must be 3, not 2! data type is char, aka there's a \0 at the end!!

    printf("Enter text: \n");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter the letter you want to replace and the new character/symbol together [ex. e3, q*, lH]: \n");
    scanf("%s", new_char);

    count = replace_char(text, new_char);

    if (count == 0) {
        printf("String was not modified\n");
    } else {
        printf("Changes: %d\n", count);
        printf("New text: \"%s\" ", text);
    }
}