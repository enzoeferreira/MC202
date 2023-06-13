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

struct hashTable {
    triplet *array;
    unsigned long size, maxSize, timestamp;
};
typedef struct hashTable hashTable;

unsigned long sdbm(unsigned char* str) {
    unsigned int size = strlen((const char *)str);
    unsigned int hash = 0;
	unsigned int i = 0;

	for (i = 0; i < size; str++, i++)
		hash = (*str) + (hash << 6) + (hash << 16) - hash;

	return hash;
}

unsigned long djb2(unsigned char* str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
    hash = ((hash << 5) + hash) ^ c; // hash * 33 XOR c

    return hash;
}

unsigned long hashing(hashTable* T, unsigned char* str, unsigned long* count) {
    return (djb2(str) + (*count) * sdbm(str)) % T->maxSize;
}

/**
 * Cria uma tabela hash de triplas com o tamanho dado
 * 
 * @param maxSize tamanho da tabela hash
 * 
 * @return 1) NULL, caso falhe em alocar memória para tabela
 * @return 2) T, apontador para tabela hash
 */
hashTable* createTable(unsigned long maxSize) {
    hashTable *T = malloc(sizeof(hashTable));
    if(!T)
        return NULL;
    triplet *array = malloc(maxSize * sizeof(triplet));
    if(!array)
        return NULL;
    
    T->array = array;
    T->size = 0;
    T->maxSize = maxSize;
    T->timestamp = 0;
    return T;
}

int main() {
    unsigned short existingTable = 0;
    unsigned long maxSize, count;
    char cmd, string[MAXSTRING];
    hashTable *T;

    cmd = getchar();
    while(cmd != 'f') {
        getchar(); // Retira espaço

        switch(cmd) {
            case 'c':
            printf("CRIANDO tabela hash\n");
            if(existingTable) {
                free(T->array);
                free(T);
            }
            scanf("%lu", &maxSize);
            T = createTable(maxSize);
            for(int i = 0; i < maxSize; i++)
                T->array[i].key = -1; // Marca posições como vazias
            for(int i = 0; i < maxSize; i++)
                printf("posicao %d: %d\n", i, T->array[i].key);

            break;

            case 'i':
            printf("INSERINDO cadeia na tabela hash\n");
            scanf("%[^\n]", string);
            count = 0;
            printf("%d", hashing(T, string, &count));
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