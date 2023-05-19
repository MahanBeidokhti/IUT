#include<stdio.h>

void ShowFibNth(long int n, long int m)
{
    long int k;
    
    if (n==1 && m==1)
    {
        printf("%d", 1);
        return;
    }

    if (n==1)
    {
        printf("%d\n%d", 1, 1);
        return;
    }

    printf("%ld\n", n);

    k = n;
    n = m - n;
    m = k;

    ShowFibNth(n , m);   
}

int main()
{
    long int num1 , num2;
    scanf("%ld %ld", &num1 , &num2);
    ShowFibNth(num1 , num2);
}