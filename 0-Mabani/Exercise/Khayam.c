#include<stdio.h>

int triangle(int i, int j)
{
    if (i==1 || i==j)
        return 1;
    return (triangle(i , j-1) + triangle(i-1 , j-1));
}

int main()
{
    int Lines;
    scanf("%d" , &Lines);

    for (int j=1; j<=Lines; j++)
    {
        for (int i=1; i<=j; i++)
        {
            printf("%d ", triangle(i , j));
        }
    printf("\n");
    }
}