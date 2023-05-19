#include<stdio.h>
#include<malloc.h>

void sorting(int * array);
void print(int * array);

int size=5;

int main()
{
    int *array;

    scanf("%d", &size);
    array = malloc(size * sizeof(int));

    for (int i=0; i<size; i++)
    {
        scanf("%d", &array[i]);
    }

    sorting(array);
    print(array);
}

void sorting(int * array)
{
    int temp;

    for (int i=0; i<size-1; i++)
    {
        for (int j=i+1; j<size; j++)
        {
            if (array[i]>array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    return;
}

void print(int * array)
{
    for (int i=0; i<size; i++)
    {
        printf("%d ", array[i]);
    }
    return;
}