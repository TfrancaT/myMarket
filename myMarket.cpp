#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int opcaoFunction;
	
	
	
	do{
		
		printf("_____________");
		printf("myMarket");
		printf("______________");
		printf("\n1- VISUALIZAR ESTOQUE:");
		printf("\n2- ADICIONAR/REMOVER PRODUTO:");
		printf("\n3- VENDAS:");
		printf("\n0- PARA FINALIZAR O PROGRAMA.");
		
		printf("\nSelecione a opcao desejada: ");
		scanf("%d", &opcaoFunction);
		
		system("cls");
		
		switch(opcaoFunction){
			case 1:
				printf("\nVOCE SELECIONOU VISUALIZAR ESTOQUE;\n");
				break;
			case 2:
				printf("\nVOCE SELECIONOU ADICIONAR/REMOVER PRODUTO;\n");
				break;
			case 3:
				printf("\nVOCE SELECIONOU VENDAS;\n");
		}
	}while(opcaoFunction != 0);
}
