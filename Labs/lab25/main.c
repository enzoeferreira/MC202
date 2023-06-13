#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binarySearchTree.h"

int main() {
    client *T, *c;
    unsigned short existingTree = 0;
    int inKey, inStart, inEnd, count;
    float inScore;
    char cmd[MAXCMD], inName[MAXNAME];

    scanf("%s", cmd);
    while(strcmp(cmd, "terminar")) {
        if(!strcmp(cmd, "criar")) {
            /**
             * Criar uma árvore binária de busca vazia.
             * Se já houver uma árvore sendo processada, todos os nós dela devem ser removidos.
             */
            if(existingTree) {
                freeTree(T);
                existingTree = 0;
            }
            else {
                T = startTree();
                existingTree = 1;
            }

        } else if(!strcmp(cmd, "inserir")) {
            /**
             * Formato: "inserir k, nome, pontuacao"
             * Inserir registro do cliente de key 'k', name 'nome', score 'pontuacao' na árvore.
             * 
             * OBS: Se k já estiver na árvore, o programa não faz nada.
             * OBS: Se não houver memória, o programa imprime "memoria insuficiente" e continua.
             */
            getchar();
            scanf("%d, %[^,], %f", &inKey, inName, &inScore);
            // printf( "\t----------Inserindo Cliente----------\n"
            //         "\tKey: %d\n"
            //         "\tNome: %s\n"
            //         "\tScore: %0.2f\n", inKey, inName, inScore);
            c = createClient(T, inKey, inName, inScore);
            if(c) {
                // printf("\tCliente criado: %s (%d) -> %.2f\n", c->name, c->key, c->score);
                // printf("\tCliente sendo inserido...\n");
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
            // printf("\t----------Removendo Cliente----------\n"
            //         "\tKey: %d\n", inKey);
            T = deleteClient2(T, inKey);
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
            // printf("\t----------Buscando Cliente----------\n"
            //         "\tKey: %d\n", inKey);
            c = searchClient(T, inKey);
            if(c)
                printf("cliente %d: %s, %.2f pontos\n", c->key, c->name, c->score);
            // if(c->key == 2147483647) {
            //     bt_dot_print(T);
            //     return;
            // }
            else
                printf("nao ha cliente %d\n", inKey);
            
        } else if(!strcmp(cmd, "imprimir")) {
            /**
             * Imprimir os nomes e chaves dos clientes Em-Ordem
             * Formato de impressão: "clientes: nome1 (k1) nome2 (k2) ... nomeN (kN)"
             * 
             * OBS: Se a árvore estiver vazia, imprimir: "arvore vazia"
             */
            if(T->key == -__INT32_MAX__)
                printf("arvore vazia\n");
            else {
                printf("clientes: ");
                print(T);
                printf("\n");
            }
            
        } else if(!strcmp(cmd, "minimo")) {
            /**
             * Imprimir a menor chave na árvore
             * Formato de impressão: "minimo: k"
             * 
             * OBS: Se a árvore estiver vazia, imprimir: "arvore vazia"
             */
            printf("minimo: %d\n", min(T));
            
        } else if(!strcmp(cmd, "maximo")) {
            /**
             * Imprimir a maior chave na árvore
             * Formato de impressão: "maximo: k"
             * 
             * OBS: Se a árvore estiver vazia, imprimir: "arvore vazia"
             */
            printf("maximo: %d\n", max(T));
            
        } else if(!strcmp(cmd, "sucessor")) {
            /**
             * Formato: "sucessor k"
             * Imprimir: "sucessor de k: z"
             * 
             * OBS: Se não tiver sucessor, imprimir: "sucessor de k: nao ha"
             * OBS: Se k não estiver na árvore, imprimir: "nao ha cliente k"
             */
            getchar();
            scanf("%d", &inKey);
            int suc = sucessor(T, inKey);
            if(suc != -__INT32_MAX__)
                printf("sucessor de %d: %d\n", inKey, suc);
            else
                printf("sucessor de %d: nao ha\n", inKey);
            
        } else if(!strcmp(cmd, "predecessor")) {
            /**
             * Formato: "predecessor k"
             * Imprimir: "predecessor de k: z"
             * 
             * OBS: Se não tiver sucessor, imprimir: "predecessor de k: nao ha"
             * OBS: Se k não estiver na árvore, imprimir: "nao ha cliente k"
             */
            getchar();
            scanf("%d", &inKey);
            int pred = predecessor(T, inKey);
            if(pred != -__INT32_MAX__)
                printf("predecessor de %d: %d\n", inKey, pred);
            else
                printf("predecessor de %d: nao ha\n", inKey);
            
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
            // printf("\t----------Buscando Clientes em Intervalo----------\n"
            //         "\tInicio: %d\n"
            //         "\tFim: %d\n", inStart, inEnd);
            printf("clientes no intervalo [%d,%d]: ", inStart, inEnd);
            count = 0;
            printRange(T, inStart, inEnd, &count);
            if(!count)
                printf("nenhum");
            printf("\n");
        }

        scanf("%s", cmd);
    }
    if(existingTree)
        freeTree(T);
}