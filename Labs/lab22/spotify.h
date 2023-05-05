#ifndef SPOTIFY_H
#define SPOTIFY_H

#define MAXNAME 101

typedef struct
{
    char name[MAXNAME];
    song *next, *prev;
} song;

typedef struct
{
    song *head;
    song *tail;
    song *pos;
} playlist;

playlist* playlist_create();

int song_add(playlist* P, song* pos);

void print(playlist* P);

#endif