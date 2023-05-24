#include <stdio.h>
#include <stdlib.h>

#include "constructTree.h"

int main() {
    char *preOrder, *inOrder;
    long int sizePreOrder, sizePreOrderMax, sizeInOrder, sizeInOrderMax;
    char c;
    while(1) {
        preOrder = malloc(sizeof(char));
        inOrder = malloc(sizeof(char));
        sizePreOrder = 0, sizePreOrderMax = 1;
        sizeInOrder = 0, sizeInOrderMax = 1;

        c = getchar();
        if(c == '\n' || c == EOF)
            return 0;
        preOrder = insertArray(preOrder, &sizePreOrder, &sizePreOrderMax, c);
        while((c = getchar()) != ' ') {
            preOrder = insertArray(preOrder, &sizePreOrder, &sizePreOrderMax, c);
        }
        while((c = getchar()) != '\n') {
            inOrder = insertArray(inOrder, &sizeInOrder, &sizeInOrderMax, c);
        }
        // printArray(preOrder, sizePreOrder);
        // printArray(inOrder, sizeInOrder);

        int index = 0;
        node* T = constructTree(preOrder, inOrder, 0, sizePreOrder - 1, &index);
        printPostOrder(T);
        printf(" ");
        printBreadth(T);
        // bt_dot_print(T);

        freeTree(T);
        free(preOrder);
        free(inOrder);
    }
}