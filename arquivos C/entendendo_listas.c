#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct meuNo {
    int info;
    struct meuNo* prox;
} meuNo;

/* Alocando uma função de criação do nó e apontando para a sua estrutura;
 * observa-se que a variável (novoNo) está sendo apontada e alocada em um espaço de memória da estrutura do nó;
 * a variável (novoNo) está apontando para a váriavel (info) onde armazenará o valor do nó;
 * a mesma variável (novoNo) está apontando para o ponteiro que estará direcionando para a próxima estrutura de um nó;*/
meuNo* criarNo(int info) {
    meuNo* novoNo = (meuNo*) malloc(sizeof(meuNo)); // aloca um espaço de memória no formato da estrutura criada do nó;
    novoNo->info = info; // "chama" a variável alocada e aponta o seu valor;
    novoNo->prox = NULL; // "chama" a variavel alocada e define seu ponteiro, onde este estará apontando para um próximo elemento nó;
    return novoNo; // retorna o nó criado;
}

void inserirNaLista (meuNo** head, int info) {
    meuNo* novoNo = criarNo(info);
    novoNo->prox = NULL;
    if (*head == NULL) {
        *head = novoNo;
    } else { 
        meuNo* atual = *head;
        while (atual->info != NULL) { 
            atual = atual->prox;
        }
        atual->prox = novoNo;
    }
}