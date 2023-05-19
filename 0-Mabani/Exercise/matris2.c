#include <stdio.h>

int main()
{
    int num1, num2, num3, i, j, count, jam;

    scanf("%d %d %d",&num1,&num2,&num3);

    int array1[num1][num2], array2[num2][num3], array3[num1][num3];
    
    for(i=0 ; i<num1 ; i++)
    {
        for(j=0 ; j<num2 ; j++)
        {
            scanf("%d",&array1[i][j]);
        }
        printf("\n");
    }

    for(i=0 ; i<num2 ; i++)
    {
        for(j=0 ; j<num3 ; j++)
        {
            scanf("%d",&array2[i][j]);
        }
        printf("\n");
    }


    for(i=0 ; i<num1 ; i++)
    {
        for(j=0 ; j<num3 ; j++)
        {
            jam=0;

            for (count=0 ; count<num2 ; count++)
            {
                jam+=array1[i][count]*array2[count][j];
            }
            array3[i][j]=jam;
        }

    }


    for(i=0 ; i<num1 ; i++)
    {
        for(j=0 ; j<num3 ; j++)
        {
            printf("%d\t",array3[i][j]);
        }
        printf("\n");
    }


    return 0;
}
