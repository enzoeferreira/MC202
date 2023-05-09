#ifndef SPOTIFY_H
#define SPOTIFY_H

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

playlist* playlist_create();
void playlist_delete(playlist* P);

int song_add(playlist* P);
void song_remove(playlist* P);

void toca(playlist* P);
void volta(playlist* P);
void final(playlist* P);

void inverte(playlist* P);

void print(playlist* P);

#endif