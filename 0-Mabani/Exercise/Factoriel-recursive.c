#include<stdio.h>

int factoriel(int number)
{
    if (number==1)
    {
        return 1;
    }
    return (number * factoriel(number - 1));
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", factoriel(n));
}