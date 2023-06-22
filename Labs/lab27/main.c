#include <stdio.h>
#include <stdlib.h>

#include "minHeap.h"

int main() {
    heap *H = malloc(sizeof(heap));
    short existingHeap = 0;
    int inMaxSize, inKey, inPriority;
    char cmd;

    cmd = getchar();
    while(cmd != 't') {
        switch(cmd) {
            case 'c': {
                scanf(" %i", &inMaxSize);
                if(existingHeap)
                    killHeap(H);
                H = createHeap(inMaxSize);
                existingHeap = 1;
            }
            break;

            case 'i': {
                scanf(" %i %i", &inKey, &inPriority);
                if(H->size == H->maxSize)
                    H = expandHeap(H, EXPANSIONFACTOR);
                insertHeap(H, inKey, inPriority);
            }
            break;

            case 'r': {
                removeMin(H);
            }
            break;

            case 'm': {
                if(H->size == 0)
                    printf("fila de prioridades vazia\n");
                else {
                    int minIndex = findMinimum(H);
                    printf("prioridade minima %i, chave %i\n",
                        H->array[minIndex].priority, H->array[minIndex].key);
                }
            }
            break;

            case 'p': {
                // Apenas para debug
                print(H);
            }
            break;
        }
        cmd = getchar(); // Recebe próximo comando
    }
    
    killHeap(H);
}