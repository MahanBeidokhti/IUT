#include<stdio.h>

int prime(int x)
{
    int  counter, count=0;

    for (counter = 2; counter<x;counter++)
    {
        if (x%counter==0)
        {
            count=1;
            printf("%d not prime\n", counter);
            break;
        }
        if (counter==x-1){
            printf("%d is prime\n", counter);
        }
    }
}

int main()
{
    int  counter;

    for (counter = 1 ; counter <= 100; counter++)
    {
        prime(counter);
    }
}