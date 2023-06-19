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

/**
 * Cria um heap e um array com espaço para 'maxSize' nós
 * 
 * @param maxSize Tamanho do heap
 * 
 * @return 1) NULL, caso falhe em alocar espaço para Heap/Array
 * @return 2) H, ponteiro para Heap
 */
heap* createHeap(long maxSize) {
    heap *H = malloc(sizeof(heap));
    if(!H)
        return NULL;
    node *array = malloc(maxSize * sizeof(node));
    if(!array)
        return NULL;
    
    H->array = array;
    H->size = 0;
    H->maxSize = maxSize;

    return H;
}

/**
 * Libera a memória alocada para um heap
 * 
 * @param H Heap a ser liberado
 */
void killHeap(heap* H) {
    free(H->array);
    free(H);
    return;
}

int main() {
    heap *H;
    short existingHeap = 0;
    long inMaxSize, inKey, inPriority;
    char cmd;

    cmd = getchar();
    while(cmd != 't') {
        switch(cmd) {
            case 'c': {
                scanf(" %li", &inMaxSize);
                if(existingHeap)
                    killHeap(H);
                H = createHeap(inMaxSize);
                existingHeap = 1;
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