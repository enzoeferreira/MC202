#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binarySearchTree.h"

/**
 * Imprime os clientes da árvore binária no formato "nome1 (k1) nome2 (k2) ... nomeN (kN)"
 * 
 * @param T raiz da árvore binária
 */
void print(client* T) {
    if(!T)
        return;
    print(T->left);
    printf("%s (%d) ", T->name, T->key);
    print(T->right);
}

/**
 * Cria uma árvore binária
 * 
 * @return 1) NULL, caso falha em alocar espaço para árvore
 * @return 2) T, apontador para raiz de uma árvore binária
 */
client* startTree() {
    client *T = malloc(sizeof(client));
    if(!T)
        return NULL;

    T->key = -__INT32_MAX__;
    T->left = NULL;
    T->right = NULL;
    T->parent = NULL;
    return T;
}

/**
 * Libera o espaço de memória alocado para todos os nós de uma árvore binária
 * 
 * @param T raiz da árvore
 */
void freeTree(client* T) {
    if(!T)
        return;
    freeTree(T->left);
    freeTree(T->right);
    free(T);
}

/**
 * Procura cliente na árvore pela key
 * 
 * @param T raiz da árvore binária
 * @param key chave do cliente a ser procurado
 * 
 * @return 1) NULL, caso não encontre o cliente
 * @return 2) p, apontador para o cliente
 */
client* searchClient(client* T, int key) {
    client* p = T;
    if(p == NULL)
        return NULL;
    if(key == p->key)
        return p;
    if(key < p->key)
        return searchClient(p->left, key);
    else
        return searchClient(p->right, key);
}

/**
 * Cria o registro de um cliente
 * 
 * @param T raiz da árvore binária
 * @param key chave do cliente a ser criado
 * @param name nome do cliente a ser criado
 * @param score pontuação do cliente a ser criado
 * 
 * @return 1) NULL, caso cliente já exista
 * @return 2) 0, printando "memoria insuficiente" caso falte memória
 * @return 3) c, apontador para cliente que foi criado
 */
client* createClient(client* T, int key, char name[MAXNAME], float score) {
    client* found = searchClient(T, key);
    if(found)
        return NULL;
    
    client *c = malloc(sizeof(client));
    if(!c) {
        printf("memoria insuficiente");
        return 0;
    }
    c->key = key;
    strcpy(c->name, name);
    c->score = score;
    c->left = NULL;
    c->right = NULL;
    c->parent = NULL;
    return c;
}

/**
 * Insere um cliente (de chave única) na árvore binária
 * 
 * @param T raiz da árvore binária
 * @param c cliente a ser inserido na árvore
 */
void insertClient(client* T, client* c) {
    client *p = T;
    if(p->key == -__INT32_MAX__) { // Primeiro elemento
        T->key = c->key;
        strcpy(T->name, c->name);
        T->score = c->score;
        T->parent = NULL;
        return;
    }
    client *q = NULL;
    while(p != NULL) {
        q = p;
        if(c->key < p->key)
            p = p->left;
        else
            p = p->right;
    }
    if(c->key < q->key) {
        q->left = c;
        c->parent = q;
    }
    else {
        q->right = c;
        c->parent = q;
    }
    return;
}

/**
 * Retorna a quantidade de filhos de um nó
 * 
 * @param A cliente desejado
 * 
 * @return 1) n, onde n é a quantidade de filhos de um nó. 0 <= n <= 2
 */
int getChildCount(client* A) {
    if(A->left == NULL && A->right == NULL)
        return 0;
    if((A->left != NULL && A->right == NULL) || (A->left == NULL && A->right != NULL))
        return 1;
    return 2;
}

/**
 * Retorna a menor chave de uma árvore binária
 * 
 * @param T raiz da árvore binária
 * 
 * @return key, menor chave da árvore binária
 */
int min(client* T) {
    client* p = T;
    while(p->left != NULL)
        p = p->left;
    return p->key;
}

/**
 * Retorna a maior chave de uma árvore binária
 * 
 * @param T raiz da árvore binária
 * 
 * @return key, maior chave da árvore binária
 */
int max(client* T) {
    client* p = T;
    while(p->right != NULL)
        p = p->right;
    return p->key;
}

/**
 * Procura o predecessor de um cliente através de sua chave
 * 
 * @param T raiz da árvore binária
 * @param key chave que o predecessor será procurado
 * 
 * @return 1) __INT32_MAX__, caso o cliente não exista ou não tenha predecessor
 * @return 2) key, chave do predecessor do cliente
 */
int predecessor(client* T, int key) {
    client *p = searchClient(T, key);
    if(!p)
        return __INT32_MAX__; // Cliente não existe
    if(p->left != NULL)
        return max(p->left);
    while(p->parent != NULL && p == p->parent->left) // 'p' é filho da esquerda
        p = p->parent; 
    if(p->parent != NULL) // Pai de 'p' é o predecessor do cliente
        return p->parent->key;
    return __INT32_MAX__; // Cliente não tem predecessor
}

/**
 * Procura o sucessor de um cliente através de sua chave
 * 
 * @param T raiz da árvore binária
 * @param key chave que o sucessor será procurado
 * 
 * @return 1) __INT32_MAX__, caso o cliente não exista ou não tenha sucessor
 * @return 2) key, chave do sucessor do cliente
 */
int sucessor(client* T, int key) {
    client *p = searchClient(T, key);
    if(!p)
        return __INT32_MAX__; // Cliente não existe
    if(p->right != NULL)
        return min(p->right);
    while(p->parent != NULL && p == p->parent->right) // 'p' é filho da direita
        p = p->parent;
    if(p->parent != NULL) // Pai de 'p' é o sucessor do cliente
        return p->parent->key;
    return __INT32_MAX__; // Cliente não tem sucessor
}

/**
 * Encontra e remove um cliente de uma árvore binária de busca
 * Se o cliente não estiver na árvore nada acontece
 * 
 * @param T raiz da árvore binária
 * @param key chave do cliente a ser removido
 * 
 * @return 1) T, árvore atualizada
 */
client* removeClient(client* T, int key) {
    client *c = searchClient(T, key);
    if(!c) // Cliente não existe
        return T;
    int child = getChildCount(c);
    if(child == 0) {
        if(c == c->parent->left)
            c->parent->left = NULL;
        else if(c == c->parent->right)
            c->parent->right = NULL;
        else {  // Cliente era o último
                T->key = -1;
                T->left = NULL;
                T->right = NULL;
                T->parent = NULL;
        }
        free(c);
        return T;
    }
    else if(child == 1) {
        if(c->left != NULL) { // Filho está na esquerda
            if(c->parent != NULL) {
                c->left->parent = c->parent;
                c->parent->left = c->left;
                free(c);
                return T;
            }
            // Cliente era raiz, agora o filho que é
            T = c->left;
            free(c);
            return T;
        }
        else { // Filho está na direita
            if(c->parent != NULL) {
                c->right->parent = c->parent;
                c->parent->right = c->right;
                free(c);
                return T;
            }
            
            // Cliente era raiz, agora o filho que é
            T = c->right;
            free(c);
            return T;
        }
    }
    else if(child == 2) {
        client *suc = searchClient(T, sucessor(T, c->key));
        if(suc == c->right) { // Sucessor é filho
            suc->parent = c->parent;
            c->parent->right = suc;
            suc->left = c->left;
            suc->left->parent = suc;
            free(c);
            return T;
        }
        
        // Sucessor não é filho, troca sucessor com seu filho da direita
        if(suc->right != NULL) { // Sucessor tem filhos (na direita)
            suc->right->parent = suc->parent;
            suc->parent->left = suc->right;
        }
        else
            suc->parent->left = NULL;

        // Troca cliente com seu sucessor
        suc->parent = c->parent;
        if(c->parent == NULL) { // Cliente era raiz
            T = suc;
        }
        else { // Cliente não era raiz
            if(c == c->parent->left)
                c->parent->left = suc;
            else
                c->parent->right = suc;
        }

        suc->right = c->right;
        suc->left = c->left;
        c->left->parent = suc;
        c->right->parent = suc;
        free(c);
        return T;
    }
    return T;
}

client* minValueClient(client* T)
{
    client* p = T;
 
    while (p && p->left != NULL)
        p = p->left;
 
    return p;
}
 
client* deleteClient2(client* T, int key)
{
    if (T == NULL)
        return T;

    if(T->parent == NULL && T->left == NULL && T->right == NULL) {
        printf("check\n");
        T->key = -__INT32_MAX__;
        return T;
    }
 
    if (key < T->key)
        T->left = deleteClient2(T->left, key);

    else if (key > T->key)
        T->right = deleteClient2(T->right, key);
 
    else {
        if (T->left == NULL) {
            client* temp = T->right;
            free(T);
            return temp;
        }
        else if (T->right == NULL) {
            client* temp = T->left;
            free(T);
            return temp;
        }

        client* temp = minValueClient(T->right);
 
        T->key = temp->key;
        strcpy(T->name, temp->name);
        T->score = temp->score;
 
        T->right = deleteClient2(T->right, temp->key);
    }
    return T;
}

void printRange(client* T, int start, int end, int* count) {
    if (T == NULL)
        return;
    if (T->key > start)
        printRange(T->left, start, end, count);
    if (T->key >= start && T->key <= end) {
        printf("%d ", T->key);
        (*count)++;
    }
    if (T->key < end)
        printRange(T->right, start, end, count);
}

void rec_dot_print(client* p, int* nnull) {
    if (p == NULL)
        return;

    if (p->left == NULL) {
        printf("  N%d [shape=point];\n",*nnull);
        printf("  %d -> N%d;\n",p->key,*nnull);
        *nnull += 1;
    }
    else {
        printf("  %d -> %d;\n",p->key,p->left->key);
        rec_dot_print(p->left,nnull);
    }

    if (p->right == NULL) {
        printf("  N%d [shape=point];\n",*nnull);
        printf("  %d -> N%d;\n",p->key,*nnull);
        *nnull += 1;
    }
    else {
        printf("  %d -> %d;\n",p->key,p->right->key);
        rec_dot_print(p->right,nnull);
    }
}

/*
Imprime a árvore no formato do graphviz dot (graphviz.org).
Um arquivo x.dot pode ser convertido em png com o comando
dot -T png x.dot >x.png
*/
void bt_dot_print(client* T) {
    printf("digraph BT {\n");
    printf("  node [fontname=\"Arial\"];\n");

    int n = 0;
    rec_dot_print(T, &n);

    printf("}\n");
}