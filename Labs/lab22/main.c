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
    char name[MAXNAME];
    struct song *next, *prev;
};
typedef struct song song;

struct playlist
{
    song *head;
    song *tail;
    song *pos;
    long songs;
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

    P->songs = 0;

    return P;
}

/**
 * Deleta uma playlist
 * 
 * @param P playlist
 */
void playlist_delete(playlist* P)
{
    song *s = P->head;
    while(!s)
    {
        P->head = P->head->next;
        free(s);
        s = P->head;
    }
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
    song *n = malloc(sizeof(song));
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

    if(!P->songs)
        P->pos = n; // Se for a primeira música, aponta para ela
    P->songs++;
    return 1;
}

void song_remove(playlist* P)
{
    char name[MAXNAME];
    fgets(name, MAXNAME, stdin); // Recebe o nome da música

    char *cleaner = strchr(name, '\n'); // Ponteiro cleaner aponta para \n
    *cleaner = '\0'; // Substitui '\n' por '\0'
    
    song *s = P->head->next;
    short int found = 0;
    while(s != P->tail && !found)
    {
        if(strcmp(s->name, name) == 0)
        {
            // Música a ser deletada encontrada
            // printf("\tACHEI!\n");
            found = 1;
            s->prev->next = s->next;
            s->next->prev = s->prev;
            if(s == P->pos)
            {
                // Música está no indicador
                if(s->prev != P->head) // Há mais musicas antes
                    P->pos = s->prev;
                else if(P->pos->next != P->tail) // Há música depois
                    P->pos = s->next;
                else if(P->songs == 1) // Última música
                    P->pos = P->head;
            }

            free(s);
            P->songs--;
        }
        s = s->next;
    }
}

/**
 * Toca a música indicada pelo ponteiro e avança para a próxima música (Caso exista)
 * 
 * @param P playlis
 */
void toca(playlist* P)
{
    if(P->pos != P->head && P->pos != P->tail)
        printf("%s\n", P->pos->name);
    else
        printf("\n");
    if(P->pos->next != P->tail)
        P->pos = P->pos->next;
}

/**
 * Volta para a música anterior a indicada pelo ponteiro. Se for a primeira nada acontece
 * 
 * @param P playlis
 */
void volta(playlist* P)
{
    if(P->pos->prev != P->head)
        P->pos = P->pos->prev;
}

void final(playlist* P)
{
    while(P->pos != P->tail)
    {
        if(P->pos->next == P->tail) // Última música
        {
            printf("%s\n", P->pos->name);
            return;
        }
        toca(P);
    }
}

void inverte(playlist* P)
{
    song *aux = P->head;
    P->head = P->tail;
    P->tail = aux;

    P->head->next = P->head->prev;
    P->head->prev = NULL;
    P->tail->prev = P->tail->next;
    P->tail->next = NULL;

    song *s = P->tail->prev;
    while(s != P->head)
    {
        s->prev = s->next;
        s->next = aux;

        aux = aux->prev;
        s = s->prev;
    }
}

void print(playlist* P)
{
    song *n = P->head->next;
    printf("PLAYLIST(%d):", P->songs);
    while(n != P->tail)
    {
        if(P->pos == n)
            printf(" (->)");
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
                // printf("\tModo INSERE\n");
                getchar(); // Pega o espaço
                song_add(P);
            }

            else if (strcmp(cmd, "remove") == 0)
            {
                // printf("\tModo REMOVE\n");
                getchar();
                song_remove(P);
            }

            else if (strcmp(cmd, "toca") == 0)
            {
                // printf("\tModo TOCA\n");
                toca(P);
            }

            else if (strcmp(cmd, "volta") == 0)
            {
                // printf("\tModo VOLTA\n");
                volta(P);
            }

            else if (strcmp(cmd, "final") == 0)
            {
                // printf("\tModo FINAL\n");
                final(P);
            }

            else if (strcmp(cmd, "inverte") == 0)
            {
                // printf("\tModo INVERTE\n");
                inverte(P);
            }

            else if (strcmp(cmd, "print") == 0)
            {
                // Deletar esse modo !!!!!
                print(P);
            }
            
            i++;
        }
        printf("\n");

        playlist_delete(P); // Deleta playlist antiga
        scanf("%d", &operations); // Recebe um novo número de operações
        i = 0;
    }
    
    return 0;
}