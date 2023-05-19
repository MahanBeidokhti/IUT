#include<stdio.h>

int main()
{
    int nletter1, nletter2, nletter, counter=0;
    char cletter1, cletter2, cletter;
    char word[100];

    scanf(" %c", &cletter1);
    nletter1 = cletter1;
    scanf(" %c", &cletter2);
    nletter2 = cletter2;
    nletter1 = nletter2 - nletter1 ;

    scanf(" %s", word);
    
    for (counter; word[counter]; counter++)
    {
        if (word[counter] - nletter1 < 97)
        {
            word[counter] += 26 - nletter1;
            continue;
        }
        if (word[counter] - nletter1 > 122)
        {
            word[counter] -= 26 + nletter1;
            continue;
        }
        word[counter] -= nletter1;
    }

    printf("%s", word);
}