#include <stdio.h>

int main()
{
    int count;
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        printf("Salam\t");
        if (i % 10 == 9)
            printf("\n");
    }
}