#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "spotify.h"

int main(void)
{
    int i = 0, operations;
    char cmd[MAXCMD];

    scanf("%d", &operations);

    while(operations)
    {
        playlist* P = playlist_create();
        while(i < operations)
        {
            scanf("%s", cmd); // Pega a operação da entrada

            if (strcmp(cmd, "insere") == 0)
            {
                getchar(); // Pega o espaço
                song_add(P);
            }

            else if (strcmp(cmd, "remove") == 0)
            {
                getchar(); // Pega o espaço
                song_remove(P);
            }

            else if (strcmp(cmd, "toca") == 0)
                toca(P);
            else if (strcmp(cmd, "volta") == 0)
                volta(P);
            else if (strcmp(cmd, "final") == 0)
                final(P);
            else if (strcmp(cmd, "inverte") == 0)
                inverte(P);
            
            i++;
        }

        playlist_delete(P); // Deleta playlist antiga
        scanf("%d", &operations); // Recebe um novo número de operações
        if(operations)
            printf("\n"); // Haverá uma prox. playlist
        i = 0;
    }
}