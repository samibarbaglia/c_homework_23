#include <stdio.h>
#include <stdbool.h>

bool read_positive(int *value);

int main(void) {
    int user_guess = 0;
    int user_attempts = 0;

    printf("Guess how much money I have!\n");

    do {
        if (read_positive(&user_guess) != 1) {
            user_attempts += 1;
        } else {
            printf("You didn't get it right. I have %d euros.\n", (user_guess * 2) + 20);
            user_attempts = user_attempts;
        }
    } while (user_attempts < 3);

    printf("\nI give up! See you later!\n");
}

bool read_positive(int *value) {

    printf("\nEnter a positive number: \n");
    if ((scanf("%d", value) != 1) || *value < 0) {
        printf("!! Invalid input !!\n");
        while (getchar() != '\n');
        return false;
    } if (*value > 0) {
        return true;
    }
    return 0;
}