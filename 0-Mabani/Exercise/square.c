#include<stdio.h>

int main()
{
    int a,b,d,i=1,j1=1,j2=1;
    
    scanf("%d%d", &a,&b);

    if (a<=b)
    {
        printf("Wrong order!");
    }

    else if ((a-b)%2==1)
    {
        printf("Wrong difference!");
    }
    
    else
    {
        d = (a-b)/2;
        while(j1<=d)
        {
            while (i <= a)
            {
                printf("* ");
                i++;
            }
            i=1;
            printf("\n");
            ++j1;
        }
        
        i = 1; j1 = 1; j2 = 1;

        while(j2<=b)
        {
            while(i<=d)
            {
                printf("\* ");
                i++;
            }
            i = 1;
            while(i<=b)
            {
                printf("  ");
                i++;
            }
            i = 1;
            while(i<=d)
            {
                printf("\* ");
                i++;
            }
            printf("\n");
            i = 1;
            j2++;
        }

        i = 1; j1 = 1; j2 = 1;

        while(j1<=d)
        {
            while (i <= a)
            {
                printf("* ");
                i++;
            }
            i=1;
            printf("\n");
            ++j1;
        }
    }

}