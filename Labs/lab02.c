#include <stdio.h>

int main()
{
    int vidaRyu, vidaKen, dano;
    int golpesRyu = 0, golpesKen = 0;

    // Recebe os valores inicias de vida de Ryu e Ken, respectivamente
    scanf("%d", &vidaRyu);
    scanf("%d", &vidaKen);


    while(vidaRyu > 0 && vidaKen > 0) // Ambos estão vivos
    {
        scanf("%d", &dano); // Recebe a qnt de dano

        if(dano > 0)
        {
            // Golpe do Ryu
            vidaKen -= dano;
            printf("RYU APLICOU UM GOLPE: %d\n", dano);
            golpesRyu++;
        }
        else
            {
                // Golpe do Ken
                vidaRyu -= dano*(-1);
                printf("KEN APLICOU UM GOLPE: %d\n", dano*(-1));
                golpesKen++;
            }
        
        // Reajuste caso dano > vida
        if(vidaRyu < 0)
            vidaRyu = 0;
        if(vidaKen < 0)
            vidaKen = 0;

        // Print com a vida restante de ambos
        printf("HP RYU = %d\n", vidaRyu);
        printf("HP KEN = %d\n", vidaKen);
    }
    
    if(vidaRyu <= 0)
    {
        // Ryu morreu
        printf("LUTADOR VENCEDOR: KEN\n");
    }
        else
        {
            // Ken morreu
            printf("LUTADOR VENCEDOR: RYU\n");
        }
    
    // Print com a qnt de golpes de cada
    printf("GOLPES RYU = %d\n", golpesRyu);
    printf("GOLPES KEN = %d\n", golpesKen);
    
    return 0;
}