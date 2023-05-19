#include<stdio.h>

int main()
{
    int ghotr, i = 1 , j = 1 , i2 = 1 , n = 1;

    scanf("%d",&ghotr);

    while(j <= (ghotr/2)+1)
    {
        while (i2 <= 2)
        {
            while (i <= (ghotr-n)/2)
            {
                printf(" ");
                i++;
            }
            i = 1;
            while (i <= n)
            {
                printf("*");
                i++;
            }
            i = 1;
            while (i <= (ghotr-n)/2)
            {
                printf(" ");
                i++;
            }
            i = 1;
            i2++;
        }
        i2 = 1;
        n+=2;
        printf("\n");
        j++;
    }
    n-=4;
    j = 1;
    while(j <= ghotr/2)
    {
        while (i2 <= 2)
        {
            while (i <= (ghotr-n)/2)
            {
                printf(" ");
                i++;
            }
            i = 1;
            while (i <= n)
            {
                printf("*");
                i++;
            }
            i = 1;
            while (i <= (ghotr-n)/2)
            {
                printf(" ");
                i++;
            }
            i = 1;
            i2++;
        }
        i2 = 1;
        n-=2;
        printf("\n");
        j++;
    }
}