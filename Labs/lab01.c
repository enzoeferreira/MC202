#include <stdio.h>

int main()
{
    int pressaoAtual, pressaoDesejada, pressaoDelta;

    // Recebe as pressões desejadas e atual, respectivamente
    scanf("%d", &pressaoDesejada);
    scanf("%d", &pressaoAtual);

    // Calcula a diferença entre as pressões
    pressaoDelta = pressaoDesejada - pressaoAtual;
    printf("%d", pressaoDelta); // Printa a diferença

    return 0;
}