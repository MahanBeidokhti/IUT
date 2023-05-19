#include<stdio.h>

int main()
{
    char letter;
    int counter = 1 ;
    scanf("%c", &letter);
    
    if (letter=='I')
    {
        while (counter <= 3)
        {
        printf("\033[;42m");
        printf("                                       ");
        printf("\033[0m\n");
        counter++;
        }
        counter = 1;
        while (counter <= 3)
        {
        printf("\033[;47m");
        printf("                                       ");
        printf("\033[0m\n");
        counter++;
        }
        counter = 1;
        while (counter <= 3)
        {
        printf("\033[;41m");
        printf("                                       ");
        if (counter == 3){
            printf("\033[0m");
        }
        else 
            printf("\033[0m\n");
        counter++;
        }
    }
    
    if (letter=='U')
    {
        while (counter <= 2)
        {
            printf("\033[;44m               ");
            printf("\033[;41m                        ");
            printf("\033[0m\n");
            printf("\033[;44m               ");
            printf("\033[;47m                        ");
            printf("\033[0m\n");
            counter++;
        }
        counter = 1;
        printf("\033[;41m                                       ");
        printf("\033[0m\n");
        while (counter <= 2)
        {
            printf("\033[;47m                                       ");
            printf("\033[0m\n");
            printf("\033[;41m                                       ");
            if (counter == 2){
                printf("\033[0m");
            }
            else 
                printf("\033[0m\n");
            counter++;
        }
    }
    
    if (letter=='C')
    {
        while (counter <= 9)
        {
            printf("\033[;41m                                       ");
            if (counter == 9){
                printf("\033[0m");
            }
            else 
                printf("\033[0m\n");
            counter++;
        }
    }
    
    if (letter=='F')
    {
        while (counter <= 9)
        {
            printf("\033[;44m             ");
            printf("\033[;47m             ");
            printf("\033[;41m             ");
            if (counter == 9){
                printf("\033[0m");
            }
            else 
                printf("\033[0m\n");
            counter++;
        }
    }
    
    if (letter=='R')
    {
        while (counter <= 3)
        {
            printf("\033[;47m                                       ");
            printf("\033[0m\n");
            counter++;
        }
        counter = 1;
        while (counter <= 3)
        {
            printf("\033[;44m                                       ");
            printf("\033[0m\n");
            counter++;
        }
        counter = 1;
        while (counter <= 3)
        {
            printf("\033[;41m                                       ");
            if (counter == 3){
                printf("\033[0m");
            }
            else 
                printf("\033[0m\n");
            counter++;
        }
    }
}