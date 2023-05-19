#include<stdio.h>

void MUL(int number1_size, char number1[number1_size+1], int number2_size, char number2[number2_size+1])
{
    int flag1=0, flag2=0, digit = number1_size+number2_size+1, digit_back = digit, backup;
    int final[digit];

    for (int i=digit; i>=0; i--)
    {
        final[i] = 0;
    }

    for (int i=number2_size;i>=0;i--)
    {
        for (int j=number1_size;j>=0;j--)
        {
            final[digit] = final[digit] + (((int)number1[j]-48) * ((int)number2[i]-48));
            digit--;
            
        }

        digit = digit_back - (number2_size - i + 1);
    }
    digit = digit_back;
    for (int i=digit; i>=0; i--)
    {
        if (final[i]>=10)
        {
            final[i-1] = final[i-1] + final[i]/10;
            final[i]%=10;
        }
    }

    for (int i=0; i<=digit_back; i++)
    {
        printf("%d", final[i]);
    }

}

int main()
{
    char first_num[255]={}, second_num[255]={};
    int first_number_digit=-1, second_number_digit=-1;

    gets(first_num);
    gets(second_num);


    for (int number1_size=0; first_num[number1_size] || second_num[number1_size] ; number1_size++)
    {
        if (first_num[number1_size])
            first_number_digit++;
        if (second_num[number1_size])
            second_number_digit++; 
    }
    MUL(first_number_digit, first_num, second_number_digit, second_num);
}