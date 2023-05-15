#include <stdio.h>

/**
 * Header
 */
struct node {
    int data;
    struct node *prev, *next;
};
typedef struct node node;

struct list {
    node *head, *tail;
};
typedef struct list list;

/**
 * Library
 */

/**
 * Cria uma lista com dummys no inicio e fim
 * 
 * @return 1) NULL, caso ocorra falha ao alocar a lista ou dummys
 * @return 2) L, onde L é um apontador para a lista
 */
list* startList() {
    list *L = malloc(sizeof(list)); // Tenta alocar lista
    if(!L)
        return NULL;
    
    node *head = malloc(sizeof(node)); // Tenta alocar dummy pra head
    if(!head)
        return NULL;
    L->head = head;
    
    node *tail = malloc(sizeof(node)); // Tenta alocar dummy pra tail
    if(!tail)
        return NULL;
    L->tail = tail;

    L->head->prev = NULL;
    L->head->next = L->tail;
    L->tail->prev = L->head;
    L->tail->next = NULL;

    return L;
}

/**
 * Adiciona um nó com o dado no fim da lista
 * 
 * @param L lista
 * @param data dado a ser adicionado
 * 
 * @return 1) 0, em caso de erro ao alocar espaço para nó
 * @return 2) 1, em caso de sucesso
 */
int insertNode(list* L, int data) {
    node *n = malloc(sizeof(node)); // Tenta alocar nó
    if(!n)
        return 0;

    n->data = data;
    n->next = L->tail;
    n->prev = L->tail->prev;
    L->tail->prev->next = n;
    L->tail->prev = n;
    return 1;
}

/**
 * Printa a lista de head a tail
 * 
 * @param L lista
 */
void print(list* L) {
    printf("A: {");

    node *p = L->head->next; // Aponta para o primeiro elemento
    while(p != L->tail->prev) {
        printf(" %d,", p->data);
        p = p->next;
    }
    printf(" %d }\n", p->data); // Último elemento
}

/**
 * Main
 */
int main() {
    list *L = startList();
    
    /**
     * Extração de lista pela entrada
     */
    char c;
    int num = 0;
    while((c = getchar()) != '}') { // Lista não acabou
        if(c >= '0' && c <= '9') // Caractére é um digito
            num = num * 10 + c - '0'; // Conversão char -> int
        else if(c == ',') {
            insertNode(L, num);
            num = 0;
        }
    }
    insertNode(L, num); // Insere o último digito
    getchar(); // Pega o \n

    /**
     * Comandos para manipulação da lista
     */

    int start, end, index;
    while((c = getchar()) != 'f') { // Não acabou execução
        if(c == 's') {
            scanf(" A[%d..%d]", &start, &end);
            getchar(); // Pega o \n
            // sliceList(L, start, end);
        }
        else if(c == '+') {
            scanf(" A[%d..%d] %d", &start, &end, &index);
            getchar(); // Pega o \n
            // copyList(L, start, end, index);
        }

        print(L);
    }
}