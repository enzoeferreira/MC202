#include <stdio.h>

int main()
{
    printf("short %d\n", sizeof(short));
    printf("int %d\n", sizeof(int));
    printf("unsigned int %d\n", sizeof(unsigned int));
    printf("long int %d\n", sizeof(long int));
    printf("unsigned long int %d\n", sizeof(unsigned long int));
    printf("long long int %d\n", sizeof(long long int));
    printf("unsigned long long int %d\n", sizeof(unsigned long long int));
    printf("float %d\n", sizeof(float));
    printf("double %d\n", sizeof(double));
    printf("long double %d\n", sizeof(long double));

    printf("Pressiona ENTER para continuar...");
    getchar();

    return 0;
}