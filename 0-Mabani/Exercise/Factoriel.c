#include<stdio.h>

int main()
{
    int num, num2, counter=1, num3;
    scanf("%d", &num);
    num2 = num;
    num3 = num;
    while (counter < num3)
    {
        num-=1;
        num2 = num2 * num;
        counter++;
    }
    printf("%d ",num2);
}