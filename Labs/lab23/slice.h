#ifndef SLICE_H
#define SLICE_H

struct node {
    int data;
    struct node *prev, *next;
};
typedef struct node node;

struct list {
    node *head, *tail;
    int size;
};
typedef struct list list;

void print(list* L);

list* startList();

int insertNode(list* L, int data);
int sliceList(list* L, int start, int end);
list* copySliceList(list* L, int start, int end);
int copyList(list* L, int start, int end, int index);

#endif