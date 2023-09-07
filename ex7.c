#include <stdio.h>
#include <string.h>

//int read_positive() {}
// bool read_positive(int *value);

int main(void) {
    char name[32];
    printf("Enter your name: ");
    fgets(name, 32, stdin);
    if(name[strlen(name) - 1] == '\n') {
        name[strlen(name) - 1] = '\0';
    }
}