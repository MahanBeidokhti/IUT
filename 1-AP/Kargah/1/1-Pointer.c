#include <stdio.h>

void update(int *a, int *b);

int main()
{
    int num1, num2;
    scanf("%d", &num1);
    scanf("%d", &num2);

    update(&num1, &num2);

    printf("%d\n", num1);
    printf("%d", num2);
}

void update(int *a, int *b)
{
    int temp1 = *a, temp2 = *b;
    *a = temp1 + temp2;
    if (temp1 >= temp2)
    {
        *b = temp1 - temp2;
        return;
    }
    *b = temp2 - temp1;
    return;
}