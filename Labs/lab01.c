/* Bomba de Combustível
 * 
 * Entrada:
 * Linha contendo um inteiro N 1<=N<=40 (Pressão desejada)
 * Linha contendo um inteiro M 1<=M<=40 (Pressão atual)
 * 
 * Saída:
 * Linha contendo a diferença entre a pressão desejada e atual
 */
#include <stdio.h>

int main()
{
    short int pressaoAtual, pressaoDesejada, pressaoDelta;

    // Recebe as pressões desejadas e atual, respectivamente
    scanf("%d", &pressaoDesejada);
    scanf("%d", &pressaoAtual);

    // Calcula a diferença entre as pressões
    pressaoDelta = pressaoDesejada - pressaoAtual;
    printf("%d", pressaoDelta); // Printa a diferença

    return 0;
}