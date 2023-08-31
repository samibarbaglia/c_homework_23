#include <stdio.h>

int read_integer(void) {
    int numbers;

    do {
        printf("\nEnter positive numbers or negative to stop:  ");

        if (scanf("%d", &numbers) == 1) {
            return numbers;
        }
        else if (scanf("%d", &numbers) != 1) {
            while (getchar() != '\n');
            printf("\n!! Invalid input !!\n");
        }
    } while (numbers == 0);
}

int main() {
    float i = 0;
    float avg;
    float sum = 0;

    while (i >= 0) {
        float numbers = read_integer();

        if (numbers < 0) {
            break;
        }
        sum = sum + numbers;
        i++;
    }
    avg = sum / i;
    printf("\nYou entered %.0f positive numbers. The average is %.3f\n", i, avg);

    return 0;
}