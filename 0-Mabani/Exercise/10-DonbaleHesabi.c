#include<stdio.h>
#include<malloc.h>

int main()
{
    int *Array, *numbers, ghadr=0, flag=0, flag2=0, numbers_size=1, counter=0, (*answers)[2], min;
    unsigned int arr_size;

    scanf("%d", &arr_size);
    Array = malloc(arr_size* sizeof(int));
    numbers = malloc(numbers_size* sizeof(int));
    answers = calloc(255, sizeof(int));

    for (int i=0; i<arr_size; i++)
        scanf("%d", &Array[i]);

    for (int num1=0; num1<arr_size; num1++)
    {
        flag=0;
        flag2=0;
        ghadr=0;

        for (int i=0; i<numbers_size; i++)
        {
            if (numbers[i]==Array[num1])
            {
                flag2=1;
                break;
            }
        }
        if (flag2==0)
        {
            numbers[numbers_size-1]=Array[num1];
            numbers_size++;
            numbers = realloc(numbers ,numbers_size* sizeof(int));

            for (int num2=num1+1; num2<arr_size; num2++)
            {
                if (Array[num2]==Array[num1] && ghadr==0)
                {
                    ghadr = num2 - num1;
                    flag = 1;

                    for (int j=0; j*ghadr<arr_size;j++)
                    {
                        if (Array[j*ghadr +num1]!=Array[num2])
                        {
                            flag = 2;
                            break;
                        }
                    }
                }
                if (flag == 1 && Array[num2]==Array[num1] && num2%ghadr!=num1%ghadr)
                {
                    flag = 2;
                    break;
                }
            }
            switch (flag)
            {
            case 0:
                answers[counter][0] = Array[num1];
                answers[counter][1] = ghadr;
                counter++;
                break;
            
            case 1:
                answers[counter][0] = Array[num1];
                answers[counter][1] = ghadr;
                counter++;
                break;
            }
        }
    }

    printf("%d\n", counter);
    for (int i=0; i<counter; i++)
    {
        min = 0;

        for (int j=0; j<counter; j++)
            if (answers[j][0]<=answers[min][0])
                min=j;

        // printf("%d %d\n", answers[i][0], answers[i][1]);
        printf("%d %d\n", answers[min][0], answers[min][1]);
        answers[min][0]=10000;
    }
    return 0;
}