#include<stdio.h>

int main()
{
    float Z1, Z2, Z3;

    scanf("%f%f%f",&Z1 ,&Z2 ,&Z3);
    if (Z1<Z2+Z3 && Z1+Z2>Z3 && Z1+Z3>Z2)
    {
        if (Z1*Z1 + Z2*Z2==Z3*Z3 || Z1*Z1 == Z2*Z2 + Z3*Z3 || Z1*Z1 + Z3*Z3 == Z2*Z2)
        {
            printf("RT");
        }
        else
        {
            printf("T");
        }
    }
    else
    {
        printf("N");
    }
}