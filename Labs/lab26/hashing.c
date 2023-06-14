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
	for (unsigned int i = 0; i < size; str++, i++)
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
 * Utiliza sondagem com incremento por hashing dupla para calcular o hash de uma string
 * h1: djb2
 * h2: sdbm
 * 
 * @param T tabela hash
 * @param str string que entrará na função de hashing
 * @param count contagem de colisões
 * 
 * @return hash da string
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

    for(unsigned long i = 0; i < maxSize; i++)
                    T->array[i].key = -1; // Marca posições como vazias
                    
    return T;
}

/**
 * Insere uma string na tabela hash
 * 
 * @param T tabela hash
 * @param str string a ser adicionada
 * @param timestamp timestamp a ser adicionada ou -1 caso vá usar a da tabela
 * 
 * @return 1) 0, caso string já esteja na tabela
 * @return 2) 1, caso string seja inserida na tabela
 */
short int insertString(hashTable* T, unsigned char* str, long timestamp) {
    unsigned long count = 0;
    unsigned long hash = hashing(T, str, count);
    while(T->array[hash].key != -1) {
        if(!strcmp((const char *)T->array[hash].string, (const char *)str)) // String encontrada
            return 0;
        hash = hashing(T, str, ++count);
    }
    T->array[hash].key = 0;
    strcpy((char *)T->array[hash].string, (char *)str);

    if(timestamp == -1)
        T->array[hash].timestamp = T->timestamp++;
    else
        T->array[hash].timestamp = (unsigned long)timestamp;

    T->size++;
    return 1;
}

/**
 * Cria uma tabela de hashing nova com o dobro do tamanho da anterior
 * Faz a cópia de todos os elementos, mantendo a timestamp anterior
 * 
 * @param T tabela de hashing a ser atualizada
 * 
 * @return 1) NULL, caso não seja possivel alocar espaço para tabela nova
 * @return 2) newT, nova tabela de hash com o dobro do tamanho
 */
hashTable* updateTable(hashTable* T) {
    hashTable *newT = createTable(2*T->maxSize);
    if(!newT)
        return NULL;
    newT->timestamp = T->timestamp; // Continua timestamp
    for(unsigned int i = 0; i < T->maxSize; i++) {
        if(T->array[i].key != -1)
            insertString(newT, T->array[i].string, T->array[i].timestamp);
    }
    free(T->array);
    free(T);
    return newT;
}

/**
 * Remove uma string da tabela hash
 * 
 * @param T tabela hash
 * @param str string a ser removida
 * 
 * @return 1) 0, caso string não seja encontrada
 * @return 2) 1, caso string foi encontrada e removida
 */
short int removeString(hashTable* T, unsigned char* str) {
    unsigned long count = 0;
    unsigned long hash = hashing(T, str, count);
    while(T->array[hash].key != -1) {
        if(!strcmp((const char *)T->array[hash].string, (const char *)str)) {  // String encontrada
            T->array[hash].key = -1; // Marca posição como vazia
            T->size--;
            return 1;
        }
        hash = hashing(T, str, ++count);
    }
    return 0;
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
long searchString(hashTable* T, unsigned char* str) {
    unsigned long count = 0;
    unsigned long hash = hashing(T, str, count);
    while(T->array[hash].key != -1) {
        if(!strcmp((const char *)T->array[hash].string, (const char *)str)) // String encontrada
            return (long)T->array[hash].timestamp;
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
    for(unsigned long i = 0; i < T->maxSize; i++) {
        if(T->array[i].key == -1)
            printf("[%lu] vazio\n", i);
        else
            printf("[%lu] %s (%li): t = %lu\n", i, T->array[i].string, T->array[i].key,
                                                  T->array[i].timestamp);
    }
}

int main() {
    unsigned short existingTable = 0;
    unsigned long maxSize;
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
            }
            break;

            case 'i': { // Inserção de string na tabela hash
                scanf("%[^\n]", string);
                getchar();
                if(T->size > (0.7*T->maxSize)) // Tabela está ocupando mais de 70% do espaço
                    T = updateTable(T);
                insertString(T, (unsigned char *)string, -1);
            }
            break;

            case 'r': { // Remove string da tabela hash
                scanf("%[^\n]", string);
                getchar();
                removeString(T, (unsigned char *)string);
            }
            break;

            case 'b': { // Imprime a timestamp da string
                scanf("%[^\n]", string);
                getchar();
                long timestamp = searchString(T, (unsigned char *)string);
                if(timestamp == -1) // String não encontrada
                    printf("[%s] nao esta na tabela\n", string);
                else
                    printf("[%s] esta na tabela, timestamp %li\n", string, timestamp);
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
    if(existingTable) {
        free(T->array);
        free(T);
    }
}