#include<stdio.h>

int rev_print(int loop_num);

int main()
{
    int num;
    scanf("%d", &num);

    rev_print(num);
    return 0;
}

int rev_print(int loop_num)
{
    char str[10];
    scanf("%s", str);

    if (loop_num==1)
    {
        printf("%s\n", str);
        return 0;
    }
    loop_num-=1;

    rev_print(loop_num);

    printf("%s\n", str);
    
    return 0;
}