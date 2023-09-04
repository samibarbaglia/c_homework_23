#include <stdio.h>

float read_integer(void) {
    float numbers;

    do {
        printf("\nEnter positive numbers or negative to stop:  ");

        if (scanf("%f", &numbers) == 1) {
            return numbers;
        } else {
            printf("Invalid input!\n");
            while (getchar() != '\n');
            numbers = 0;
        }
    } while (numbers == 0);
}

int main() {
    int i = 0;
    float avg;

    while (i >= 0) {
        float numbers = read_integer();

        if (numbers < 0) {
            break;
        }
        avg = avg + numbers;
        i++;
    }
    avg = avg / i;
    printf("\nYou entered %.0d positive numbers. The average is %.3f\n", i, avg);

    return 0;
}