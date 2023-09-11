#include <stdio.h>
#include <stdlib.h>

int find_first(const unsigned int *array, unsigned int what);

int main() {
    const int size = 20;
    unsigned int random_array[size];
    int choice = 0;

    // random array values 0-19
    for (int i = 0; i < size - 1; i++) {
        random_array[i] = ((rand() % size) + 1);
        printf("%d\n", random_array[i]);
    }

    // last array value must be 0
    random_array[size - 1] = 0;
    printf("%d\n", random_array[size - 1]);

    do {
        printf("\nEnter number to search or 0 to stop: ");

        // eliminates multiple invalid inputs
        while (scanf("%d", &choice) == 0) {
            printf("Invalid input\n");
            while (getchar() != '\n') {
                // loops nothing for cleaner output
            }
            printf("\nEnter number to search or 0 to stop: ");
        }
        //actual array and user number choice testing
        int result = find_first(random_array, choice);
        if (result != -1) {
            printf("Number found at index [%d]\n", result);
        } else {
            printf("Number not found\n");
        }
    } while (choice != 0);
}


int find_first(const unsigned int *array, unsigned int what) {
    for (int i = 0; array[i] != 0; i++) {
        if (array[i] == what) {
            return i;
        }
    }
    return -1;
}