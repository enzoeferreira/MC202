#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNAME 101
#define MAXCMD 17

struct client {
    int key;
    char name[MAXNAME];
    float score;
    struct client *left;
    struct client *right;
};
typedef struct client client;

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

    T->key = NULL;
    T->left = NULL;
    T->right = NULL;
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
 * @return 1) 0, caso não encontre o cliente
 * @return 2) 1, caso encontre
 */
unsigned short searchClient(client* T, int key) {
    client* p = T;
    if(key == p->key)
        return 1;
    if(key < p->key) {
        if(p->left == NULL)
            return 0;
        searchClient(p->left, key);
    }
    else
        searchClient(p->right, key);
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
    unsigned short found = searchClient(T, key);
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
    if(p == NULL) { // Primeiro elemento
        T = c;
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
    if(c->key < q->key)
        q->left = c;
    else
        q->right = c;
    return;
}

int main() {
    client *T;
    unsigned short existingTree = 0;
    int inKey, inStart, inEnd;
    float inScore;
    char cmd[MAXCMD], inName[MAXNAME];

    scanf("%s", cmd);
    while(strcmp(cmd, "terminar")) {
        if(!strcmp(cmd, "criar")) {
            /**
             * Criar uma árvore binária de busca vazia.
             * Se já houver uma árvore sendo processada, todos os nós dela devem ser removidos.
             */
            if(existingTree)
                freeTree(T);
            T = startTree();
            existingTree = 1;

        } else if(!strcmp(cmd, "inserir")) {
            /**
             * Formato: "inserir k, nome, pontuacao"
             * Inserir registro do cliente de key 'k', name 'nome', score 'pontuacao' na árvore.
             * 
             * OBS: Se k já estiver na árvore, o programa não faz nada.
             * OBS: Se não houver memória, o programa imprime "memoria insuficiente" e continua.
             */
            getchar(); // Tira espaço
            scanf("%d, ", &inKey);
            scanf("%[^,]s", inName);
            getchar();
            scanf("%f", &inScore);
            printf( "\t----------Inserindo Cliente----------\n"
                    "\tKey: %d\n"
                    "\tNome: %s\n"
                    "\tScore: %0.2f\n", inKey, inName, inScore);
            client *c = createClient(T, inKey, inName, inScore);
            if(c) {
                printf("\tCliente sendo inserido...\n");
                insertClient(T, c);
            }

        } else if(!strcmp(cmd, "remover")) {
            /**
             * Formato: "remover k"
             * Remover registro do cliente de key 'k'.
             * 
             * OBS: Se k não estiver na árvore, o programa não faz nada.
             */
            getchar();
            scanf("%d", &inKey);
            printf("\t----------Removendo Cliente----------\n"
                    "\tKey: %d\n", inKey);
            
        } else if(!strcmp(cmd, "buscar")) {
            /**
             * Formato: "buscar k"
             * Buscar registro do cliente de key 'k' e imprimir: "cliente k: nome, z pontos"
             * 
             * OBS: Pontos com 2 casas decimais
             * OBS: Se não encontrar o cliente, imprimir: "nao ha cliente k"
             */
            getchar();
            scanf("%d", &inKey);
            printf("\t----------Buscando Cliente----------\n"
                    "\tKey: %d\n", inKey);
            
        } else if(!strcmp(cmd, "imprimir")) {
            /**
             * Imprimir os nomes e chaves dos clientes Em-Ordem
             * Formato de impressão: "clientes: nome1 (k1) nome2 (k2) ... nomeN (kN)"
             * 
             * OBS: Se a árvore estiver vazia, imprimir: "arvore vazia"
             */
            
        } else if(!strcmp(cmd, "minimo")) {
            /**
             * Imprimir a menor chave na árvore
             * Formato de impressão: "minimo: k"
             * 
             * OBS: Se a árvore estiver vazia, imprimir: "arvore vazia"
             */
            
        } else if(!strcmp(cmd, "maximo")) {
            /**
             * Imprimir a maior chave na árvore
             * Formato de impressão: "maximo: k"
             * 
             * OBS: Se a árvore estiver vazia, imprimir: "arvore vazia"
             */
            
        } else if(!strcmp(cmd, "sucessor")) {
            /**
             * Formato: "sucessor k"
             * Imprimir: "sucessor de k: z"
             * 
             * OBS: Se não tiver sucessor, imprimir: "sucessor de k: nao ha"
             * OBS: Se k não estiver na árvore, imprimir: "nao ha cliente k"
             */
            
        } else if(!strcmp(cmd, "predecessor")) {
            /**
             * Formato: "predecessor k"
             * Imprimir: "predecessor de k: z"
             * 
             * OBS: Se não tiver sucessor, imprimir: "predecessor de k: nao ha"
             * OBS: Se k não estiver na árvore, imprimir: "nao ha cliente k"
             */
            
        } else if(!strcmp(cmd, "buscar-intervalo")) {
            /**
             * Formato: "buscar-intervalo x y"
             * Imprimir todas as chaves na árvore contidas no intervalo [x,y]
             * Formato de impressão: "clientes no intervalo [x,y]: k1 k2 ... kN"
             * 
             * OBS: Se não houver chaves em [x,y], imprimir: "clientes no intervalo [x,y]: nenhum"
             */
            getchar();
            scanf("%d %d", &inStart, &inEnd);
            printf("\t----------Buscando Clientes em Intervalo----------\n"
                    "\tInicio: %d\n"
                    "\tFim: %d\n", inStart, inEnd);
            
        }

        scanf("%s", cmd);
    }
}