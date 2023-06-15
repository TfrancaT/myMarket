#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

int main(){
    //Estrutura inicial da cabeça do nó;
    struct node *head = malloc(sizeof(struct node));
    head->data = 10;
    head->next = NULL;
    
    struct node *nohDois = malloc(sizeof(struct node));
    nohDois->data = 20;
    nohDois->next = NULL;
    head->next = nohDois;

    struct node *current = head;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }

}