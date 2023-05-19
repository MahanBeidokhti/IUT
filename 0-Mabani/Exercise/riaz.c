#include<stdio.h>
#include<math.h>

int main()
{
    int fac, i, i2, i3 , count, num22, num , num3;
    float num2=0;

    scanf("%d %d", &num, &count);
    num3 = num;

    for (i2 = 2; i2<=count; i2++)
    {
        fac = 1;

        for(i=2;i<i2;i++)
        {
            fac = fac * i;
        }
        
        for (i3=2;i3<i2;i3++)
        {
            num3 = num3 * num3;
        }

        num2 = num2 + num3/fac;
    }

    num2 += 1;
    
    num22 = (int)(1000 * num2 - ( 1000 * (int)num2));

    if (num22 % 1<=999)
    {
        num2 = (float)((int)num2+1);
    }

    printf("%f", num2);
}