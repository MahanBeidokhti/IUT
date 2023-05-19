#include<stdio.h>

int main()
{
    char Time[5];
    int flag=0, hour_rev, min;
    scanf("%s", Time);
    min = 10 * ((int)Time[3]-48) + ((int)Time[4]-48);
    hour_rev = 10 * ((int)Time[1]-48) + ((int)Time[0]-48);
    if(hour_rev==32 && min>32)
        printf("%d", 60-min);
    else
        if (hour_rev-min<0)
            printf("%d", 70+(hour_rev-min));
        else if (hour_rev-min==0)
            printf("0");
        else
            printf("%d", hour_rev-min);
}