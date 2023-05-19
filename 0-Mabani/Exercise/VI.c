#include<stdio.h>

int main()
{
    int num;
    
    scanf("%d", &num);

    while (num >= 1000)
    {
        printf("M");
        num-=1000;
    }
    while(num == 999)
    {
        printf("IM");
        num-=999;
    }
    while (num>=500)
    {
        printf("D");
        num-=500;
    }
    while(num == 499)
    {
        printf("ID");
        num-=499;
    }
    while (num>=100)
    {
        printf("C");
        num-=100;
    }
    while(num == 99)
    {
        printf("IC");
        num-=99;
    }
    while (num>=50)
    {
        printf("L");
        num-=50;
    }
    while(num == 49)
    {
        printf("IL");
        num-=49;
    }
    while (num>=10)
    {
        printf("X");
        num-=10;
    }

    switch (num)
    {
        case 1:
            printf("I");
            break;
        
        case 2:
            printf("II");
            break;
        
        case 3:
            printf("III");
            break;
        
        case 4:
            printf("IV");
            break;
        
        case 5:
            printf("V");
            break;
        
        case 6:
            printf("VI");
            break;
        
        case 7:
            printf("VII");
            break;
        
        case 8:
            printf("VII");
            break;
        
        case 9:
            printf("IX");
            break;
    }
}