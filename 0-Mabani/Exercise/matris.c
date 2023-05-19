#include <stdio.h>
#include <math.h>

float determinan(float array[200][200], int num);

int main()
{
    float array[200][200], res;
    int n,num1,num2;

    scanf("%d", &n);

    for(num1=0 ; num1<n ; num1++)
    {
        for(num2=0 ; num2<n ; num2++)
        {
            scanf("%f",&array[num1][num2]);
        }
    }

    printf("%.2f", determinan(array,n));
}


float determinan(float array[200][200], int num)
{
    float minor[200][200], det=0;
    int num1,num2,num3,counter1,counter;

    if(num==2)
    {
        det = array[0][0]*array[1][1] - array[0][1]*array[1][0] ;
        return det;
    }

    for(num1=0 ; num1<num ; num1++)
    {
        counter1=0,counter=0;
        for(num2=0 ; num2<num ; num2++)
        {
            for(num3=0 ; num3<num ; num3++)
            {
                if(num2!=0 && num3!=num1)
                {
                    minor[counter1][counter]=array[num2][num3];
                    counter=counter+1;
                    if(counter>num-2)
                    {
                        counter1++;
                        counter=0;
                    }
                }
            }
        }
        det +=  array[0][num1] * pow(-1,num1) * determinan(minor,num-1);
    }
    return det;
}