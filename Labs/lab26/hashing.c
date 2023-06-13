#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTRING 101
#define INITIALTABLESIZE 128

struct tuple {
    unsigned char string[MAXSTRING];
    unsigned long timestamp;
};
typedef struct tuple tuple;

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

tuple* createTable(unsigned long maxSize) {
    tuple *T = malloc(maxSize * sizeof(tuple));
    if(!T)
        return NULL;
    return T;
}

int main() {
    unsigned short existingTable = 0;
    unsigned long size, maxSize, timestamp;
    char cmd;
    tuple *T;

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