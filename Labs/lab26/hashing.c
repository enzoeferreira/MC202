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

/**
 * Utiliza sondagem com incremento por hashing dupla para calcular o hash de uma cadeia
 * h1: djb2
 * h2: sdbm
 * 
 * @param T tabela hash
 * @param str cadeia que entrará na função de hashing
 * @param count contagem de colisões
 * 
 * @return hash da cadeia
 */
unsigned long hashing(hashTable* T, unsigned char* str, unsigned long count) {
    return ((djb2(str) + (count * sdbm(str))) % T->maxSize);
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

/**
 * Insere uma cadeia na tabela hash
 * 
 * @param T tabela hash
 * @param str cadeia a ser adicionada
 * 
 * @return 1) 0, caso cadeia já esteja na tabela
 * @return 2) 1, caso cadeia seja inserida na tabela
 */
short int insert(hashTable* T, unsigned char* str) {
    unsigned long count = 0;
    unsigned long hash = hashing(T, str, count);
    while(T->array[hash].key != -1) {
        if(!strcmp(T->array[hash].string, str)) // String encontrada
            return 0;
        hash = hashing(T, str, ++count);
    }
    T->array[hash].key = 0;
    strcpy(T->array[hash].string, str);
    T->array[hash].timestamp = T->timestamp++;
    return 1;
}

/**
 * Procura na tabela de hash por uma string, retornando sua timestamp caso encontre
 * 
 * @param T tabela de hash
 * @param str string a ser encontrada
 * 
 * @return 1) -1, caso a string não esteja na tabela
 * @return 2) timestamp da string
 */
unsigned long search(hashTable* T, unsigned char* str) {
    unsigned long count = 0;
    unsigned long hash = hashing(T, str, count);
    while(T->array[hash].key != -1) {
        if(!strcmp(T->array[hash].string, str)) // String encontrada
            return T->array[hash].timestamp;
        hash = hashing(T, str, ++count);
    }
    return -1; // String não encontrada
}

/**
 * Printa a tabela hash no formato:
 * 1) ['pos'] vazio
 * 2) ['pos'] 'string' ('key'): t = 'timestamp'
 * 
 * @param T tabela hash
 */
void print(hashTable* T) {
    for(int i = 0; i < T->maxSize; i++) {
        if(T->array[i].key == -1)
            printf("[%d] vazio\n", i);
        else
            printf("[%d] %s (%d): t = %d\n", i, T->array[i].string, T->array[i].key, T->array[i].timestamp);
    }
}

int main() {
    unsigned short existingTable = 0;
    unsigned long maxSize, count, timestamp;
    char cmd, string[MAXSTRING];
    hashTable *T;

    cmd = getchar();
    while(cmd != 'f') {
        getchar(); // Retira espaço

        switch(cmd) {
            case 'c': { // Criação de tabela hash
                if(existingTable) {
                    free(T->array);
                    free(T);
                }
                scanf("%lu", &maxSize);
                getchar();
                T = createTable(maxSize);
                for(int i = 0; i < maxSize; i++)
                    T->array[i].key = -1; // Marca posições como vazias
            }
            break;

            case 'i': { // Inserção de cadeia na tabela hash
                scanf("%[^\n]", string);
                getchar();
                short int unique = insert(T, string);
                if(!unique)
                    printf("\tELEMENTO REPETIDO.\n");
            }
            break;

            case 'r': { // Remove cadeia da tabela hash

            }
            break;

            case 'b': { // Imprime a timestamp da cadeia
                scanf("%[^\n]", string);
                getchar();
                timestamp = search(T, string);
                if(timestamp == -1) // String não encontrada
                    printf("[%s] nao esta na tabela\n", string);
                else
                    printf("[%s] esta na tabela, timestamp %d\n", string, timestamp);
            }
            break;

            case 'p': { // Print da tabela hash para debug
                print(T);
            }
            break;
        }

        cmd = getchar(); // Novo comando
    }

    // Libera memória alocada
    free(T->array);
    free(T);
}