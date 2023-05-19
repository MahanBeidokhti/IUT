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

    for (int jout=Lines; jout>=1; jout--)
    {
        for (int iout=1; iout<=jout; iout++)
        {
            printf("%d ", triangle(iout , jout));
        }
    printf("\n");
    }
}