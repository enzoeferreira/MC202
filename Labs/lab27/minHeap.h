#ifndef MINHEAP_H
#define MINHEAP_H

#define EXPANSIONFACTOR 2

struct node {
    unsigned long timestamp;
    unsigned key;
    int priority;
};
typedef struct node node;

struct heap {
    long timestamp;
    int size, maxSize;
    node *array;
};
typedef struct heap heap;

void print(heap* H);

heap* createHeap(int maxSize);
void killHeap(heap* H);
heap* expandHeap(heap* H, int factor);

int parent(int index);
void swap(heap* H, int indexA, int indexB);

void insertHeap(heap* H, unsigned key, int priority);
void minHeapify(heap* H, int index);
int findMinimum(heap* H);
void removeMin(heap* H);

#endif