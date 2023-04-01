#include <stdio.h>
#include <string.h>

#define POPULACAOMAX 1000
#define NOMEMAX 51

int main()
{
    char rawIn[110], nome1[NOMEMAX], nome2[NOMEMAX];
    char *pString, *pNome;

    char populacao[POPULACAOMAX][NOMEMAX];
    int registrados = 0;
    int relacionamentos[POPULACAOMAX][2]; // [Conhecido, Conhece]

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
         * Registro de nomes no vetor
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
            relacionamentos[indexNome1][0] = 1; // Se conhece
            relacionamentos[indexNome1][1] = 1; // Conhece nome2 
            strcpy(populacao[i++], nome1); // Insere o nome
            registrados++;
        }
        if(!flag2)
        {
            indexNome2 = i;
            relacionamentos[indexNome2][0] = 1; // Se conhece 
            strcpy(populacao[i], nome2); // Insere o nome
            registrados++;
        }

        // nome2 é conhecido por nome1
        relacionamentos[indexNome2][0] += 1;
    }

    /**
     * Busca de celebridade
     */
    
    score = 0;
    flagCeleb = 1;
    i = 0;
    while(i < registrados)
    {
        if(relacionamentos[i][0] == registrados)
            // É conhecido por todos
            if(relacionamentos[i][1] == 0)
                // Não conhece ninguem
                printf("%s e' celebridade.", populacao[i]);
                if(flagCeleb == 1)
                    // Celebridade não tinha sido encontrada até agora
                    flagCeleb = 0;
        i++;
    }
    if(flagCeleb)
        // Nenhuma celebridade
        printf("Nao ha' celebridade.");
}