#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERMAX 100

int main() {
    char user_str[BUFFERMAX] = {0};
    int i = 0;

    while (strcmp(user_str, "stop") != 0) {
        printf("Enter string or 'stop' to stop: ");
        fgets(user_str, BUFFERMAX, stdin);

        for (i = 0; user_str[i] != '\n'; i++) {
            // empty loop for checking
        }
        user_str[i] = '\0';
        printf("Lenght of string: %d\n", i);
    }

}