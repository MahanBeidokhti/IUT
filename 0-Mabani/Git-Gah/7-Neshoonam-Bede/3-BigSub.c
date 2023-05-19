#include<stdio.h>

void sub(int number1_size, char number1[number1_size+1], int number2_size, char number2[number2_size+1])
{
    int flag1=0, flag2=0, j;
    
    if (number1_size>=number2_size)
    {
        j = number1_size - number2_size;
        for (int i=number1_size; i>=0; i--)
        {
            if (number2[i-j]<58 && number2[i-j]>=48)
                number2[i] = number2[i-j];
            else
                number2[i] = 48;
        }

        for (int i=number1_size; i>=0; i--)
        {
            flag2 = flag1;
            flag1 = 0;

            if ((int) number1[i] - (int) number2[i] < 0)
            {
                flag1 = 1;
                number1[i] = number1[i] + 10;
            }
            
            number1[i] = (char)((int) number1[i] - (int) number2[i]);

            if (flag2==1)
            {
                number1[i] = (char)((int)number1[i]-1);
                if (number1[i]<0)
                {
                    number1[i] = number1[i] + 10;
                    flag1=1;
                }
            }
            
            
            number1[i] = number1[i] + 48 ;
        }
        printf("%s", number1);

    }

    if (number2_size>number1_size)
    {
        j = number2_size - number1_size;
        for (int i=number2_size; i>=0; i--)
        {
            if (number1[i-j]<58 && number1[i-j]>=48)
                number1[i] = number1[i-j];
            else
                number1[i] = 48;
        }

        for (int i=number2_size; i>=0; i--)
        {
            flag2 = flag1;
            flag1 = 0;

            if ((int) number2[i] - (int) number1[i] < 0)
            {
                flag1 = 1;
                number2[i] = number2[i] + 10;
            }
            
            number2[i] = (char)((int) number2[i] - (int) number1[i]);

            if (flag2==1)
            {
                number2[i] = (char)((int)number2[i]-1);
                if (number2[i]<0)
                {
                    number2[i] = number2[i] + 10;
                    flag1=1;
                }
            }
            
            
            number2[i] = number2[i] + 48 ;

        }
        printf("-%s", number2);

    }
}

int main()
{
    char first_num[255]={}, second_num[255]={};
    int first_number_digit=-1, second_number_digit=-1;

    gets(first_num);
    gets(second_num);

    for (int i=0; first_num[i] || second_num[i] ; i++)
    {
        if (first_num[i])
            first_number_digit++;
        if (second_num[i])
            second_number_digit++; 
    }
    sub(first_number_digit, first_num, second_number_digit, second_num);
}