#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char nome_produto[50];
    int id_produto, quantidade_produto;
    float preco_produto;
} Produto;

typedef struct lista {
    Produto valor;
    struct lista* proximo;
} lista;

lista* criar_no(Produto valor){
    lista* novo_no = (lista*)malloc(sizeof(lista));
    novo_no->valor = valor;
    novo_no->proximo = NULL;
    return novo_no;
}

lista* inserir_inicio(lista** cabeca, Produto valor){
    lista* novo_no = criar_no(valor);
	novo_no->valor = valor;
	novo_no->proximo = *cabeca;
	*cabeca = novo_no;
}

void imprimir_lista(lista* cabeca){
    lista* atual = cabeca;
    if(atual == NULL){
        printf("SEM ITENS PARA MOSTRAR.\n");
        return;
    }

        printf("DISPONIVEL EM ESTOQUE: \n");
        while(atual != NULL) {
        printf("\nNOME: %s", atual->valor.nome_produto);
        printf("\nID PRODUTO: %d", atual->valor.id_produto);
        printf("\nVALOR: %.2f R$", atual->valor.preco_produto);
        printf("\nQUANTIDADE DISPONIVEL: %d\n", atual->valor.quantidade_produto);
        atual = atual->proximo;
        }
    printf("\n");
}

Produto pItem;
lista* cabeca = NULL;

void cadastrar_item(){
    int quantidade;
    printf("QUANTOS PRODUTOS DESEJA CADASTRAR: \n");
    scanf("%d", &quantidade);

    for(int i = 0; i < quantidade; i++){
        printf("CADASTRE O ID: \n");
        scanf("%d", &pItem.id_produto);
        printf("NOME DO PRODUTO: \n");
        scanf("%s", &pItem.nome_produto);
        printf("QUANTIDADE: \n");
        scanf("%d", &pItem.quantidade_produto);
        printf("VALOR DO PRODUTO: \n");
        scanf("%f", &pItem.preco_produto);
    }
}

int main(){

    int usuario_op;

    do{

        printf("--------------------\n");
        printf("INVENTARIO\n");
        printf("ESCOLHA A OPCAO DESEJADA:\n");
        printf("(1) - VISUALIZAR ESTOQUE\n");
        printf("(2) - CADASTRAR PRODUTO\n");
        printf("(3) - REMOVER PRODUTO\n");
        printf("(4) - VENDER\n");
        printf("(0) - SAIR\n");
        printf("--------------------\n");
        scanf("%d", &usuario_op);

        switch (usuario_op)
        {
        case 1:
            imprimir_lista(cabeca);
            system("pause");
			system("cls");
            break;
        case 2:
            cadastrar_item();
            break;
        case 3:
            printf("EXCLUIR ITEM\n");
            break;
        case 4:
            printf("VENDER ITEM\n");
            break;
        }
    }while(usuario_op != 0);

}