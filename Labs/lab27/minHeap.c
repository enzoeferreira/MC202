#include <stdio.h>
#include <stdlib.h>

struct node {
    long key, priority;
};
typedef struct node node;

struct heap {
    long size, maxSize;
    node* array;
};
typedef struct heap heap;

int main() {

}