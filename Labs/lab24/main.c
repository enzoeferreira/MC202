#include <stdio.h>
#include <stdlib.h>

/**
 * Printa um array dinâmico
 * 
 * @param array array dinâmico
 * @param size tamanho atual do array
 */
void print(char* array, long int size) {
    for(int i = 0; i < size; i++)
        printf("%c ", *(array + i));
    printf("\n");
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
char* insert(char* array, long int* size, long int* sizeMax, char c) {
    if(*size < *sizeMax) {
        // Espaço suficiente para adicionar
        *(array + (*size)) = c;
        (*size)++;
        return array;
    } else {
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
}

int main() {
    char *preOrder = malloc(sizeof(char));
    char *inOrder = malloc(sizeof(char));
    long int sizePreOrder = 0, sizePreOrderMax = 1, sizeInOrder = 0, sizeInOrderMax = 1;
    
    char c;
    while((c = getchar()) != ' ') {
        preOrder = insert(preOrder, &sizePreOrder, &sizePreOrderMax, c);
    }
    while((c = getchar()) != '\n') {
        inOrder = insert(inOrder, &sizeInOrder, &sizeInOrderMax, c);
    }
    print(preOrder, sizePreOrder);
    print(inOrder, sizeInOrder);
}