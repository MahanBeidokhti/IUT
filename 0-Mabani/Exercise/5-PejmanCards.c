#include<stdio.h>
#include<malloc.h>

int main()
{
    int *pejman, *payam, size, replaces, min, max, temp, sum=0;
    scanf("%d %d", &size, &replaces);

    pejman = malloc(size * sizeof(int));
    payam  = malloc(size * sizeof(int));

    for (int i=0; i<size; i++)
    {
        scanf("%d", &pejman[i]);
    }
    
    for (int i=0; i<size; i++)
    {
        scanf("%d", &payam[i]);
    }
    
    for (int replace=0; replace<replaces; replace++)
    {
        min = replace;
        max = replace;
        
        for (int i=0; i<size; i++)
        {  
            if (pejman[i]<=pejman[min])
                min = i;
            if (payam[i]>=payam[max])
                max = i;
        }
        temp = pejman[min];
        pejman[min] = payam[max];
        payam[max] = temp;
    }
    
    for (int i=0; i<size; i++)
    {
        sum += pejman[i];
    }
    printf("%d", sum);
}