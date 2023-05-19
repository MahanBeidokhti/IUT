#include<stdio.h>

int tartib(int num)
{
    scanf("%d", &num);

    if (num==0)
    {
        return 0;
    }
    tartib(num);
    printf("%d\n", num);
    return 0;
}

int main()
{
    tartib(1);
}