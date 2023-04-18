#include <stdio.h>

#define INMAX 100

int main()
{
    typedef struct
    {
        int linha, coluna, valor, status;
    } triplet;
    
    int i, j, v, m, n, elementos, linha, coluna, valor, encontrado;
    char modo, rawIn[INMAX];
    triplet tripla;

    // Criação do vetor que armazenará triplas dos não-nulos de uma matriz m x n
    scanf("%d %d", &m, &n);
    triplet vetor[m+n];

    // Recebimento das triplas
    scanf("%d", &elementos);
    for(i = 0; i < elementos; i++)
    {
        getchar(); // Pega o \n do buffer
        // [a,b] x -> Linha 'a', coluna 'b' tem valor 'x'
        scanf("[%d,%d] %d", &vetor[i].linha, &vetor[i].coluna, &vetor[i].valor);
        // printf("linha %d, coluna %d, valor %d\n", vetor[i].linha, vetor[i].coluna, vetor[i].valor);
        vetor[i].status = 1;
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
            i = 0;
            encontrado = 0;
            while(i < elementos && encontrado == 0)
            {
                if(vetor[i].status == 1)
                {
                    // Elemento ativo
                    if(vetor[i].linha == (int)(*(rawIn + 3) - '0')) // - '0' para fazer char -> int
                    {
                        // Linha igual
                        if(vetor[i].coluna == (int)(*(rawIn + 5) - '0'))
                        {
                            // Elemento encontrado (Linha e coluna igual)
                            encontrado = 1;
                            printf("Elemento encontrado e ");
                            if(*(rawIn + 8) - '0')
                            {
                                // Alterar valor
                                printf("alterado\n");
                                vetor[i].valor = (int)(*(rawIn + 8) - '0');
                            }
                            else
                            {
                                // Remover valor
                                printf("removido\n");
                                vetor[i].valor = 0;
                                vetor[i].status = 0;
                                elementos--;
                            }
                        }
                    }
                }
                i++;
            }

            if(!encontrado)
            {
                // Elemento novo
                if(elementos < m + n)
                {
                    // Há espaço para adicionar
                    for(i = 0; vetor[i].status == 1; i++) {}
                    vetor[i].linha = (int)(*(rawIn + 3) - '0');
                    vetor[i].coluna = (int)(*(rawIn + 5) - '0');
                    vetor[i].valor = (int)(*(rawIn + 8) - '0');
                    vetor[i].status = 1;
                    elementos++;
                }
                else
                {
                    // Não há espaço para adicionar
                    printf("O VC esta' cheio.\n");
                }
            }
        }
        else if(*rawIn == 'r')
        {
            // Modo 'r'
            i = 0;
            encontrado = 0;
            while(i < elementos && encontrado == 0)
            {
                if(vetor[i].status == 1)
                {
                    // Elemento ativo
                    if(vetor[i].linha == (int)(*(rawIn + 3) - '0')) // - '0' para fazer char -> int
                    {
                        // Linha igual
                        if(vetor[i].coluna == (int)(*(rawIn + 5) - '0'))
                        {
                            // Elemento encontrado (Linha e coluna igual)
                            encontrado = 1;
                            printf("Elemento encontrado!\n");
                            printf("M[%d][%d] == %d\n",
                                    vetor[i].linha, vetor[i].coluna, vetor[i].valor);
                        }
                    }
                }
                i++;
            }

            if(!encontrado)
            {
                // Elemento nulo
                printf("M[%d][%d] == 0\n", (int)(*(rawIn + 3) - '0'), (int)(*(rawIn + 5) - '0'));
            }
        }
        else if(*rawIn == 'p')
        {
            // Modo 'p'
            if(elementos > 0)
            {
                printf("VC: ");
                for(linha = 0; linha < m; linha++)
                {
                    for(coluna = 0; coluna < n; coluna++)
                    {
                        for(i = 0; i < elementos; i++)
                        {
                            if(vetor[i].status &&
                                vetor[i].linha == linha && vetor[i].coluna == coluna)
                            {
                                // Elemento ativo, linha e coluna certa
                                printf("(%d,%d,%d) ", vetor[i].linha,
                                                        vetor[i].coluna,
                                                        vetor[i].valor);
                            }
                        }
                    }
                }
                printf("\n");
            }
            else
            {
                printf("O VC esta' vazio.\n");
            }
        }
    }

    return 0;
}