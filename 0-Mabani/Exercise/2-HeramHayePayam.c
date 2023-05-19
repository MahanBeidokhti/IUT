#include<stdio.h>
#include<malloc.h>

int main()
{
    int num, size, sum=0, main_sum=0, counter_sum=0, counter;

    scanf("%d", &size);

    for (int i=0; i<size; i++)
    {
        scanf("%d", &num);

        for (int j=num; j>0; j--)
            sum+=j;
        main_sum += sum*3-num;
        sum=0;
        num=0;
    }

    for (counter=1; counter<100; counter++)
    {
        counter_sum+=counter;
        if (((counter_sum*2)+(counter_sum-counter)) > main_sum)
            break;
    }

    printf("%d", counter-1);
}