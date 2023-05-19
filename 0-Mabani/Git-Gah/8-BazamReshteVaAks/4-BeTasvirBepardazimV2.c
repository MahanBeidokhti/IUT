#include <stdio.h>
#include <malloc.h>
int main()
{
    int pic_size , pic[256][256], kern_size, kern[256][256], sum=0, result[256][256];
    
    scanf("%d",&pic_size);
    for(int i=0 ; i<pic_size ; i++)
    {
        for(int j=0 ; j<pic_size ; j++)
        {
            scanf("%d",&pic[i][j]);
        }
    }
    scanf("%d",&kern_size);
    for(int i=0 ; i<kern_size ; i++)
    {
        for(int j=0 ; j<kern_size ; j++)
        {
            scanf("%d",&kern[i][j]);
        }
    }

    for(int i=0 ; i<pic_size ; i++)
    {
        for(int j=0 ; j<pic_size ; j++)
        {
            result[i][j]=0;
        }
    }

    for(int i=0 ; i<=pic_size-kern_size ; i++)
    {
        for(int j=0 ; j<=pic_size-kern_size ; j++)
        {
            for(int k=0 ; k<kern_size ; k++)
            {
                for(int t=0 ; t<kern_size ; t++)
                {
                    sum += pic[k+i][t+j] * kern[k][t];
                }
            }
         result[i+1][j+1]=sum;
         sum=0;
        }
    }
    for(int i=0 ; i<pic_size ; i++)
    {
        for(int j=0 ; j<pic_size ; j++)
        {
            if(result[i][j]<0 )
                printf("0 ");
            else if( result[i][j]>255)
                printf("255 ");
            else 
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
    return 0;
}