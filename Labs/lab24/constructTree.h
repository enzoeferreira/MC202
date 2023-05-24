#ifndef TREE_H
#define TREE_H

struct node {
    char data;
    struct node *left, *right;
};
typedef struct node node;

struct listNode {
    node *pNode;
    struct listNode *next;
};
typedef struct listNode listNode;

struct list {
    listNode *head, *tail;
};
typedef struct list list;

void printArray(char* array, long int size);
void printPreOrder(node* T);
void printInOrder(node* T);
void printPostOrder(node* T);
void printBreadth(node* T);
void printQueue(list* L);

list* startList();
void enqueue(list* L, node* n);
node* dequeue(list* L);
void freeList(list* L);

char* insertArray(char* array, long int* size, long int* sizeMax, char c);
long int findChar(char* array, long int start, long int end, char c);
node* constructTree(char* preOrder, char* inOrder, long start, long end, int* index);
void freeTree(node* T);

void rec_dot_print(node* p, int* nnull);
void bt_dot_print(node* T);

#endif