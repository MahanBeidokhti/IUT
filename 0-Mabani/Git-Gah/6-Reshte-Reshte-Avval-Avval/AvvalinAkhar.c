#include<stdio.h>

int main()
{
    char first_array[70]={}, second_array[70]={};
    int second_array_counter=0;

    scanf("%s",first_array);
    scanf("%s",second_array);

    for (int i=0; i<50; i++)
        if (second_array[i+1]==0 && second_array[i+2]==0)
            break;
        else
            second_array_counter++;

    if (first_array[0] == second_array[second_array_counter])
    {
        printf("YES");
        return 0;
    }
    printf("NO");
}