#include<stdio.h>

int main()
{
    int cupL = 0, cupM = 0, cupR = 0, x, count, Checker = 0;
    char changer1, changer2, sstart;
       scanf("%d %c",&count ,&sstart);

    if (sstart=='L')
    {
        cupL = 1;
    }
    else if (sstart=='R')
    {
        cupR = 1;
    }
    else 
    {
        cupM = 1;
    }

    while (count >= 1)
    {
           scanf(" %c %c", &changer1, &changer2);
           
        if (Checker==0 && changer1 == 'L' || changer2 == 'L')
        {
            if (Checker==0 && changer1 == 'R' || changer2 == 'R')
            {
                x = cupL;
                cupL = cupR;
                cupR = x;
            }
            if (Checker==0 && changer1 == 'M' || changer2 == 'M')
            {
                x = cupL;
                cupL = cupM;
                cupM = x;
            }
            Checker = 1;
        }
    
        if (Checker==0 && changer1 == 'M' || changer2 == 'M')
        {
            if (Checker==0 && changer1 == 'R' || changer2 == 'R')
            {
                x = cupM;
                cupM = cupR;
                cupR = x;
            }
            if (Checker==0 && changer1 == 'L' || changer2 == 'L')
            {
                x = cupM;
                cupM = cupL;
                cupL = x;
            }
            Checker = 1;
        }

        if (Checker==0 && changer1 == 'R' || changer2 == 'R')
        {
            if (Checker==0 && changer1 == 'L' || changer2 == 'L')
            {
                x = cupR;
                cupR = cupL;
                cupL = x;
            }
            if (Checker==0 && changer1 == 'M' || changer2 == 'M')
            {
                x = cupR;
                cupR = cupM;
                cupM = x;
            }
            Checker = 1;
        }
        Checker = 0;
        count--;
    }

    if (cupL==1)
    {
        printf("L");
    }
    else if (cupM==1)
    {
        printf("M");
    }
    else
    {
        printf("R");
    }
}