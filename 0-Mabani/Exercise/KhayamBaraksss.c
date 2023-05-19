#include <stdio.h>

int main()
{
    int lines,i, j;
    unsigned long long int number;
    number=1;

    scanf("%d", &lines);

    for (i = lines-1; i >=0; i--) 
    {

        for (j = 0; j <= i; j++) 
        {

            if (j == 0 || i == 0)
            number = 1;
            else
            number = number * (i-j + 1)/j ;

            printf("%llu ", number);
        }
    printf("\n");

    }
   return 0;
}