#ifndef BT_TREE_H
#define BT_TREE_H

#define MAXNAME 101
#define MAXCMD 17

struct client {
    int key;
    char name[MAXNAME];
    float score;
    struct client *left;
    struct client *right;
    struct client *parent;
};
typedef struct client client;

void print(client* T);
client* startTree();
void freeTree(client* T);

client* searchClient(client* T, int key);
client* createClient(client* T, int key, char name[MAXNAME], float score);
void insertClient(client* T, client* c);

int getChildCount(client* A);
int min(client* T);
int max(client* T);
int predecessor(client* T, int key);
int sucessor(client* T, int key);

client* removeClient(client* T, int key);
client* minValueClient(client* T);
client* deleteClient2(client* T, int key);

void printRange(client* T, int start, int end, int* count);

void rec_dot_print(client* p, int* nnull);
void bt_dot_print(client* T);

#endif