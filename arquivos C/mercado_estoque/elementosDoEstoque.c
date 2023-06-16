#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produtos {
    int idProduto;
    int quantidadeProduto;
    char nomeProduto[50];
    char tipoProduto[50];
    float precoProduto;
} Produtos;

typedef struct noProduto {
    int value;
    struct noProduto* next;
} noProduto;

noProduto* criarNo(int value){
    noProduto* novoNo = (noProduto*) malloc(sizeof(noProduto));
    novoNo->value = value;
    novoNo->next = NULL;
    return novoNo;
}

void inserirInicio(noProduto** head, int value) {
    noProduto* novoNo = criarNo(value);
    novoNo->next = *head;
    *head = novoNo;
}

void inserirFinal(noProduto** head, int value){
    noProduto* novoNo = (noProduto*) malloc(sizeof(noProduto));
    novoNo->value = value;
    novoNo->next = NULL;

    if(*head == NULL){
        *head = novoNo;
    } else {
        noProduto* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = novoNo;
    }
}

void imprimirLista(noProduto* head) {
    noProduto* current = head;
    while(current != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    }
    printf("\n");
}

void removerInicio(noProduto** head) {
    if(*head == NULL) {
        printf("Lista vazia.");
        return;
    }
    noProduto* current = *head;
    *head = (*head)->next;
    free(current);
}

int main() {
    noProduto* lista = NULL;

/*  inserirInicio(&lista, 10);
    inserirInicio(&lista, 5);
    inserirInicio(&lista, 0); */

    inserirFinal(&lista, 2);
    inserirFinal(&lista, 4);
    inserirFinal(&lista, 6);
    inserirFinal(&lista, 8);
    inserirFinal(&lista, 10);
    imprimirLista(lista);

/*  removerInicio(&lista);
    imprimirLista(lista); */

    return 0;
}