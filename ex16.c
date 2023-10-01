#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHARACTERS 100

typedef struct node {
    int number;
    struct node *next;
} nnode;


void add_to_list(nnode **head, nnode **tail, int data) {
    nnode *new_node = (nnode *) malloc(sizeof(nnode));
    new_node->number = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = *tail = new_node;
    } else {
        (*tail)->next = new_node;
        *tail = new_node;
    }
}


void print_list(nnode **i) {
    while (*i != NULL) {
        printf("%d\n", (*i)->number);
        *i = (*i)->next;
    }
}


void clear_list(nnode **i) {
    while (*i != NULL) {
        nnode *temp = *i;
        *i = (*i)->next;
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

        int user_data_int = atoi(user_data);

        if ((strcmp(user_data, "end") != 0)) {
            //empty so that code won't print "invalid input" for end
        }
        if (user_data_int != 0) {
            add_to_list(&head, &tail, user_data_int);
        }
        else {
            printf("!! Invalid input !!\n");
        }
    }
    nnode *i = head;
    printf("--------------\n");
    print_list(&i);
    clear_list(&i);
}