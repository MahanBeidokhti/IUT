#include<stdio.h>

int mypow(int num, int exp);
int digit(int num);
int isArm(int num);

int main()
{
    int number;
    scanf("%d", &number);
    if (isArm(number)==number)
    {
        printf("Yes");
        return 0;
    }
    printf("No");

}


int mypow(int num, int exp)
{
    if (exp==0)
    {
        return 1;
    }
    return (num * mypow(num , exp-1));
}

int digit(int num)
{
    int digit=1;
    while (num>=10)
    {
        digit+=1;
        num/=10;
    }
    return digit;
}

int isArm(int num)
{
    int sum=0, digits, yekan;
    digits = digit(num);
    for (int i=1; i<=digits; i++)
    {
        yekan = num%10;
        sum += mypow(yekan, 3);
        num/=10;
    }
    return sum;
}