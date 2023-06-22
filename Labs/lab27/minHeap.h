#ifndef MINHEAP_H
#define MINHEAP_H

#define EXPANSIONFACTOR 2

struct node {
    long key, priority, timestamp;
};
typedef struct node node;

struct heap {
    long size, maxSize, timestamp;
    node *array;
};
typedef struct heap heap;

void print(heap* H);

heap* createHeap(long maxSize);
void killHeap(heap* H);
heap* expandHeap(heap* H, long factor);

long parent(long index);
void swap(heap* H, unsigned long indexA, unsigned long indexB);

void insertHeap(heap* H, long key, long priority);
void minHeapify(heap* H, long index);
long findMinimum(heap* H);
void removeMin(heap* H);

#endif