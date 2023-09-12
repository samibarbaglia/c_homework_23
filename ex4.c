#include <stdio.h>

int read_integer(void) {
    int numbers;

    do {
        printf("\nEnter positive numbers or negative to stop:  ");

        if (scanf("%d", &numbers) > 0) {
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
    float avg = 0;
    int loop = 1;

    while (loop == 1) {

        float numbers = read_integer();

        if (numbers < 0) {
            loop = 0;
        } else {
            avg = avg + numbers;
            i++;
        }
    }
    avg = avg / i;
    printf("\nYou entered %.0d positive numbers. The average is %.3f\n", i, avg);

    return 0;
}