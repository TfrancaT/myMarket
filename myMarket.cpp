#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int opcaoFunction;
	
	char nomeProd[50];
	int i, codigoProd, quantProd;
	float precoProd;
	
	int maisProd;
	char voltarMenu[30];
	
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
		
		system("cls");
		
		switch(opcaoFunction){
			case 1:
				do{
				printf("\nVOCE SELECIONOU VISUALIZAR ESTOQUE;\n");				
				printf("\nPRODUTO: %s\n", nomeProd);
				printf("\nCODIGO DO PRODUTO: %d\n", codigoProd);
				printf("\nPRECO: %.2f\n", precoProd);
				printf("\nQUANTIDADE: %d\n", quantProd);
				printf("\nDIGITE SAIR PARA VOLTAR AO MENU PRINCIPAL: \n");
				scanf("%s", &voltarMenu);
				}while(voltarMenu == "Sair" || voltarMenu == "SAIR");
				break;
				
			case 2:
				printf("\nVOCE SELECIONOU ADICIONAR/REMOVER PRODUTO;\n");
				
				do{
				printf("\nDIGITE NOME DO PRODUTO: ");
				scanf("%s", &nomeProd);
				printf("\nCODIGO DO PRODUTO: ");
				scanf("%d", &codigoProd);
				printf("\nPRECO DO PRODUTO: ");
				scanf("%f", &precoProd);
				printf("\nQUANTIDADE DO PRODUTO: ");
				scanf("%d", &quantProd);
				
				printf("\nDESEJA CADASTRAR MAIS PRODUTOS? \n");
				printf("\n1- SIM \n 2- NAO ");
				scanf("%d", &maisProd);
				}while(maisProd == 1);			
				break;
				
			case 3:
				printf("\nVOCE SELECIONOU VENDAS;\n");
				break;
		}
	}while(opcaoFunction != 0);
}
