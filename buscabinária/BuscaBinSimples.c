#include <stdio.h>
#include <stdlib.h>
#include "buscabin.h"

int main ()
{

    int vet[]={3,4,5,6,7,8,9,13,17};
    int tam = sizeof(vet)/sizeof(int);

    printf("%d \n", buscabinaria(tam, vet, 5));
    return 0;

}