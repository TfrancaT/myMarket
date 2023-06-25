#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id_item, qt_item;
    float valor_item;
    char nome_item[30];
} Item;

typedef struct noh_item {
    Item info;
    struct noh_item* seguinte;
} noh_item;

noh_item* criar_noh(Item info){
    noh_item* novo_noh = (noh_item*)malloc(sizeof(noh_item));
    novo_noh->info = info;
    novo_noh->seguinte = NULL;
    return novo_noh;
}

void inserir_noh(noh_item** cabeca, Item info){
    noh_item* novo_noh = criar_noh(info);
    novo_noh->info = info;
    novo_noh->seguinte = *cabeca;
    *cabeca = novo_noh;
}

void mostrar_nohs(noh_item* cabeca){
    noh_item* atual = cabeca;
        if(atual == NULL){
            printf("\n---------------------------");
            printf("\nNao Ha Itens Cadastrados.");
            printf("\n---------------------------");
            return;
        }

        printf("\n---------------------------");
        printf("\nEstocado: ");
        while(atual != NULL){
        printf("\nId: %d", atual->info.id_item);
        printf("\nNome: %s", atual->info.nome_item);
        printf("\nQuantidade: %d", atual->info.qt_item);
        printf("\nValor: %f", atual->info.valor_item);
        atual = atual->seguinte;
        }
}

Item novo_item;
noh_item *cabeca = NULL;

cadastro_item();
cadastro_item(){
    printf("\n--------------------");
    printf("\nCadastre ID: ");
    scanf("%d", &novo_item.id_item);
    printf("\nNome: ");
    scanf("%s", novo_item.nome_item);
    printf("\nQuantidade: ");
    scanf("%d", &novo_item.qt_item);
    printf("\nValor: ");
    scanf("%f", &novo_item.valor_item);
    inserir_noh(&cabeca, novo_item);
    printf("\n--------------------");
}

int main(){
    int opcao_menu;
        do{
            printf("\nBem-vindo ao Seu Estoque.");
            printf("\n--------------------");
            printf("\nO que deseja fazer? ");
            printf("\nInserir Item: (1);\nVer Estoque: (2);\nVender: (3);\nAtualizar Itens: (4);\nEncerrar: (0); ");
            scanf("%d", &opcao_menu);
                switch(opcao_menu)
                {
                    case 1:
                        cadastro_item();
                        break;

                    case 2:
                        mostrar_nohs(cabeca);
                        break;

                    case 3:
                        printf("\nFalta Implementar.");
                        break;
                    
                    case 4:
                        printf("\nFalta Implementar.");
                        break;
                }
        }while(opcao_menu != 0);

        return 0;
}