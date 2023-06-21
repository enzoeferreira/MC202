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

heap* expandHeap(heap* H) {
    // Criação do novo Heap com o dobro do tamanho no array
    heap *newH = malloc(sizeof(heap));
    if(!newH)
        return NULL;
    node *newArray = malloc((2*H->maxSize) * sizeof(node));
    if(!newArray)
        return NULL;

    newH->array = newArray;
    newH->size = H->size;
    newH->maxSize = 2*H->maxSize;

    // Cópia dos elementos
    for(long int i = 0; i < H->maxSize - 1; i++)
        newH->array[i] = H->array[i];

    return newH;
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

/**
 * @param index Índice que quer encontra o pai
 * 
 * @return Índice do pai
 */
long parent(long index) {
    return ((index - 1)/2);
}

void swap(heap* H, unsigned long indexA, unsigned long indexB) {
    node aux;
    aux.key = H->array[indexA].key;
    aux.priority = H->array[indexA].priority;
    H->array[indexA] = H->array[indexB];
    H->array[indexB] = aux;
    return;
}

void insertHeap(heap* H, long key, long priority) {
    // Insere novo nó no fim
    H->array[H->size].key = key;
    H->array[H->size].priority = priority;

    unsigned long index = H->size;
    unsigned long parentIndex = parent(index);

    if(H->size == H->maxSize)
        H = expandHeap(H);
    while(parentIndex >= 0 && H->array[index].priority < H->array[parentIndex].priority) {
        swap(H, parentIndex, index);
        index = parentIndex;
        parentIndex = parent(index);
    }
    H->size++;

    return;
}

void print(heap* H) {
    for(unsigned long i = 0; i < H->size; i++)
        printf("(%lu,%lu) ", H->array[i].key, H->array[i].priority);
    printf("\n");
}

int main() {
    heap *H = malloc(sizeof(heap));
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
                insertHeap(H, inKey, inPriority);
            }
            break;

            case 'r': {

            }
            break;

            case 'm': {

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
}