#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHARACTERS 100

typedef struct node {
    int number;
    struct node *next;
} nnode;


void add_to_list(nnode **head, nnode **tail, int data) {
    nnode *new_node = (nnode *)malloc(sizeof(nnode));
    if (new_node == NULL) {
        printf("!! Error !!\n");
        return;
    }

    new_node->number = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = *tail = new_node;
    } else {
        (*tail)->next = new_node;
        *tail = new_node;
    }
}


void print_list(nnode **head) {
    while (*head != NULL) {
        printf("%d\n", (*head)->number);
        *head = (*head)->next;
    }
}


void clear_list(nnode **head) {
    while (*head != NULL) {
        nnode *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}


// PROGRAM STARTS HERE
int main() {
    char user_data[MAX_CHARACTERS] = {0};
    nnode *head = NULL;
    nnode *tail = NULL;

    while ((strcmp(user_data, "end") != 0)) {

        printf("Enter number or 'end' to stop: \n");
        fgets(user_data, sizeof(user_data), stdin);
        user_data[strlen(user_data) - 1] = '\0';

        int user_data_int = atoi(user_data); //scanf tai strol

        if ((strcmp(user_data, "end") == 0)) {
            printf("Quitting...\n");
        }
        else if (user_data_int != 0) {
            add_to_list(&head, &tail, user_data_int);
        }
        else {
            printf("!! Invalid input !!\n");
        }
    }
    printf("--------------\n");
    print_list(&head);
    clear_list(&head);
}