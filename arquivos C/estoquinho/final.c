#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void assinatura();
// criando a estrutura produto
typedef struct {
    int cod;
    char nomeProd[50];
    float preco;
    int quant;
} Produto;

// criando a estrutura venda
typedef struct {
    int codVenda;
    int codProduto;
    int quantVenda;
    float valorVendaUnitario;
    float valorVenda;
} Venda;

// n� da pilha VendaNode, que cont�m uma venda e um ponteiro para o pr�ximo n� da pilha.
typedef struct VendaNode {
    Venda venda;
    struct VendaNode* next;
} VendaNode;

//  n� da lista encadeada Node, que cont�m um produto e um ponteiro para o pr�ximo n� da lista.
typedef struct Node {
    Produto data;
    struct Node* next;
} Node;

// defini��o da pilha Stack, que possui apenas um ponteiro para o topo da pilha.
typedef struct {
    VendaNode* top;
} Stack;

// fun��o createStack() cria uma nova pilha e retorna seu ponteiro. Ela aloca mem�ria para a estrutura Stack e inicializa o topo como NULL.
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}
//  fun��o isEmpty() verifica se a pilha est� vazia. Ela retorna 1 se o topo da pilha for NULL (ou seja, a pilha est� vazia) e retorna 0 caso contr�rio.
int isEmpty(Stack* stack) {
    return (stack->top == NULL);
}

// fun��o push() adiciona um novo n� (com a venda fornecida) no topo da pilha. Ela aloca mem�ria para o novo n�, atribui os valores da venda e atualiza o ponteiro do topo para o novo n�.
void push(Stack* stack, Venda data) {
    VendaNode* newNode = (VendaNode*)malloc(sizeof(VendaNode));
    newNode->venda = data;
    newNode->next = stack->top;
    stack->top = newNode;
}
//  fun��o pop() remove o n� do topo da pilha e retorna a venda associada a ele. Se a pilha estiver vazia, ela exibe uma mensagem de erro e retorna uma venda vazia com o c�digo de venda igual a -1.
Venda pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("A pilha est� vazia!\n");
        Venda vazio;
        vazio.codVenda = -1;
        return vazio;
    }

    VendaNode* temp = stack->top;
    // o dado que ele retirou da pilha
    Venda data = temp->venda;
    //Proximo vai ser o topo
    stack->top = temp->next;
    // limpar
    free(temp);
     //retornando o dado que eu desempilhei
    return data;
}
// fun��o createNode() cria um novo n� da lista encadeada com o produto fornecido. Ela aloca mem�ria para o novo n�, atribui os valores do produto e define o pr�ximo como NULL.
Node* createNode(Produto data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// fun��o insertAtBeginning() insere um novo n� no in�cio da lista encadeada. Ela cria um novo n� com o produto fornecido, atualiza o pr�ximo para o n� anteriormente no in�cio da lista e atualiza a cabe�a da lista para o novo n�.
void insertAtBeginning(Node** head, Produto data) {
    //usando a fun��o createNode para criar um novo n�
    Node* newNode = createNode(data);
    //como ele vai ser o novo n� ele deve pegar o ender�o do antigo n�
    newNode->next = *head;
    //alterando o endere�o da nova cabe�a
    *head = newNode;
}
//fun��o search() busca um n� com o c�digo fornecido na lista encadeada. Ela percorre a lista at� encontrar um n� com o c�digo correspondente ou at� o final da lista. Se encontrar, retorna o n� correspondente; caso contr�rio, retorna NULL.

Node* search(Node* head, int cod) {
    Node* current = head;

    while (current != NULL) {
        if (current->data.cod == cod) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}
// fun��o displayList() exibe os produtos presentes na lista encadeada. Ela percorre a lista, exibindo o c�digo, nome, pre�o e quantidade de cada produto. Se a lista estiver vazia, exibe uma mensagem informando isso.

void displayList(Node* head) {
    Node* current = head;

    if (current == NULL) {
        printf("A lista est� vazia.\n");
        return;
    }

    printf("\nPRODUTOS DO ESTOQUE:\n");

    while (current != NULL) {
        printf("\nC�digo: %d", current->data.cod);
        printf("\nNome: %s", current->data.nomeProd);
        printf("\nPre�o: %.2f", current->data.preco);
        printf("\nQuantidade: %d\n", current->data.quant);
        current = current->next;
    }

    printf("\n");
}
// fun��o adicionarVenda() adiciona uma nova venda � pilha de vendas. Ela solicita ao usu�rio o c�digo da venda, cria uma venda com os valores fornecidos e calcula o valor total da venda. Em seguida, chama a fun��o push() para adicionar a venda � pilha.

void adicionarVenda(Stack* pilha_vendas, int codProduto, int quantidade, float precoVenda) {
    Venda venda;
    int codigoVenda;
    printf("Digite o c�digo da venda: ");
    scanf("%d", &codigoVenda);
    venda.codVenda = codigoVenda;
    venda.codProduto = codProduto;
    venda.quantVenda = quantidade;
    venda.valorVendaUnitario = precoVenda;
    venda.valorVenda = precoVenda * quantidade;

    push(pilha_vendas, venda);
}
// fun��o cancelarVenda() permite cancelar uma venda espec�fica, informando o c�digo da venda a ser cancelada.

void cancelarVenda(Stack* pilha_vendas, Node* estoque) {
    if (isEmpty(pilha_vendas)) {
        printf("\n---- NENHUMA VENDA PARA CANCELAR ----\n"); // Verifica se a pilha de vendas est� vazia
        return;
    }

    int codVenda;
    printf("Digite o c�digo da venda que deseja cancelar: ");
    scanf("%d", &codVenda);

    Venda vendaAtual;
    Node* produto;

    do {
        vendaAtual = pop(pilha_vendas);

        if (vendaAtual.codVenda == -1) {
            printf("\n---- VENDA N�O ENCONTRADA ----\n");
            return;
        }

        if (vendaAtual.codVenda == codVenda) {
            produto = search(estoque, vendaAtual.codProduto);
            if (produto != NULL) {
                produto->data.quant += vendaAtual.quantVenda;
            }
            printf("\n---- VENDA CANCELADA COM SUCESSO ----\n");
            return;
        }
    } while (!isEmpty(pilha_vendas));
}
//  fun��o exibirVendas() exibe as vendas realizadas, percorrendo a pilha de vendas. Ela utiliza uma pilha tempor�ria para preservar a ordem original das vendas. A cada venda retirada da pilha de vendas, exibe suas informa��es (c�digo da venda, c�digo do produto, quantidade vendida, valor unit�rio e valor total). Em seguida, as vendas s�o restauradas na pilha original.

void exibirVendas(Stack* pilha_vendas) {
    if (isEmpty(pilha_vendas)) {
        printf("\n---- NENHUMA VENDA EFETUADA ----\n");
        return;
    }

    printf("\nVENDAS REALIZADAS:\n");

    VendaNode* vendaAtual = pilha_vendas->top;

    while (vendaAtual != NULL) {
        printf("\nC�digo da Venda: %d", vendaAtual->venda.codVenda);
        printf("\nC�digo do Produto: %d", vendaAtual->venda.codProduto);
        printf("\nQuantidade: %d", vendaAtual->venda.quantVenda);
        printf("\nValor Unit�rio: %.2f", vendaAtual->venda.valorVendaUnitario);
        printf("\nValor Total: %.2f\n", vendaAtual->venda.valorVenda);
        vendaAtual = vendaAtual->next;
    }

    printf("\n");
}

void menu() {
    printf("\n-------- BEM VINDO AO MERCADO VAREJ�O DAS QUENGA --------\n");
    printf("\n1 - Cadastrar produto no estoque.");
    printf("\n2 - Listagem de produtos.");
    printf("\n3 - Efetuar venda.");
    printf("\n4 - Exibir vendas realizadas.");
    printf("\n5 - Cancelar venda.");
    printf("\n0 - Para sair.");
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    Node* estoque = NULL;
    Stack* pilha_vendas = createStack();
    Produto produto;
    int escolha, mais;
    while (1) {
        menu();
        printf("\nInforme a op��o desejada: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 0:
                printf("\n------------ LOJA FECHADA ------------\n");
                assinatura();
                return 0;
            case 1:
                printf("\n---- CADASTRAR PRODUTO ----\n");
                printf("\nDigite o c�digo do produto: ");
                scanf("%d", &produto.cod);
                printf("Digite o nome do produto: ");
                scanf("%s", produto.nomeProd);
                printf("Digite o pre�o do produto: ");
                scanf("%f", &produto.preco);
                printf("Digite a quantidade do produto: ");
                scanf("%d", &produto.quant);
                insertAtBeginning(&estoque, produto);
                system("cls");
                printf("\n---------- PRODUTO CADASTRADO COM SUCESSO ----------\n");
                printf("Deseja adicionar outro produto?\n1- SIM\n2- N�O\n");
                printf("Informe sua op��o:");
                scanf("%d", &mais);
                while(mais == 1){
                if (mais == 1){
                    printf("\n---- CADASTRAR PRODUTO ----\n");
                    printf("\nInforme o c�digo do produto: ");
                    scanf("%d", &produto.cod);
                    printf("Informe o nome do produto: ");
                    scanf(" %s", produto.nomeProd);
                    printf("Informe o pre�o do produto: ");
                    scanf("%f", &produto.preco);
                    printf("Informe a quantidade do produto: ");
                    scanf("%d", &produto.quant);
                    insertAtBeginning(&estoque, produto);
                    system("cls");
                    printf("\n\n------------ PRODUTO CADASTRADO COM SUCESSO!!! ------------\n");
                    printf("Deseja adicionar outro produto?\n1- SIM\n2- N�O\n");
                    printf("Informe sua op��o:");
                    scanf("%d", &mais);
                }else{
                    menu();
                    printf("\nInforme o que deseja fazer: ");
                    scanf("%d", &escolha);
                }
            }
                break;
            case 2:
                displayList(estoque);
                break;
            case 3: {
                int codProduto, quantidade;
                printf("\n---- EFETUAR VENDA ----\n");
                printf("Digite o c�digo do produto: ");
                scanf("%d", &codProduto);
                Node* produtoVenda = search(estoque, codProduto);
                if (produtoVenda == NULL) {
                    printf("\n---- PRODUTO N�O ENCONTRADO NO ESTOQUE ----\n");
                    break;
                }
                printf("Digite a quantidade a ser vendida: ");
                scanf("%d", &quantidade);
                if (quantidade > produtoVenda->data.quant) {
                    printf("\n---- QUANTIDADE SOLICITADA INDISPON�VEL NO ESTOQUE ----\n");
                    break;
                }
                adicionarVenda(pilha_vendas, codProduto, quantidade, produtoVenda->data.preco);
                produtoVenda->data.quant -= quantidade;
                printf("\n---- VENDA REALIZADA COM SUCESSO ----\n");
                break;
            }
            case 4:
                exibirVendas(pilha_vendas);
                break;
            case 5:
                cancelarVenda(pilha_vendas, estoque);
                break;
            default:
                printf("\n---- OP��O INV�LIDA. TENTE NOVAMENTE ----\n");
                break;
        }
    }

    return 0;
}
void assinatura(){
printf("\n               ^!.            ");
printf("\n             .P@@#:           ");
printf("\n             G@&5BP           ");
printf("\n            !@G. :#:          ");
printf("\n            J@:  7&:          ");
printf("\n            !B  7@B           ");
printf("\n            .P!P@@7           ");
printf("\n            ~#@@@?            ");
printf("\n          ~P@@@G~             ");
printf("\n        :5@@@PG:              ");
printf("\n       ~&@&Y: 7J              ");
printf("\n      ^&@P:  !5&B#GY^         ");
printf("\n      Y@P  ^B@#BB5#@@Y        ");
printf("\n      J@7  P@J ^P  ?@@!       ");
printf("\n      .#5  7@!  P!  G@7       ");
printf("\n       ^GY: ^?^ !P ~&P.       ");
printf("\n         7YJ7~~~!#557         ");
printf("\n           .^~~~^55           ");
printf("\n            .    ^B.          ");
printf("\n          ?B#B!   B~          ");
printf("\n         :@@@@J  .#^          ");
printf("\n          !G#?^~7P?           ");
printf("\n            :~!!~.            ");
}
