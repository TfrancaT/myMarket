#include <stdio.h>
#include <stdlib.h>

typedef struct noLista {
    int elemento;
    struct noLista* prox;
} noLista;

void inserirElemento(noLista** cabeca, int elemento){
    noLista* novoNo = (noLista*) malloc(sizeof(noLista));
    novoNo->elemento = elemento;
    novoNo->prox = NULL;

        if(*cabeca == NULL){
            *cabeca = novoNo;
        } else {
            noLista* atual = *cabeca;
            while(atual->prox != NULL){
                atual = atual->prox;
            }
            atual->prox = novoNo;
        }
}
