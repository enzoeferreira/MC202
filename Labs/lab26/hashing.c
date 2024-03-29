#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTRING 251

struct triplet {
    unsigned char string[MAXSTRING];
    unsigned long timestamp;
    short status;
};
typedef struct triplet triplet;

struct hashTable {
    triplet **array;
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
    T->array = (triplet**)malloc(maxSize * sizeof(triplet*));
    
    T->size = 0;
    T->maxSize = maxSize;
    T->timestamp = 0;

    for(unsigned long i = 0; i < maxSize; i++) {
        triplet *tripla = malloc(sizeof(triplet));
        if(!tripla)
            return NULL;
        T->array[i] = tripla;
        T->array[i]->status = -1; // Marca posições como vazias
    }
                    
    return T;
}

/**
 * Libera toda a memória alocada por uma tabela hash, seu array e os elementos VAZIOS de seu array
 * 
 * @param T tabela hash
 */
void freeEmpty(hashTable* T) {
    for(unsigned int i = 0; i < T->maxSize; i++)
        if(T->array[i]->status == -1)
            free(T->array[i]);
    free(T->array);
    free(T);
}

/**
 * Libera toda a memória alocada por uma tabela hash, seu array e os elementos de seu array
 * 
 * @param T tabela hash
 */
void freeTable(hashTable* T) {
    for(unsigned int i = 0; i < T->maxSize; i++)
            free(T->array[i]);
    free(T->array);
    free(T);
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
    while(T->array[hash]->status != -1) {
        if(!strcmp((const char *)T->array[hash]->string, (const char *)str)) // String encontrada
            return 0;
        hash = hashing(T, str, ++count);
    }
    T->array[hash]->status = 0;
    strcpy((char *)T->array[hash]->string, (char *)str);

    if(timestamp == -1)
        T->array[hash]->timestamp = T->timestamp++;
    else
        T->array[hash]->timestamp = (unsigned long)timestamp;

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
    newT->size = T->size;
    for(unsigned int i = 0; i < T->maxSize; i++) {
        if(T->array[i]->status != -1) {
            unsigned long count = 0;
            unsigned long hash = hashing(newT, T->array[i]->string, 0);
            while(newT->array[hash]->status != -1) {
                hash = hashing(newT, T->array[i]->string, ++count);
            }
            newT->array[hash] = T->array[i];
        }
    }
    freeEmpty(T);
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
    while(T->array[hash]->status != -1) {
        if(!strcmp((const char *)T->array[hash]->string, (const char *)str)) {  // String encontrada
            T->array[hash]->status = -1; // Marca posição como vazia
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
    while(T->array[hash]->status != -1) {
        if(!strcmp((const char *)T->array[hash]->string, (const char *)str)) // String encontrada
            return (long)T->array[hash]->timestamp;
        hash = hashing(T, str, ++count);
    }
    return -1; // String não encontrada
}

/**
 * Printa a tabela hash no formato:
 * 1) ['pos'] vazio
 * 2) ['pos'] 'string' ('status'): t = 'timestamp'
 * 
 * @param T tabela hash
 */
void print(hashTable* T) {
    unsigned long trueSize = 0;
    for(unsigned long i = 0; i < T->maxSize; i++) {
        if(T->array[i]->status == -1) 
            printf("[%lu] vazio\n", i);
        else {
            printf("[%lu] %s (%hi): t = %lu\n", i, T->array[i]->string, T->array[i]->status,
                                                   T->array[i]->timestamp);
            trueSize++;
        }
    }
    printf("trueSize = %lu, size = %lu, maxSize = %lu, timestamp = %lu\n",
            trueSize, T->size, T->maxSize, T->timestamp);
}

int main() {
    unsigned short existingTable = 0;
    unsigned long maxSize;
    char cmd, string[MAXSTRING];
    hashTable *T;

    cmd = getchar();
    while(cmd != 'f' && cmd != EOF) {
        getchar(); // Retira espaço

        switch(cmd) {
            case 'c': { // Criação de tabela hash
                if(existingTable)
                    freeTable(T);
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
    if(existingTable)
        freeTable(T);
}