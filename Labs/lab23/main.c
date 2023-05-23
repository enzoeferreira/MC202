#include <stdio.h>
#include <stdlib.h>

#include <slice.h>

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
    sliceList(L, 0, 0); // Remove nós da lista L
    free(L->head);
    free(L->tail);
}