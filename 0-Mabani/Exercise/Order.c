#include<stdio.h>

int main()
{
    int N1, N2, N3, d;
    char A,B,C;
    scanf("%d %d %d %c%c%c", &N1, &N2, &N3, &A, &B, &C);
   
    if (N2<N1)
        {
        d = N1;
        N1 = N2;
        N2 = d;
        }
    if (N3<N2)
        {
        d = N2;
        N2 = N3;
        N3 = d;
        }
    if (N2<N1)
        {
        d = N1;
        N1 = N2;
        N2 = d;
        }
    
    if (A=='A')
        {
        if (B=='B')
            {
            printf("%d %d %d",N1,N2,N3);   
            }
        else
            {    
            printf("%d %d %d",N1,N3,N2);
            }
        }
    else
        {
        if (B=='B')
            {
            printf("%d %d %d",N3,N2,N1);   
            }
        else
            {
            if (C=='C')
                {
                printf("%d %d %d",N2,N1,N3);
                }
            else 
                {
                if (A=='B')
                    {
                   printf("%d %d %d",N2,N3,N1);
                    }
                else
                    {
                    printf("%d %d %d",N3,N1,N2);
                    }
                }
            }
        }

    return 0;
}