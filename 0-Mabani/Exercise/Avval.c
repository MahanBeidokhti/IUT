#include<stdio.h>
#include<math.h>

int main()
{
    int a, b, c, d ;

    scanf("%d %d", &a, &b);

    for (c=a ; c<=b; c++)
    {
        for (d=2 ; d<=c ; d++)
        {   
            if (c==2)
            {
                printf("2\n");
            }
            else if (c%d==0 )
            {
                break;
            }
            else if ((c%d!= 0 && d == c - 1) )
            {
                printf("%d\n", c);
        }
        }
    }
}