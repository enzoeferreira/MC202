#include <stdio.h>

int main()
{
    int i = 11;
    float r = i / 2;    // Dividindo: int / int   -> int
    float s = i / 2.0;  // Dividindo: int / float -> float

    printf("r=%f s=%f\n",r,s); // r=5.000000 s=5.500000
}