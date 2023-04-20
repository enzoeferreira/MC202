#include <stdio.h>
#include <stdlib.h>

struct node
{
    float data;
    struct node *next;
};
typedef struct node node;

/**
 * Insere um dado no início de uma lista encadeada
 * Retorna 1 em sucesso, 0 em falha
 */

int insert(node** L, float data)
{
    node *n = malloc(sizeof(node));
    if(n == NULL)
        return 0;

    n->data = data;
    n->next = *L;
    *L = n;
    return 1;
}

int push(node **L, float data)
{
    node *n = malloc(sizeof(node));
    if(!n)
        return 0;

    n->data = data;
    n->next = NULL;

    node *p = *L;

    if(p == NULL)
    {
        *L = n;
        return 1;
    }

    while(p->next != NULL)
        p = p->next;
}

void release(node** L)
{
    while(*L != NULL)
    {
        node* p = (*L)->next;
        free(*L);
        *L = p;
    }
}

void print(node* L)
{
    node *p;
    p = L;

    while(p != NULL)
    {
        printf("%f ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    node *L = NULL;

    insert(&L, 3.14);
    insert(&L, 1.78);
    insert(&L, 0);
    print(L);

    release(L);

    insert(&L, 5.67);
    print(L);

    push(&L, 10);
    push(&L, 20);
    push(&L, 30);
    print(L);
}