#include <stdio.h>

#define INMAX 100

int main()
{
    typedef struct
    {
        int linha, coluna, valor, status;
    } triplet;
    
    int i, m, n, elementos, elementosInvalidos, linha, coluna, valor, encontrado;
    char rawIn[INMAX];

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
        vetor[i].status = 1;
    }
    elementosInvalidos = 0;

    /**
     * Modo Interativo
     */

    getchar();
    while(*(fgets(rawIn, INMAX, stdin)) != 't') // Modo 't' finaliza o programa
    {
        if(*rawIn == 'a')
        {
            // Modo 'a'
            sscanf(rawIn, "a [%d,%d] %d", &linha, &coluna, &valor);
            i = 0;
            encontrado = 0;
            while(((i < m + n) && (i < elementos + elementosInvalidos)) && encontrado == 0)
            {
                if(vetor[i].status && vetor[i].linha == linha && vetor[i].coluna == coluna)
                {
                    // Elemento ativo, linhas e coluna iguais (encontrado)
                    encontrado = 1;
                    // printf("\tElemento [%d,%d] encontrado e ", linha, coluna);
                    if(valor)
                    {
                        // Alterar valor
                        // printf("alterado\n");
                        vetor[i].valor = valor;
                    }
                    else
                    {
                        // Remover valor
                        // printf("removido / ");
                        vetor[i].valor = 0;
                        vetor[i].status = 0;
                        elementos--;
                        // printf("E = %d\n", elementos);
                    }
                }
                else if(!vetor[i].status)// Elemento inativo
                    elementosInvalidos++;
                i++;
            }

            if(!encontrado && valor != 0)
            {
                // Elemento novo
                if(elementos < m + n)
                {
                    // Há espaço para adicionar
                    for(i = 0; vetor[i].status == 1; i++) {}
                    vetor[i].linha = linha;
                    vetor[i].coluna = coluna;
                    vetor[i].valor = valor;
                    vetor[i].status = 1;
                    elementos++;
                    // printf("\tElemento NAO encontrado, adicionado / ");
                    // printf("E = %d\n", elementos);
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
            sscanf(rawIn, "r [%d,%d]", &linha, &coluna);
            i = 0;
            encontrado = 0;
            while(i <= elementos && encontrado == 0)
            {
                if(vetor[i].status && vetor[i].linha == linha && vetor[i].coluna == coluna)
                {
                    // Elemento ativo, linhas e coluna iguais (encontrado)
                    encontrado = 1;
                    // printf("Elemento encontrado!\n");
                    printf("M[%d][%d] == %d\n", linha, coluna, vetor[i].valor);
                }
                i++;
            }

            if(!encontrado)
            {
                // Elemento nulo
                printf("M[%d][%d] == 0\n", linha, coluna);
            }
        }
        else if(*rawIn == 'p')
        {
            // Modo 'p'
            if(elementos > 0)
            {
                printf("VC: ");
                for(linha = 0; linha <= m; linha++)
                {
                    for(coluna = 0; coluna <= n; coluna++)
                    {
                        for(i = 0; i <= elementos; i++)
                        {
                            if(vetor[i].status &&
                               vetor[i].linha == linha && vetor[i].coluna == coluna &&
                               vetor[i].valor)
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
    // while(*(fgets(rawIn, INMAX, stdin)) != 't')
    // {
    //     i = 0;
    //     sscanf(rawIn, "r [%d, %d]", &linha, &coluna);
    //     while(1)
    //     {
    //         if(vetor[i].linha == linha && vetor[i].coluna == coluna)
    //         {
    //             printf("%d(%d,%d,%d)%d\n", i, vetor[i].linha, vetor[i].coluna, vetor[i].valor, vetor[i].status);
    //             break;
    //         }
    //         i++;
    //     }
    // }

    // for(i = 0; i <= elementos; i++)
    // {
    //     printf("%d(%d,%d,%d)%d ", i, vetor[i].linha, vetor[i].coluna, vetor[i].valor, vetor[i].status);
    // }

    // printf("E = %d\n", elementos);

    return 0;
}