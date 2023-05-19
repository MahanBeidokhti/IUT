#include<stdio.h>

int fibonatchi(int times)
{   
    return (times == 0 || times == 1) ? 1 : fibonatchi(times - 1) + fibonatchi(times - 2);
}

int main()
{
    int time;
    scanf("%d", &time);
    printf("%d", fibonatchi(time-1));
}