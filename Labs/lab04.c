#include <stdio.h>
#include <string.h>

#define POPULACAOMAX 1000
#define NOMEMAX 51

int main()
{
    char rawIn[110], nome1[NOMEMAX], nome2[NOMEMAX];
    char *pString, *pNome;

    char populacao[POPULACAOMAX][NOMEMAX];
    int registrados;
    int relacionamentos[POPULACAOMAX][POPULACAOMAX];

    int i, j, score, flagCeleb, flag1, flag2, indexNome1, indexNome2;

    while(*(pString = gets(rawIn)) != NULL) // Não foi apenas '\n'
    {
        /**
         * Extração dos nomes
         */
        pString = strstr(rawIn, "conhece");
        i = 0;
        for(pNome = rawIn; pNome < (pString - 1); pNome++)
        {
            nome1[i++] = *pNome;
        }
        nome1[i] = '\0';

        i = 0;
        for(pNome = pString + 8; *pNome != '\0'; pNome++)
        {
            nome2[i++] = *pNome;
        }
        nome2[i] = '\0';

        printf("Nome 1: '%s'\n", nome1);
        printf("Nome 2: '%s'\n", nome2);

        /**
         * Registro de nomes na matriz
         */

        // Verificação de nome já registrado
        flag1 = 0;
        flag2 = 0;
        for(i = 0; i < registrados; i++)
        {
            printf("populacao[%d]: '%s'\n", i, populacao[i]);
            if((strcmp(populacao[i], nome1)) == 0)
            {
                printf("Nome 1 encontrado!\n");
                flag1 = 1;
                indexNome1 = i;
            }
            if((strcmp(populacao[i], nome2)) == 0)
            {
                printf("Nome 2 encontrado!\n");
                flag2 = 1;
                indexNome2 = i;
            }
        }

        // Registra os nomes não registrados
        if(!flag1)
        {
            indexNome1 = i;
            strcpy(populacao[i++], nome1);
            registrados++;
        }
        if(!flag1)
        {
            indexNome2 = i;
            strcpy(populacao[i], nome2);
            registrados++;
        }
        /**
         * Manipulação da matriz
         */

        // Preenche a diagonal principal com 1 (Conhece si mesmo)
        for(i = 0; i < registrados; i++)
        {
            relacionamentos[i][i] = 1;
        }
        relacionamentos[indexNome1][indexNome2] = 1; // nome1 conhece nome2
    }

    /**
     * Busca de celebridade
     */
    
    score = 0;
    flagCeleb = 1;
    i = 0;
    j = 0;
    while(j < registrados && flagCeleb == 1)
    {
        while(i < registrados && flagCeleb == 1)
        {
            if(relacionamentos[i][j] == 1)
                score += 1;
            else
                flagCeleb = 0;
            i++;
        }
        if(flagCeleb == 1)
            printf("%s e' celebridade", populacao[j]);
        j++;
    }
}