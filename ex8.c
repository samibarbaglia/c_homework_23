#include <stdio.h>
#include <stdlib.h>

void print_numbers(const int *array, int count);

int main() {
    int rounds = 5;
    int random_array[rounds];
    int i = 0;

    while (i < rounds) {
        random_array[i] = rand();
        i++;
    }
    print_numbers(random_array, rounds);
}

void print_numbers(const int *array, int count) {
    for (int i = 0; i < count; i++) {
        printf("%8d\n", array[i]);
    }
}