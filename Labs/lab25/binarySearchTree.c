#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNAME 101
#define MAXCMD 17

struct client {
    int key;
    char name[MAXNAME];
    float score;
    struct client *left;
    struct client *right;
};
typedef struct client client;

struct tree {
    client *root;
};
typedef struct tree tree;

int main() {
    char cmd[MAXCMD];
    scanf("%s", cmd);
    while(strcmp(cmd, "terminar")) {
        
        scanf("%s", cmd);
    }
}