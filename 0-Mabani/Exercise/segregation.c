#include<stdio.h>

int main()
{
    int numbers[1000]={1}, odd[1000], even[1000], conuter=0, oddcounter=0, evencounter=0;

    scanf("%d", &numbers[conuter]);
    conuter++;
    
    while(numbers[conuter-1])
    {
        scanf("%d", &numbers[conuter]);
        conuter++;
    }

    for (int i=0; i<=conuter; i++)
    {
        if (numbers[i]%2==0)
        {
            even[evencounter] = numbers[i];
            evencounter++;
        }
        else
        {
            odd[oddcounter] = numbers[i];
            oddcounter++;
        }
    }
    printf("Even:\n");
    for (int ieven=0; even[ieven]; ieven++)
    {
        printf("%d\n", even[ieven]);
    }
    printf("Odd:\n");
    for (int iodd=0; odd[iodd]; iodd++)
    {
        printf("%d\n", odd[iodd]);
    }
}