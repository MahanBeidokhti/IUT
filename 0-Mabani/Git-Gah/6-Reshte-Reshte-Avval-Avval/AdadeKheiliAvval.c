#include<stdio.h>
int Prime_Checker(int number)
{
    int counter;
    if (number==2)
        return 1;
    if (number%2==0 || number==0 || number==1)
        return 0;
    for (counter=2;counter<number/2;counter++)
    {
        if (number%counter==0)
            return 0;
    }
    return 1;
}

int main ()
{
    int max, max_backup, flag=0;

    scanf("%d", &max);

    for (int number=2; number<max; number++)
    {
        max_backup = number;

        flag =0;
        if (Prime_Checker(number))
        {
            while (max_backup>=1)
            {
                if (Prime_Checker(max_backup%10)==0)
                {   
                    flag=1;
                    break;
                }
                max_backup /= 10;
            }
            if (flag==0)
                printf("%d ", number);
        }
    }
}