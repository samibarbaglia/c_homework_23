#include <stdio.h>
#include <string.h>

#define BUFFERMAX 1000

int count_words(const char *str, const char *word) {
    int count = 0;
    const char *find_words = str;

    while ((find_words = strstr(find_words, word)) != NULL) {
        count++;
        find_words += strlen(word);
    }
    return count;
}


int main() {
    char sentence[BUFFERMAX] = {0};
    char word[BUFFERMAX] = {0};
    int count = 0;

    while (strcmp(word, "stop") != 0) {

        printf("Enter your sentence: \n");
        fgets(sentence, BUFFERMAX, stdin);
        sentence[strcspn(sentence, "\n")] = '\0';

        printf("Enter word to search or 'stop' to stop: \n");
        fgets(word, BUFFERMAX, stdin);
        word[strcspn(word, "\n")] = '\0';

        if (strcmp(word, "stop") == 0) {
            printf("Quitting...\n");
        } else {
            count = count_words(sentence, word);
            printf("Appears %d time(s)\n", count);
        }
    }
    return 0;
}