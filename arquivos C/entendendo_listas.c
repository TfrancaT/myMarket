#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

int main(){
    //Estruturando a cabeca do no;
    struct node *head = malloc(sizeof(struct node));
    head->data = 0;
    head->next = NULL;
    
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = 1;
    new_node->next = NULL;
    head->next = new_node;
    
    struct node *current = head;
    while (current != NULL){
        printf("%d\n", current->data);
        current = current->next;
    }
}