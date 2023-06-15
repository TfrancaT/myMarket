#include <stdio.h>
#include <stdlib.h>

int somaNum(int x){
    x = x + 10;
    printf("Numero modificado: %d\n", x);
    return(x);
}

void somaPonteiro(int *y){
    *y = *y + 10;
    printf("Soma com ponteiro: %d\n", *y);
    return;
}

int main(){
    int numQualquer;
    printf("Digite um numero: \n");
    scanf("%d", &numQualquer);

    printf("Numero digitado: %d\n", numQualquer);
    somaNum(numQualquer);
    printf("Numero modificado: %d\n", numQualquer);
    somaPonteiro(&numQualquer);
    printf("Agora com ponteiro: \n%d", numQualquer);

// Agora utilizando ponteiro;
    

}