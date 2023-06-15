#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nomeProd[50];
	int codigoProd[50], quantProd[50];
	float precoProd[50];
} Produtos;

int main(){
	
	int opcaoFunction, vezesMostrar;
	char voltarMenu[30];
	char maisProd[30];
	
	Produtos meusProdutos;
	
	do{
		
		printf("\n_____________\n");
		printf("\nmyMarket\n");
		printf("\n______________\n");
		printf("\n1- VISUALIZAR ESTOQUE: \n");
		printf("\n2- ADICIONAR/REMOVER PRODUTO: \n");
		printf("\n3- VENDAS: \n");
		printf("\n0- PARA FINALIZAR O PROGRAMA. \n");
		
		printf("\nSELECIONE A OPCAO DESEJADA: \n");
		scanf("%d", &opcaoFunction);
		
		switch(opcaoFunction){
			//OP��O PARA VISUALIZAR ITENS CADASTRADOS EM ESTOQUE;
			case 1:
				do{
					printf("\nVOCE SELECIONOU VISUALIZAR ESTOQUE;\n");				
					printf("\nPRODUTO: %s\n", meusProdutos.nomeProd);
					printf("\nCODIGO DO PRODUTO: %d\n", meusProdutos.codigoProd);
					printf("\nPRECO: %.2f\n", meusProdutos.precoProd);
					printf("\nQUANTIDADE: %d\n", meusProdutos.quantProd);	

					printf("\nDIGITE SAIR PARA VOLTAR AO MENU PRINCIPAL: \n");
					scanf("%s", &voltarMenu);
				}while(voltarMenu == "sair" || voltarMenu == "SAIR");
				break;
				
			//OP��O PARA ADICIONAR PRODUTOS EM ESTOQUE;	
			case 2:
				printf("\nVOCE SELECIONOU ADICIONAR/REMOVER PRODUTO;\n");
				
				do{
				vezesMostrar++;
				
				printf("\nDIGITE NOME DO PRODUTO: ");
				scanf("%s", &meusProdutos.nomeProd);
				printf("\nCODIGO DO PRODUTO: ");
				scanf("%d", &meusProdutos.codigoProd);
				printf("\nPRECO DO PRODUTO: ");
				scanf("%f", &meusProdutos.precoProd);
				printf("\nQUANTIDADE DO PRODUTO: ");
				scanf("%d", &meusProdutos.quantProd);
				printf("\nDESEJA CADASTRAR MAIS PRODUTOS? \n");
				printf("\nSIM\n");
				printf("\nNAO\n");
				scanf("%s", &maisProd);
				}while(maisProd == "SIM" || maisProd == "sim");			
				break;
				
			//OPCAO DE VENDAS, MOSTRAR QUANTIDADE DOS ITENS DISPONIVEIS EM ESTOQUE;
			case 3:
				printf("\nVOCE SELECIONOU VENDAS;\n");
				break;
		}
	}while(opcaoFunction != 0);
}
