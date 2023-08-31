#include <stdio.h>

int read_integer(void) {
    int numbers;

    do {
        printf("\nEnter positive numbers or negative to stop:  ");

        if (scanf("%d", &numbers) == 1) {
            return numbers;
        } else if (getchar() != '\n') {
            printf("\n!! Invalid input !!\n");
        }

    } while (numbers == 0);
}

int main() {
    int i = 0;
    float avg;
    int sum = 0;

    while (i >= 0) {
        int numbers = read_integer();

        if (numbers < 0) {
            break;
        }
        sum = sum + numbers;
        i++;
    }
    avg = sum / i;
    printf("\nYou entered %.0d positive numbers. The average is %.3f\n", i, avg);

    return 0;
}