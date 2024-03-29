#include <stdio.h>
#include <stdlib.h>

#include "constructTree.h"

/**
 * Printa um array dinâmico
 * 
 * @param array array dinâmico
 * @param size tamanho atual do array
 */
void printArray(char* array, long int size) {
    for(int i = 0; i < size; i++)
        printf("%c ", *(array + i));
    printf("\n");
}

/**
 * Printa uma árvore em Pré-Ordem
 * 
 * @param T árvore
 */
void printPreOrder(node* T) {
    if(!T)
        return;
    printf("%c", T->data);
    printPreOrder(T->left);
    printPreOrder(T->right);
}

/**
 * Printa uma árvore Em-Ordem
 * 
 * @param T árvore
 */
void printInOrder(node* T) {
    if(!T)
        return;
    printInOrder(T->left);
    printf("%c", T->data);
    printInOrder(T->right);
}

/**
 * Printa uma árvore em Pos-Ordem
 * 
 * @param T árvore
 */
void printPostOrder(node* T) {
    if(!T)
        return;
    printPostOrder(T->left);
    printPostOrder(T->right);
    printf("%c", T->data);
}

/**
 * Inicia uma lista de nós de lista com dummys na head e tail
 * 
 * @return 1) NULL, caso falha em alocar espaço para lista ou nó de lista
 * @return 2) L, ponteiro para lista
 */
list* startList() {
    list *L = malloc(sizeof(list));
    if(!L)
        return NULL;
    
    listNode *head = malloc(sizeof(listNode));
    if(!head)
        return NULL;
    listNode *tail = malloc(sizeof(listNode));
    if(!tail)
        return NULL;

    L->head = head;
    L->tail = tail;
    L->head->next = L->tail;
    L->tail->next = NULL;
    return L;
}

/**
 * Coloca um nó no final de uma lista
 * 
 * @param L lista
 * @param n nó a ser colocado na fila
 */
void enqueue(list* L, node* n) {
    listNode *lN = malloc(sizeof(listNode));
    if(!lN)
        return;
    lN->pNode = n;
    lN->next = L->tail;

    listNode *p = L->head;
    while(p->next != L->tail)
        p = p->next;
    p->next = lN;
}

/**
 * 
 * @param L list
 * 
 * @return 1) NULL, caso lista esteja vazia
 * @return 2) aux, apontador para nó com o nó que foi tirado da fila
 */
node* dequeue(list* L) {
    listNode *p = L->head;
    if(p->next == L->tail)
        return NULL;
    listNode *q = p->next;
    node *aux = p->next->pNode;
    p->next = p->next->next;
    free(q);
    return aux;
}

/**
 * Libera uma lista da memória
 * 
 * @param L lista
 */
void freeList(list* L) {
    listNode* current = L->head;
    while (current != NULL) {
        listNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(L);
}

/**
 * Printa uma árvore binária em ordem de camadas
 * 
 * @param T árvore
 */
void printBreadth(node* T) {
    if(!T)
        return;
    list *L = startList();
    enqueue(L, T);
    while(L->head->next != L->tail) {
        node* n = dequeue(L);
        printf("%c", n->data);
        if(n->left != NULL)
            enqueue(L, n->left);
        if(n->right != NULL)
            enqueue(L, n->right);
    }
    freeList(L);
    printf("\n");
}

/**
 * Printa uma lista da head até tail
 * 
 * @param L lista
 */
void printQueue(list* L) {
    listNode *p = L->head->next;
    printf("L: ");
    while(p != L->tail) {
        printf("%c ", p->pNode->data);
        p = p->next;
    }
}

/**
 * Insere um caractére em um vetor dinâmico, aumentando o tamanho do array com fator 2 se preciso
 * 
 * @param array array dinâmico
 * @param size tamanho atual do array
 * @param sizeMax tamanho máximo do array
 * @param c caractére a ser adicionado
 * 
 * @return 1) NULL, caso não seja possivel alocar um novo array
 * @return 2) array, ponteiro para o mesmo ou novo array com o caractére adicionado
 */
char* insertArray(char* array, long int* size, long int* sizeMax, char c) {
    // printf("\t-----INSERINDO %c-----\n", c);
    // printf("\tsize: %li\n", *size);
    // printf("\tsizeMax: %li\n", *sizeMax);
    // printf("\tarray[0]: %c\n", *array);
    if(*size < *sizeMax) {
        // Espaço suficiente para adicionar
        *(array + (*size)) = c;
        (*size)++;
        return array;
    }
    // Espaço insuficiente para adicionar
    char *newArray = malloc((2*(*sizeMax)) * sizeof(char));
    *sizeMax *= 2;
    if(!newArray)
        return NULL;

    // Cópia dos elementos do array antigo para o novo
    char *p, *q;
    p = array;
    q = newArray;
    for(int i = 0; i < *size; i++) {
        *q = *p;
        p++;
        q++;
    }

    // Adição do caractére
    *(newArray + (*size)) = c;
    (*size)++;
    free(array);
    return newArray;
}

/**
 * Procura um caractére em um array
 * 
 * @param array array dinâmico
 * @param start índice de começo da busca
 * @param end índice de fim da busca
 * @param c caractére a ser encontrado
 * 
 * @return 1) NULL, caso não encontre
 * @return 2) i, onde i é o índice do caractére desejado
 */
long int findChar(char* array, long int start, long int end, char c) {
    int i;
    for(i = start; i <= end; i++)
        if(array[i] == c)
            return i;
    return 0;
}

/**
 * Constrói uma árvore binária a partir de seus elementos em 2 char arrays em Pré-Ordem e Em-Ordem
 * 
 * @param preOrder array da árvore em pré-ordem
 * @param inOrder array da árvore em-ordem
 * @param start índice de início dos arrays
 * @param end índice de fim dos arrays
 * @param index ponteiro que guarda índice na Pré-Ordem
 * 
 * @return 1) NULL, caso falhe em alocar memória para os nós da árvore
 * @return 2) n, apontador para a raiz de uma árvore
 */
node* constructTree(char* preOrder, char* inOrder, long start, long end, int* index) {
    if(start > end)
        return NULL;
    
    node *n = malloc(sizeof(node));
    if(!n)
        return NULL;
    n->data = preOrder[*index];
    (*index)++;
    n->left = NULL;
    n->right = NULL;
    if(start == end)
        return n;

    long int nIndex = findChar(inOrder, start, end, n->data);

    // printf("\t\n-----INSERINDO %c-----\n", n->data);
    // printf("\tstart = %li\n", start);
    // printf("\tnIndex = %li\n", nIndex);
    // printf("\tend = %li\n", end);

    n->left = constructTree(preOrder, inOrder, start, nIndex - 1, index);
    n->right = constructTree(preOrder, inOrder, nIndex + 1, end, index);
    return n;
}

/**
 * Libera uma árvore binária da memória
 * 
 * @param T árvore binária
 */
void freeTree(node* T) {
    if(!T)
        return;
    freeTree(T->left);
    freeTree(T->right);
    free(T);
}

void rec_dot_print(node* p, int* nnull) {
    if (p == NULL)
        return;

    if (p->left == NULL) {
        printf("  N%d [shape=point];\n",*nnull);
        printf("  %c -> N%d;\n",p->data,*nnull);
        *nnull += 1;
    }
    else {
        printf("  %c -> %c;\n",p->data,p->left->data);
        rec_dot_print(p->left,nnull);
    }

    if (p->right == NULL) {
        printf("  N%d [shape=point];\n",*nnull);
        printf("  %c -> N%d;\n",p->data,*nnull);
        *nnull += 1;
    }
    else {
        printf("  %c -> %c;\n",p->data,p->right->data);
        rec_dot_print(p->right,nnull);
    }
}

/*
Imprime a árvore no formato do graphviz dot (graphviz.org).
Um arquivo x.dot pode ser convertido em png com o comando
dot -T png x.dot >x.png
*/
void bt_dot_print(node* T) {
    printf("digraph BT {\n");
    printf("  node [fontname=\"Arial\"];\n");

    int n = 0;
    rec_dot_print(T, &n);

    printf("}\n");
}