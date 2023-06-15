#include <stdio.h>
#include <stdlib.h>

int main(){

    int tamanho = 5;
    int *numeros = (int*) malloc(tamanho * sizeof(int));

    if(numeros == NULL){
        printf("Falha na alocacao de memoria.\n");
        return 1;
    }

    for(int i = 0; i < tamanho; i++){
        numeros[i] = i + 1;
    }
    for(int i = 0; i < tamanho; i++){
        printf("%d\n", numeros[i]);
    }

    free(numeros);

    return 0;
}