#include<stdio.h>

long double myPow(long double num,int power)
{
    if (power==0)
    {
        return 1;
    }

    return num * myPow(num, power - 1);
}

int main()
{
    long double Base , final;
    unsigned int exp;
    
    scanf("%Lf", &Base);
    scanf("%u", &exp);


    final = myPow(Base, exp);

    printf("%.3Lf", final);
}
