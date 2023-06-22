#include <stdio.h>
#include <stdlib.h>

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

/**
 * Printa 'size' e 'maxSize' de um Heap, além de todos os seus elementos do array
 * 
 * @param H Heap a ser printado
 */
void print(heap* H) {
    printf("\n==============================");
    printf("\nSize: %li, MaxSize: %li\n", H->size, H->maxSize);
    for(long i = 0; i < H->size; i++)
        printf("[%lu](%lu,%lu) ", H->array[i].timestamp, H->array[i].key, H->array[i].priority);
    printf("\n==============================");
    printf("\n");
}

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
    H->timestamp = 0;

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

/**
 * Cria um novo Heap com 'fator' vezes o tamanho do array anterior.
 * 'fator' >= 1, se não, comportamento indefinido (provavelmente erro grave na hora da cópia).
 * Libera a memória alocada pelo outro Heap (e array).
 * 
 * @param H Heap a ser expandido
 * @param factor Fator de expansão
 * 
 * @return 1) NULL, caso falhe em alocar espaço para Heap ou array
 * @return 2) newH, apontador para novo Heap com array expandido
 */
heap* expandHeap(heap* H, long factor) {
    // Criação do novo Heap com o dobro do tamanho no array
    heap *newH = malloc(sizeof(heap));
    if(!newH)
        return NULL;
    node *newArray = malloc((factor*H->maxSize) * sizeof(node));
    if(!newArray)
        return NULL;

    newH->array = newArray;
    newH->size = H->size;
    newH->maxSize = factor*H->maxSize;
    newH->timestamp = H->timestamp;

    // Cópia dos elementos
    for(long int i = 0; i < H->size; i++)
        newH->array[i] = H->array[i];
    killHeap(H);
    return newH;
}

/**
 * @param index Índice que quer encontra o pai
 * 
 * @return Índice do pai
 */
long parent(long index) {
    return ((index - 1)/2);
}

/**
 * Troca os dados de 'Elemento A' com 'Elemento B'
 * 
 * @param H Heap com o array dos elementos
 * @param indexA Index do elemento A
 * @param indexB Index do elemento B
 */
void swap(heap* H, unsigned long indexA, unsigned long indexB) {
    node aux = H->array[indexA];
    H->array[indexA] = H->array[indexB];
    H->array[indexB] = aux;
    return;
}

/**
 * Adiciona o elemento no fim do array e vai trocando com o pai até ele estar na posição correta.
 * 
 * @param H Heap que contém array onde elemento será adicionado
 * @param key Key do elemento a ser adicionado
 * @param priority Prioridade do elemento a ser adicionado
 */
void insertHeap(heap* H, long key, long priority) {
    // Insere novo nó no fim
    H->array[H->size].key = key;
    H->array[H->size].priority = priority;
    H->array[H->size].timestamp = H->timestamp++;

    long index = H->size;
    long parentIndex = parent(index);

    while(parentIndex >= 0 && H->array[index].priority < H->array[parentIndex].priority) {
        swap(H, parentIndex, index);
        index = parentIndex;
        parentIndex = parent(index);
    }
    H->size++;

    return;
}

/**
 * Certifica-se a partir de 'index' que o array está em minHeap.
 * 
 * @param H Heap
 * @param index Index inicial do minHeapify
 */
void minHeapify(heap* H, long index) {
    long leftIndex = 2*index + 1; 
    long rightIndex = 2*index + 2;
    long minimum = index;
    if(leftIndex < H->size && H->array[leftIndex].priority < H->array[minimum].priority)
        minimum = leftIndex;
    if(rightIndex < H->size && H->array[rightIndex].priority < H->array[minimum].priority)
        minimum = rightIndex;
    if(index != minimum) {
        swap(H, index, minimum);
        minHeapify(H, minimum);
    }

    return;
}

/**
 * Encontra o índice do mínimo com menor timestamp (mais antigo)
 * 
 * @param H Heap
 * 
 * @return Índice do mínimo mais antigo
 */
long findMinimum(heap* H) {
    long minPriority = H->array[0].priority;
    long minIndex = 0;
    long minTimestamp = H->array[0].timestamp;
    for(long int i = 0; i < H->size; i++)
        if(H->array[i].priority == minPriority && H->array[i].timestamp < minTimestamp) {
            minTimestamp = H->array[i].timestamp;
            minIndex = i;
        }

    return minIndex;
}

/**
 * Remove o primeiro elemento (mínimo) se existir do Heap, aplicando minHeapify ao realizar a troca.
 * 
 * @param H Heap
 */
void removeMin(heap* H) {
    if(H->size == 0)
        return;

    long minIndex = findMinimum(H);

    // Troca mínimo mais antigo com último
    swap(H, minIndex, H->size - 1);
    H->size--;

    minHeapify(H, minIndex); // Aplica minHeapify no elemento trocado com o mínimo mais antigo
    return;
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
                    long minIndex = findMinimum(H);
                    printf("prioridade minima %li, chave %li\n",
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