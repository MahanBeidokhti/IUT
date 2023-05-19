#include <stdio.h>
int main()
{
    int num,i,j,counter=0;
    scanf("%d",&num);
    
    for (i=1;i<=4*num+1;i++)
    {
        for(j=1;j<=8*num+1;j++)
        {
            if(num%2!=0)
            {
                if((i+j)%8==6||(j-i)%8==4||i==4*counter+1||(j-i)%8==-4)
                {
                    if(4*num+1<(i+j)&&(j-i)<4*num+1)
                    printf("*");
                    else if((j-i)<4*num+1)
                    printf(" ");
                    
                }
                else if((j-i)<4*num+1)
                printf(" ");
                
            }
            else
            {
                if((i+j)%8==2||(j-i)%8==0||i==4*counter+1)
                {
                    if(4*num+1<(i+j)&&(j-i)<4*num+1)
                    printf("*");
                    else if((j-i)<4*num+1)
                    printf(" ");
                }
                else if((j-i)<4*num+1)
                printf(" ");
            }
            
        }
        printf("\n");
        
        if(i%4==0)
        counter++;
    }
}