#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTRING 251
#define INITIALTABLESIZE 128

struct triplet {
    unsigned char string[MAXSTRING];
    unsigned long timestamp;
    long key;
};
typedef struct triplet triplet;

unsigned long sdbm(unsigned char *str) {
    unsigned int size = strlen((const char *)str);
    unsigned int hash = 0;
	unsigned int i = 0;

	for (i = 0; i < size; str++, i++)
		hash = (*str) + (hash << 6) + (hash << 16) - hash;

	return hash;
}

unsigned long djb2(unsigned char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
    hash = ((hash << 5) + hash) ^ c; // hash * 33 XOR c

    return hash;
}

/**
 * Cria uma tabela hash de triplas com o tamanho dado
 * 
 * @param maxSize tamanho da tabela hash
 * 
 * @return 1) NULL, caso falhe em alocar memória para tabela
 * @return 2) T, apontador para tabela hash
 */
triplet* createTable(unsigned long maxSize) {
    triplet *T = malloc(maxSize * sizeof(triplet));
    if(!T)
        return NULL;
    return T;
}

int main() {
    unsigned short existingTable = 0;
    unsigned long size, maxSize, timestamp;
    char cmd;
    triplet *T;

    cmd = getchar();
    while(cmd != 'f') {
        getchar(); // Retira espaço

        switch(cmd) {
            case 'c':
            printf("CRIANDO tabela hash\n");
            if(existingTable)
                free(T);
            scanf("%lu", &maxSize);
            T = createTable(maxSize);
            size = 0;
            existingTable = 1;
            timestamp = 0;
            for(int i = 0; i < maxSize; i++)
                T[i].key = -1; // Marca posições como vazias

            break;

            case 'i':
            printf("INSERINDO cadeia na tabela hash\n");

            break;

            case 'r':
            printf("REMOVENDO cadeia da tabela hash\n");
            break;

            case 'b':
            printf("IMPRIMINDO TIMESTAMP de cadeia na tabela hash\n");
            break;
        }

        free(T);
        cmd = getchar();
    }
}