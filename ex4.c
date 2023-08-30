#include <stdio.h>

int read_integer(void) {
    int numbers;
    scanf("%d", &numbers);
    return numbers;
}

int main() {
    int i = 0;
    float avg;
    float sum = 0;

    while (i >= 0) {
        printf("\nEnter positive numbers or negative to stop: ");
        int numbers = read_integer();
        if (numbers < 0) {
            break;
        }
        sum = sum + numbers;
        i++;
    }
    avg = sum / i;
    printf("\nYou entered %.0d positive numbers. The average is %.3f", i, avg);

    return 0;
}