#include <stdio.h>

#define INMAX 100

int main()
{
    typedef struct
    {
        int linha, coluna, valor;
    } triplet;
    
    int i, m, n, linhas, linha, coluna, valor;
    char modo, rawIn[INMAX];
    triplet tripla;

    // Criação do vetor que armazenará triplas dos não-nulos de uma matriz m x n
    scanf("%d %d", &m, &n);
    triplet vetor[m+n];

    // Recebimento das triplas
    scanf("%d", &linhas);
    for(i = 0; i < linhas; i++)
    {
        getchar(); // Pega o \n do buffer
        // [a,b] x -> Linha 'a', coluna 'b' tem valor 'x'
        scanf("[%d,%d] %d", &vetor[i].linha, &vetor[i].coluna, &vetor[i].valor);
        printf("linha %d, coluna %d, valor %d\n", vetor[i].linha, vetor[i].coluna, vetor[i].valor);
    }

    /**
     * Modo Interativo
     */

    getchar();
    while(*(fgets(rawIn, INMAX, stdin)) != 't') // Modo 't' finaliza o programa
    {
        if(*rawIn == 'a')
        {
            // Modo 'a'
            printf("Modo A\n");
        }
        else if(*rawIn == 'r')
        {
            // Modo 'r'
            printf("Modo R\n");
        }
        else if(*rawIn == 'p')
        {
            // Modo 'p'
            printf("Modo P\n");
        }
    }

    return 0;
}