#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTRING 101

struct tuple {
    unsigned char string[MAXSTRING];
    unsigned long timestamp;
};
typedef struct tuple tuple;

unsigned long sdbm(unsigned char *str) {
    unsigned int size = strlen(str);
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


int main() {

}