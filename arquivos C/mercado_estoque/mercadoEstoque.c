#include <stdio.h>
#include <stdlib.h>

typedef struct Products{
    int amountProd;
    int id;
    int codProd;
    char name[50];
    float priceProd;
} Products;

typedef struct noList {
    int element;
    struct noList* prox;
} noList;

void inserirFinal(noList** cabeca, int element){
    noList* novoNo = (noList*)malloc(sizeof(noList));
    novoNo->element = element;
    novoNo->prox = NULL;

        if(*cabeca == NULL){
            *cabeca = novoNo;
        } else {
            noList* atual = *cabeca;
            while(atual->prox != NULL){
                atual = atual->prox;
            }
            atual->prox = novoNo;
        }
}

void imprimirLista(noList* cabeca){
    noList* atual = cabeca;
    while(atual != NULL){
        printf("%d\n", atual->element);
        atual = atual->prox;
    }
    printf("\n");
}

int main(){
    
    
    return 0;
}