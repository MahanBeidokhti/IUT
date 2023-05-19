#include<stdio.h>
#include<math.h>

int main()
{
    int digit1, digit2, num1, num2, num3, counter = 1, counter2, sum=0, tavan=1;
    scanf("%d %d", &num1 , &num2);
    num3 = num1;
    if (num1==0 && num2==0)
    {
        printf("00");
    }
    else if(num1==0 && num2!=0)
    {
        printf("0");
    }

    while (num3>=10)
        {
            counter++;
            num3/=10;
        }


    for (counter=counter; counter>=1; counter--)
    {
        
        for (counter2=counter; counter2>1; counter2--)
        {
            tavan*=10;
        }

        digit1 = num1/tavan;
        digit2 = num2/tavan;

        sum*=100;
        sum+= (digit1*10 + digit2);

        num1%=tavan;
        num2%=tavan;
        tavan = 1;

    }


    if(sum!=0)
    {
        printf("%d", sum);
    }
}