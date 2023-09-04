#include <stdio.h>
#include <stdlib.h>

int roll_dice(int dice) {
    dice = ((rand() % dice) + 1);
    printf("%d \n", dice);
    return dice;
}

int dice_choice(int player_choice) {
    if (player_choice == 1) {
        roll_dice(6);
    } else if (player_choice == 2) {
        roll_dice(10);
    }
    return 0;
}

int main() {
    int player_choice = 0;

    do {
        printf("\n1) Roll D6\n"
               "2) Roll D10\n"
               "3) Quit\n");
        scanf("%d", &player_choice);

        if (player_choice < 1 || player_choice > 3) {
            while (getchar() != '\n');
            printf("!! Invalid input !!\n");
        } else {
            dice_choice(player_choice);
        }
    } while (player_choice != 3);

    return 0;
}