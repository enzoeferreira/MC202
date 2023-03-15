#include <stdio.h>

int main()
{
    int i;
    scanf("%d", &i);

    switch(i)
    {
        case 1:
        case 2:
            printf("Igual a 1 ou 2\n");

        case 3:
        case 4:
            printf("Menor que 5\n");
            break;

        case 5:
            printf("Igual a 5\n");
            break;

        default:
            printf("Menor que zero ou maior que 5\n");
    }

    return 0;
}