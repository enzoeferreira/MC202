#include <stdio.h>
#include <stdlib.h>

#define MAXNAME 101

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
    
}