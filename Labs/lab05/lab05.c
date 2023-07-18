#include <stdio.h>
#include <stdlib.h>

#define INMAX 100

typedef struct
{
    int linha, coluna, valor, status;
} tripla;

int main()
{
    
    int i, m, n, elementos, elementosInvalidos, linha, coluna, valor, encontrado;
    char rawIn[INMAX];

    // Criação do vetor que armazenará triplas dos não-nulos de uma matriz m x n
    scanf("%d %d", &m, &n);
    tripla *triplas, *p;
    triplas = malloc((m+n) * sizeof(tripla));
    if(triplas == NULL)
    {
        return 1;
    }
    
    p = triplas;

    // Recebimento das triplas
    scanf("%d", &elementos);
    for(i = 0; i < elementos; i++)
    {
        getchar(); // Pega o \n do buffer
        // [a,b] x -> Linha 'a', coluna 'b' tem valor 'x'
        scanf("[%d,%d] %d", &p->linha, &p->coluna, &p->valor);
        p->status = 1;
        p++;
    }
    elementosInvalidos = 0;

    // Status 0 no restante dos elementos
    while(i < (m + n))
    {
        p->status = 0;
        p++;
        i++;
    }

    /**
     * Modo Interativo
     */

    getchar();
    while(*(fgets(rawIn, INMAX, stdin)) != 't') // Modo 't' finaliza o programa
    {
        switch(*rawIn)
        {

            case 'a':
            {
                // Modo 'a'
                sscanf(rawIn, "a [%d,%d] %d", &linha, &coluna, &valor);
                i = 0;
                p = triplas;
                encontrado = 0;
                while(((i < m + n) && (i < elementos + elementosInvalidos)) && encontrado == 0)
                {
                    if(p->status && p->linha == linha && p->coluna == coluna)
                    {
                        // Elemento ativo, linhas e coluna iguais (encontrado)
                        encontrado = 1;
                        // printf("\tElemento [%d,%d] encontrado e ", linha, coluna);
                        if(valor)
                        {
                            // Alterar valor
                            // printf("alterado\n");
                            p->valor = valor;
                        }
                        else
                        {
                            // Remover valor
                            // printf("removido / ");
                            p->valor = 0;
                            p->status = 0;
                            elementos--;
                            // printf("E = %d\n", elementos);
                        }
                    }
                    else if(!p->status)// Elemento inativo
                        elementosInvalidos++;
                    p++;
                    i++;
                }

                if(!encontrado && valor != 0)
                {
                    // Elemento novo
                    if(elementos < m + n)
                    {
                        // Há espaço para adicionar
                        p = triplas;
                        for(i = 0; p->status == 1; i++)
                        {
                            p++;
                        }
                        p->linha = linha;
                        p->coluna = coluna;
                        p->valor = valor;
                        p->status = 1;
                        elementos++;
                        // printf("\tElemento [%d,%d] NAO encontrado, adicionado em %d / ", linha, coluna, i);
                        // printf("E = %d\n", elementos);
                    }
                    else
                    {
                        // Não há espaço para adicionar
                        printf("O VC esta' cheio.\n");
                    }
                }
                
                break;
            }

            case 'r':
            {
                // Modo 'r'
                sscanf(rawIn, "r [%d,%d]", &linha, &coluna);
                i = 0;
                p = triplas;
                encontrado = 0;
                while(i <= elementos && encontrado == 0)
                {
                    if(p->status && p->linha == linha && p->coluna == coluna)
                    {
                        // Elemento ativo, linhas e coluna iguais (encontrado)
                        encontrado = 1;
                        // printf("Elemento encontrado!\n");
                        printf("M[%d][%d] == %d\n", linha, coluna, p->valor);
                    }
                    p++;
                    i++;
                }

                if(!encontrado)
                {
                    // Elemento nulo
                    printf("M[%d][%d] == 0\n", linha, coluna);
                }

                break;
            }

            case 'p':
            {
                // Modo 'p'
                if(elementos > 0)
                {
                    printf("VC: ");
                    for(linha = 0; linha <= m; linha++)
                    {
                        for(coluna = 0; coluna <= n; coluna++)
                        {
                            i = 0;
                            p = triplas;
                            encontrado = 0;
                            while(i < elementos && encontrado == 0)
                            {
                                if(p->status &&
                                   p->linha == linha && p->coluna == coluna &&
                                   p->valor)
                                {
                                    // Elemento ativo, linha e coluna certa
                                    printf("(%d,%d,%d) ", p->linha,
                                                          p->coluna,
                                                          p->valor);
                                    encontrado = 1;
                                }
                                p++;
                                i++;
                            }
                        }
                    }
                    printf("\n");
                }
                else
                {
                    printf("O VC esta' vazio.\n");
                }

                break;
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

    // for(i = 0; i < elementos; i++)
    // {
    //     printf("%d(%d,%d,%d)%d ", i, vetor[i].linha, vetor[i].coluna, vetor[i].valor, vetor[i].status);
    // }

    // printf("E = %d\n", elementos);

    free(triplas);
    return 0;
}