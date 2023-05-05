#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #include "spotify.h"

/**
 * HEADER
 */
#define MAXCMD 108
#define MAXNAME 102

struct song
{
    char* name;
    struct song *next, *prev;
};
typedef struct song song;

struct playlist
{
    song *head;
    song *tail;
    song *pos;
};
typedef struct playlist playlist;

/**
 * LIBRARY
 */

/**
 * Cria uma playlist com dummys no inicio e fim, pos começa no inicio
 * 
 * @return 1) 0, em caso de falha de alocação de espaço para playlist
 * @return 2) P, onde P é um apontador para playlist
 */
playlist* playlist_create()
{
    playlist* P = malloc(sizeof(playlist));
    if(!P)
        return NULL; 
    song* m = malloc(sizeof(song));
    if(!m)
        return NULL;
    P->head = m;

    song* n = malloc(sizeof(song));
    if(!n)
        return NULL;
    P->tail = n;

    P->pos = P->head;
    P->head->prev = NULL;
    P->head->next = P->tail;
    P->tail->prev = P->head;
    P->tail->next = NULL;

    return P;
}

/**
 * Adiciona uma música na playlist após a posição atual
 * Caso a playlist esteja vazia, a música é inserida na primeira posição
 * Uma música pode aparecer na playlist mais de uma vez
 * 
 * @param P playlist
 * 
 * @return 1) 0, caso não seja possível alocar memória para a música
 * @return 2) 1, caso a música tenha sido adicionada na playlist
 */
int song_add(playlist* P)
{
    song *n = (song*) malloc(sizeof(song));
    if(!n)
    {
        printf("\tFALHA AO ADICIONAR MUSICA\n");
        return 0; // Alocação falhou
    }

    fgets(n->name, MAXNAME, stdin); // Recebe o nome da música

    char *cleaner = strchr(n->name, '\n'); // Ponteiro cleaner aponta para \n
    *cleaner = '\0'; // Substitui '\n' por '\0'

    n->prev = P->pos;
    n->next = P->pos->next;
    P->pos->next->prev = n;
    P->pos->next = n;
    return 1;
}

void print(playlist* P)
{
    song *n = P->head->next;
    printf("PLAYLIST:");
    while(n != P->tail)
    {
        printf(" %s,", n->name);
        n = n->next;
    }
    printf("\n");
}

/**
 * MAIN
 */

int main(void)
{
    int i = 0, operations;
    char cmd[MAXCMD], name[MAXNAME];

    playlist* P = playlist_create();
    // scanf("%d", &operations);

    // while(i < operations)
    while(1)
    {
        scanf("%s", cmd); // Pega a operação da entrada

        if (strcmp(cmd, "insere") == 0)
        {
            printf("\tModo INSERE\n");
            getchar(); // Pega o espaço
            song_add(P);
        }

        else if (strcmp(cmd, "remove") == 0)
        {
            printf("\tModo REMOVE\n");

        }

        else if (strcmp(cmd, "toca") == 0)
        {
            printf("\tModo TOCA\n");

        }

        else if (strcmp(cmd, "volta") == 0)
        {
            printf("\tModo VOLTA\n");

        }

        else if (strcmp(cmd, "final") == 0)
        {
            printf("\tModo FINAL\n");

        }

        else if (strcmp(cmd, "inverte") == 0)
        {
            printf("\tModo INVERTE\n");

        }

        else if (strcmp(cmd, "print") == 0)
        {
            // Deletar esse modo !!!!!
            print(P);
        }
        
        i++;
    }
    
    return 0;
}