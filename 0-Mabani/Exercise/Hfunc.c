#include<stdio.h>

long long int H(int number)
{
    if (number==0)
    {
        return 5;
    }
    if (number==1)
    {
        return -3;
    }
    if (number==2)
    {
        return 1;
    }
    return 3*H(number-1) - 2*H(number-2) + H(number-3);
}

int main()
{
    int num;
    scanf("%d", &num);
    printf("%lld", H(num));
}
