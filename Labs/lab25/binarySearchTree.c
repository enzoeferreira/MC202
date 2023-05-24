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

struct tree {
    client *root;
};
typedef struct tree tree;

/**
 * Cria uma árvore binária
 * 
 * @return 1) NULL, caso falha em alocar espaço para árvore
 * @return 2) T, apontador para árvore
 */
tree* startTree() {
    tree *T = malloc(sizeof(tree));
    if(!T)
        return NULL;
    
    client *r = malloc(sizeof(client));
    if(!r)
        return NULL;

    T->root = r;
    T->root->key = NULL;
    T->root->left = NULL;
    T->root->right = NULL;
    return T;
}

/**
 * Libera o espaço de memória alocado para uma árvore binária e todos os seus nós
 * 
 * @param T árvore binária
 */
void* freeTree(tree* T) {
    if(!T->root)
        return;
    freeTree(T->root->left);
    freeTree(T->root->right);
    free(T);
}

int main() {
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