#include<stdio.h>

int main()
{
    long long int sum, num , num2=1, counter=1, counter2;
    scanf("%lld", &num);

    num2 = num;
    sum = num;

    if (num>=10)
    {

        while (num2>=10)
        {
            counter++;
            num2/=10;
        }
    }

    num2 = num;

    while (1)
    {

    if (sum<10)
    {
        break;
    }

    num2 = sum;
    sum = 0;
    // for (counter2=1; counter2 <= counter; counter2++)
    while(num2>=1)
    {
        sum+= num2%10;
        num2/=10;
    }
    }
    printf("%lld", sum);
}