#include <stdio.h>
#include <string.h>

int main()
{
    char rawIn[110], nome1[51], nome2[51];
    char populacao[1000];
    short int relacionamentos[1000][1000];
    short int nomesAdicionados;

    scanf(" %[^\n]s", rawIn); // Recebe a entrada
    // printf("'%s'", rawIn);

    char *pcEnd, *pcStart;
    pcEnd = strstr(rawIn, "conhece"); // Seta o ponteiro final

    // Extração do Nome 1
    short int i = 0;
    for(pcStart = rawIn; pcStart < (pcEnd - 1); pcStart++)
    {
        // Percorre do inicio de rawIn até 2 antes de "conhece" (ultima letra)
        nome1[i++] = *pcStart;
    }
    nome1[i] = '\0'; // Adiciona o '\0' no fim da cadeia

    // Extração do Nome 2
    i = 0;
    for(pcStart = pcEnd + 8; *pcStart != '\0'; pcStart++)
    {
        // Percorre depois do "conhece" até o fim da cadeia
        nome2[i++] = *pcStart;
    }
    nome2[i] = '\0'; // Adiciona o '\0' no fim da cadeia
}