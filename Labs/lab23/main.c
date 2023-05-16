#include <stdio.h>
#include <stdlib.h>

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
    int size;
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

    L->size = 0;

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

    L->size++;

    return 1;
}

/**
 * Extrai uma sublista de A e substituir A pela sublista, removendo A anterior no processo
 * 
 * @param L lista
 * @param start índice inicial
 * @param end índice final
 * 
 * @return 1) 0, em caso de falha para criar a lista auxiliar e/ou nós copiados
 * @return 2) 1, em caso de sucesso
 */
int sliceList(list* L, int start, int end) {
    list *newL = startList(); // Cria uma nova lista
    if(!newL)
        return 0;

    /**
     * Apontador p vai do inicio a start se estiver na metade esquerda da lista
     * ou do fim a start se estiver na metade direita
     * Apontador q aponta para o mesmo que p
     */
    int i = 0;
    node *p, *q;
    if(start <= (L->size/2)) {
        p = L->head->next; // Começa no primeiro
        while(i < start) {
            p = p->next;
            i++;
        }
    }
    else {
        p = L->tail->prev; // Começa no último
        while(i < (L->size - start - 1)) {
            p = p->prev;
            i++;
        }
    }
    q = p;

    /**
     * Faz a copia dos elementos, liberando os originais
     */
    i = 0;
    int sucess;
    int delta = (end >= start) ? end - start : start - end;
    while(i <= delta) {
        sucess = insertNode(newL, p->data);
        if(!sucess)
            return 0;
        if(delta == end - start) {
            p = p->next;
            free(q);
            q = p;
        }
        else {
            p = p->prev;
            free(q);
            q = p;
        }
        i++;
    }

    L->head = newL->head;
    L->tail = newL->tail;
    free(newL);

    return 1;
}

/**
 * Extrai uma sublista de A e substituir A pela sublista, NÃO removendo A anterior no processo
 * 
 * @param L lista
 * @param start índice inicial
 * @param end índice final
 * 
 * @return 1) NULL, em caso de falha para criar a lista auxiliar e/ou nós copiados
 * @return 2) newL, onde newL é um apontador para a nova lista
 */
list* copySliceList(list* L, int start, int end) {
    list *newL = startList(); // Cria uma nova lista
    if(!newL)
        return NULL;

    /**
     * Apontador p vai do inicio a start se estiver na metade esquerda da lista
     * ou do fim a start se estiver na metade direita
     * Apontador q aponta para o mesmo que p
     */
    int i = 0;
    node *p;
    if(start <= (L->size/2)) {
        p = L->head->next; // Começa no primeiro
        while(i < start) {
            p = p->next;
            i++;
        }
    }
    else {
        p = L->tail->prev; // Começa no último
        while(i < (L->size - start - 1)) {
            p = p->prev;
            i++;
        }
    }

    /**
     * Faz a copia dos elementos, liberando os originais
     */
    i = 0;
    int sucess;
    int delta = (end >= start) ? end - start : start - end;
    while(i <= delta) {
        sucess = insertNode(newL, p->data);
        if(!sucess)
            return NULL;
        if(delta == end - start)
            p = p->next;
        else
            p = p->prev;

        i++;
    }

    return newL;
}

/**
 * 
 * 
 * @param L lista
 * @param start índice inicial
 * @param end índice final
 * @param index índice onde sera colocada a cópia
 * 
 * @return 1) 0, em caso de falha para criar a lista auxiliar e/ou nós copiados
 * @return 2) 1, em caso de sucesso
 */
int copyList(list* L, int start, int end, int index) {
    list *copyL = copySliceList(L, start, end);
    if(!copyL)
        return 0;
    
    /**
     * Apontador p vai do inicio a index se estiver na metade esquerda da lista
     * ou do fim a index se estiver na metade direita
     */
    int i = 0;
    node *p;
    if(index <= (L->size/2)) {
        p = L->head->next; // Começa no primeiro
        while(i < index) {
            p = p->next;
            i++;
        }
    }
    else {
        p = L->tail->prev; // Começa no último
        while(i < (L->size - index - 1)) {
            p = p->prev;
            i++;
        }
    }
    node *aux = p;
    p = p->prev; // Volta 1
    
    /**
     * Inserção dos elementos
     */
    node *q = copyL->head->next;
    p->next = q;
    q->prev = p;
    
    while(q->next != copyL->tail)
        q = q->next;
    q->next = aux;
    aux->prev = q;
    L->size += copyL->size;

    free(copyL);
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
    if(p == L->tail) {
        printf(" }\n");
        return; // Lista vazia
    }
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
            sliceList(L, start, end);
        }
        else if(c == '+') {
            scanf(" A[%d..%d] %d", &start, &end, &index);
            getchar(); // Pega o \n
            copyList(L, start, end, index);
        }

        print(L);
    }
}