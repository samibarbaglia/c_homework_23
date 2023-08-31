// read more into pointers
#include <stdio.h>

int read_range(int low, int high) {
    int player_num = low - 1;

    do {
        printf("\nEnter a number between %d and %d:", low, high);
        scanf("%d", &player_num);
        if (getchar() != '\n' || player_num > high || player_num < low) {
            printf("!! Invalid input !!\n");
        } else {
            return player_num;
        }
    } while (1);
}

int main() {
    int i = 0;
    int low = 1;
    int high = 6;

    printf("Let's play!\nRoll a dice and enter your result.\n");

    while (i < 3) {
        int player_num = read_range(low, high);
        int game_num = player_num + 1;

        if (player_num < high) {
            printf("I got %d. I win!\n", game_num);
            i++;
        } else {
            printf("I got %d. It is a tie!\n", high);
            i++;
        }
    }
    printf("\nBetter luck next time. Bye!\n");
    return 0;
}