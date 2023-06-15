#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int idProduto;
    int quantProdutod;
    char nomeProduto[30];
    float precoProduto;
} Produtos;

typedef struct nohProduto {
    int value;
    struct nohProdut *next;
} nohProduto;