#include<stdio.h>
#include<malloc.h>

int main()
{
    int size1, size2, size3, ***array;
    scanf("%d %d %d", &size1, &size2, &size3);

    array = malloc(size1 * sizeof(int **));

    for (int i=0; i<size1; i++)
    {
        *(array+i) = malloc(size2 * sizeof(int *));
        for (int j=0; j<size2; j++)
        {
            *(*(array+i)+j) = malloc(size3 * sizeof(int));
        }
    }
}