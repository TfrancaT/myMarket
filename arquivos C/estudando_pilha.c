#include <stdio.h>
#include <stdlib.h>

//Criando um n�
typedef struct Node {
    int data;
    struct Node* next;
} Node;

//Definindo a Pilha
typedef struct Stack {
    Node* top;
} Stack;

//Criando uma Pilha
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

//Verifica se a pilha est� vazia se re
int isEmpty(Stack* stack) {
    return (stack->top == NULL);
}

//Empilhar
void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}
int pop(Stack* stack) {
   
    if (isEmpty(stack)) {
        printf("A pilha est� vazia!\n");
        return -1;
    }
   
    Node* temp = stack->top;
    // o dado que ele retirou da pilha
    int data = temp->data;
    //Proximo vai ser o topo
    stack->top = temp->next;
    //limpar
    free(temp);
    //retornando o dado que eu desempilhei
    return data;
}

int main() {
   
    Stack* stack = createStack();
    int soma = 0;
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    pop(stack);
    pop(stack);
    pop(stack);
    push(stack, 25);

    printf("A Soma de todos os elementos de uma pilha:\n");
   
    while (!isEmpty(stack)) {
        soma += pop(stack);
       
    }
     printf("%d\n", soma);
    return 0;
}
