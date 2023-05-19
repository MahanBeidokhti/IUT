#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

char  * randomer();
void print(char ** array);
void Address_Maker();
char *array;

int main()
{
    array = malloc(2*sizeof(char));
    Address_Maker();
    return 0;
}

char *randomer()
{    
    for (int i=0; i<2; i++)
    {
        array[i] = rand()%26 + 97;
    }
    
    return array;
}

void print(char ** array)
{
    for (int i=0; i<5; i++)
        for (int j=0; j<2; j++)
        {
            printf("%c", array[i][j]);
        }

    return;
}

void Address_Maker()
{
    char **addresses;
    addresses = malloc(5 * sizeof(char*));
    for (int i=0; i<5; i++)
    {
        array = calloc(2,sizeof(char));
        addresses[i] = randomer();
    }
    print(addresses);
    
    return;
}