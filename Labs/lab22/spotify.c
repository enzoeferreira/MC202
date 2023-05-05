#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "spotify.h"

playlist* playlist_create()
{
    playlist* P = malloc(sizeof(playlist));
    if(!P)
        return NULL; 
    song* n = malloc(sizeof(song));
    if(!n)
        return NULL;
    P->head = n;

    song* n = malloc(sizeof(song));
    if(!n)
        return NULL;
    P->tail = n;

    P->head->prev = NULL;
    P->head->next = P->tail;
    P->tail->prev = P->head;
    P->tail->next = NULL;

    return P;
}

int song_add(playlist* P, song* pos)
{
    song *n = malloc(sizeof(song));
    if(!n)
        return 0; // Alocação falhou

    fgets(n->name, MAXNAME, stdin);
    n->next = P->pos->next;
    n->prev = P->pos;
    P->pos->next = n;
    return 1;
}

void print(playlist* P)
{
    song *n = P->head;
    printf("\tPLAYLIST:");
    while(!n->next->next)
    {
        printf(" %s,", n->name);
    }
    printf("\n");
}