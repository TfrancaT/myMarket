#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int matricula;
    float nota;
} Pessoa;

int main(){
    Pessoa p1;
    p1.matricula = 777;
    p1.nota = 7.7;

    Pessoa *ptr1 = &p1;

    printf("Matricula: %d\n", p1.matricula);
    printf("Nota: %.2f\n", p1.nota);
    (*ptr1).nota = 9.7;
    printf("Nova nota: %f\n", (*ptr1).nota);
    //Segunda forma de uso do ponteiro com struct;
    ptr1->nota = 6.6;
    printf("Novamente: %.2f\n", ptr1->nota);
    printf("Verificando alteracao: %.2f\n", p1.nota);
    

}