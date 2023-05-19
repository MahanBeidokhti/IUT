#include<stdio.h>

int main()
{
    int a, b, count, Other;
    scanf("%d %d", &a, &b);
    count = (a-b)/10;
    Other = ((a-b)%10+9)/10;
    printf("%d", count+Other);
}