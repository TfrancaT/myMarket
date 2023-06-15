#include <stdio.h>
#include <stdlib.h>

int main(){
    int userOp;
    int *vetor = (int *) malloc(sizeof(int));

    printf("Qual tamanho deseja: \n");
    scanf("%d", &userOp);

    for(int i = 0; i < userOp; i++){
        printf("%d Valor\n", i);
        scanf("%d", &vetor[i]);
    }
    for(int i = 0; i < userOp; i++){
        printf("Seus %d Valor: %d\n", i, vetor[i]);
        printf("Endereco: %x\n", &vetor[i]);
    }
}