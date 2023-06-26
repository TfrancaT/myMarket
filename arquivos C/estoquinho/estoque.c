#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// estrutura do Item/Produto;
typedef struct {
    int id_item, qt_item;
    float valor_item;
    char nome_item[30];
} Item;

// estrutura da venda do Item/Produto
typedef struct {
    int id_venda, id_item, qt_venda;
    float valor_venda, valor_unidade;
} VendaItem;

// estrutura do noh para a pilha de vendas;
typedef struct noh_pilha {
    VendaItem info;
    struct noh_pilha* seguinte;
} noh_pilha;

// estrutura para ser chamada na criacao do primeiro no da pilha que estara apontando para o topo;
typedef struct {
    noh_pilha* topo;
} Stack;

// funcao para criar o noh para poder ser empilhado posteriormente; a variavel stack estara apontando para o topo;
Stack* createStack(){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->topo = NULL;
    return stack;
}

/*
funcao para verificar se a pilha esta vazia; 
seguindo a logica booleana;
retornara 1 para verdadeiro, ou seja se estiver vazia;
retornara 0 para falso, ou seja se estiver cheia;
*/
int ehVazio(Stack* stack){
    return (stack->topo == NULL);
}

/*
    funcao para "empilhar" os nohs;
    "puxa" a estrutura de noh da pilha criada anteriormente;
*/
void push(Stack* stack, VendaItem info){
    noh_pilha* novo_noh = (noh_pilha*)malloc(sizeof(noh_pilha));
    novo_noh->info = info;
    novo_noh->seguinte = stack->topo;
    stack->topo = NULL;
    return stack;
}

/*
    funcao que retira um no da pilha;
    mostra a venda que foi feita utilizando o noh;
*/
VendaItem pop(Stack* stack){
    if(ehVazio(stack)) {
        printf("Sem itens empilhados.");
        VendaItem vazio;
        vazio.id_venda = -1;
        return vazio;
    }

    noh_pilha* temp = stack->topo;
    VendaItem info = temp->info;
    stack->topo = temp->seguinte;
    free(temp);
    return info;
}

// estrutura do noh para lista de Itens/Produtos;
typedef struct noh_item {
    Item info;
    struct noh_item* seguinte;
} noh_item;


// funcao para criar o noh para listar/cadastrar produtos/itens;
noh_item* criar_noh(Item info){
    noh_item* novo_noh = (noh_item*)malloc(sizeof(noh_item));
    novo_noh->info = info;
    novo_noh->seguinte = NULL;
    return novo_noh;
}

// funcao para criar cada unidade do noh, com o seu elemento e o ponteiro para o proximo;
void inserir_noh(noh_item** cabeca, Item info){
    noh_item* novo_noh = criar_noh(info);
    novo_noh->info = info;
    novo_noh->seguinte = *cabeca;
    *cabeca = novo_noh;
}

// funcao para mostrar/listar os nohs, ou seja para mostrar os itens/produtos que serao cadastrados;
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

/*
    busca um noh especifico;
    utiliza o id passado no parametro da funcao;
    associa ao id do item cadastrado;
*/
noh_item* buscar_nohs(noh_item* head, int id){
    noh_item* atual = head;

    while(atual != NULL){
        if(atual->info.id_item == id){
            return atual;
        }

    atual = atual->seguinte;
    }
}

/*
    funcao para empilhar cada noh que foi utilizado para uma saida/venda;
*/
void vender_itens(Stack* empilhar_vendas, int id_item, int qte, float preco_venda){
    VendaItem venda;
    int cod_venda;
    printf("Informe codigo para Venda: ");
    scanf("%d", &cod_venda);
    venda.id_venda = cod_venda;
    venda.id_item = id_item;
    venda.qt_venda = qte;
    venda.valor_unidade = preco_venda;
    venda.valor_venda = preco_venda * qte;
    push(empilhar_vendas, venda);
}

void mostrar_vendas(Stack* empilhar_vendas){
    if(ehVazio(empilhar_vendas)){
        printf("\nNenhuma venda realizada.");
        return;
    }

    printf("\nVendas: ");
    noh_pilha* vendas_feitas = empilhar_vendas->topo;
    while (vendas_feitas != NULL){
        printf("\nVenda N: %d", vendas_feitas->info.id_venda);
        printf("\nItem N: %d", vendas_feitas->info.id_item);
        printf("\nQuantidade: %d", vendas_feitas->info.qt_venda);
        printf("\nValor Unidade: %f", vendas_feitas->info.valor_unidade);
        printf("\nTotal: %f", vendas_feitas->info.valor_venda);
        vendas_feitas = vendas_feitas->seguinte;
    }
}

// chamando a estrutra do produto/item;
Item novo_item;

// chamando a estrutra do noh;
noh_item *cabeca = NULL;

// funcao para cadastrar o item, esta sendo "consumida" na opcao 2 da condicao 'switch'
cadastro_item();
cadastro_item(){
    int cad_itens;
    printf("\nQuantos produtos deseja cadastrar? ");
    scanf("%d", &cad_itens);
    for(int i = 0; i < cad_itens; i++){
    printf("\n--------------------");
    printf("\nCadastre ID: ");
    scanf("%d", &novo_item.id_item);
        if(novo_item.id_item == novo_item.id_item){
            printf("Codigo ja utilizado.");
        }
    printf("\nNome: ");
    scanf("%s", novo_item.nome_item);
    printf("\nQuantidade: ");
    scanf("%d", &novo_item.qt_item);
    printf("\nValor: ");
    scanf("%f", &novo_item.valor_item);
    inserir_noh(&cabeca, novo_item);
    printf("\n--------------------");
    }
}
venda_item();
venda_item(){
    int cod_produto, quantidade;
                printf("\nVender: ");
                printf("Informe o Id do Item: ");
                scanf("%d", &cod_produto);
                noh_item* venda_produto = buscar_nohs(cabeca, cod_produto);
                if (venda_produto == NULL) {
                    printf("\nProduto Indisponivel.");
                }
                printf("Informe a quantidade: ");
                scanf("%d", &quantidade);
                if (quantidade > venda_produto->info.qt_item) {
                    printf("\nQuantidade indisponivel.");
                }
                vender_itens(venda_produto, cod_produto, quantidade, venda_produto->info.valor_item);
                venda_produto->info.qt_item -= quantidade;
                printf("\nVenda realizada.");
}

int main(){
    int opcao_menu;
    Stack* pilha_vendas = createStack();
        do{
            printf("\nBem-vindo ao Seu Estoque.");
            printf("\n--------------------");
            printf("\nO que deseja fazer? ");
            printf("\nInserir Item: (1);\nVer Estoque: (2);\nVender: (3);\nHistorico de Vendas: (4);\nEncerrar: (0); ");
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
                        venda_item();
                        break;
                    
                    case 4:
                        mostrar_vendas(pilha_vendas);
                        break;
                }
        }while(opcao_menu != 0);

        return 0;
}