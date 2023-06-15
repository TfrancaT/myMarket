#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

int main(){

    struct node *head = malloc(sizeof(struct node));
    head->data = 1;
    head->next = NULL;

    struct node *nohUm = malloc(sizeof(struct node));
    nohUm->data = 2;
    nohUm->next = NULL;
    head->next = nohUm;

    struct node *current = head;
    while(current != NULL){
        printf("%d\n", current->data);
        current = current->next;
    }
        free(head);
            free(nohUm);

    return 0;
}