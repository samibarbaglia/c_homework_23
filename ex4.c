#include <stdio.h>

int read_integer(void) {
    float i = 0;
    float numbers = 0;
    float avg;
    float sum = 0;
    while (numbers >= 0) {
        printf("Enter positive numbers or negative to stop: \n");
        scanf("%f", &numbers);
        if (numbers > 0) {
            sum = sum + numbers;
            i++;
        }
        else {
            numbers = -1;
        }
    }
    avg = sum / i;
    printf("You entered %.0f positive numbers. The average is %.3f", i, avg);
}

int main() {
    read_integer();
    return 0;
}