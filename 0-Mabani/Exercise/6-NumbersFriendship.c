#include<stdio.h>
#include<malloc.h>

int main()
{
    int *array, *odd, size, odd_counter=0;

    scanf("%d", &size);

    array = malloc(size * sizeof(int));
    odd = calloc(size, sizeof(int));

    for (int i=0; i<size; i++)
    {
        scanf("%d", &array[i]);
        if (array[i]%2==1)
        {
            odd[odd_counter]=array[i];
            odd_counter++;
        }
    }

    if (odd_counter%2==0)
    {    
        printf("Yes");
        return 0;
    }

    for (int j=odd_counter-1; j>=0; j--)
    {
        for (int i=0; i<size; i++)
        {
            if (odd[j]-array[i]==1 || odd[j]-array[i]==-1)
            {
                printf("Yes");
                return 0;
            }
        }
    }

    printf("No");
}