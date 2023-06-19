#include <stdio.h>
#include <stdlib.h>

struct node {
    long key, priority;
};
typedef struct node node;

struct heap {
    long size, maxSize;
    node *array;
};
typedef struct heap heap;

int main() {
    short existingHeap = 0;
    long inMaxSize, inKey, inPriority;
    char cmd;

    cmd = getchar();
    while(cmd != 't') {
        switch(cmd) {
            case 'c': {
                scanf(" %li", &inMaxSize);
            }
            break;

            case 'i': {
                scanf(" %li %li", &inKey, &inPriority);
            }
            break;

            case 'r': {

            }
            break;

            case 'm': {

            }
            break;
        }
        cmd = getchar(); // Recebe próximo comando
    }
}