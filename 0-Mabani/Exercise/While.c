#include<stdio.h>>

void main()
{
    int counter=1,fib1=1,fib2=1,akbar;
    while(fib2 < 1000)
    {
        akbar = fib2;
        fib2 = fib1 + fib2;
        fib1 = akbar;
    }
    printf("last fibonachi number behind 1000 %d",fib1);
}