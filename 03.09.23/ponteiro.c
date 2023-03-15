#include <stdio.h>

int main()
{
    int i;
    int *pi;
    int **ppi;

    i = 10;
    pi = &i;
    ppi = &pi;

    printf("Valor de i: %d\n", i);
    printf("Endereco de i: %p\n", &i);
    
    printf("Valor de i via pi: %d\n", *pi);
    printf("Valor de pi: %d\n", pi);
    printf("Endereço de pi: %p\n", &pi);

    printf("Valor de i via ppi: %d\n", **ppi);
    printf("Valor de ppi: %d\n", ppi);
    printf("Endereço de ppi: %p\n", &ppi);

    printf("Pressiona ENTER para continuar...");
    getchar();
    
    return 0;
}