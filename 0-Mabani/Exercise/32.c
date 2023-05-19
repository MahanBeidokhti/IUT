#include<stdio.h>
#include<math.h>

int main()
{
    int repeat, digit, count, counter1=0, counter2=0, A, pcounter=1;
    long long num, num2,ppower =1, B;

    scanf("%d", &repeat);

    for(repeat=repeat;repeat>=1;repeat--)
    {
        scanf("%d\n%lld", &digit , &num);
        num2 = num;

        for(count=digit ; count>=1 ; count--)
        {
            A = num%10;
            if (A==3)
            {
                counter1++;
            }
            else 
            {
                break;
            }
            num = num / 10;

        }
        
        for(count=digit ; count>=1 ; count--)
        {
            while (pcounter < count)
            {
                ppower = ppower *10;
                pcounter++;
            }
            B = num2/ppower;
            if (B==2)
            {
                counter2++;
            }
            else
            {
                break;
            }
            num2 = num2 % ppower;
            ppower = 1;
            pcounter = 1;
        }
    
        // printf("counter1 : %d\ncounter2 : %d\n", counter1, counter2);

        if (counter1+counter2==digit)
        {
            printf("%d\n", counter1+counter2);
        }
        else
        {
            printf("%d\n", counter1+counter2+1);
        }
        counter1 = 0;
        counter2 = 0;

    }
}