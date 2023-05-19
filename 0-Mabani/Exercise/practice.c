#include <stdio.h>

int checker(int array[], int n)
{
    int result = 0;

    for (int i = 0; i < n; i++)
        result = result ^ array[i];

    return result;
}

int main()
{
    int arr[] = {10, 12, 10, 12, 10}, siz = 5;

    printf("%d", checker(arr, siz));
}