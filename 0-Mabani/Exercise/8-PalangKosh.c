#include<stdio.h>
#include<malloc.h>
int main(){
    int *cakes, cks_count, stds, Min=5000, Max=1;
    scanf("%d %d", &cks_count, &stds);
    cakes = malloc(cks_count * sizeof(int));
    for (int i=0; i<cks_count; i++)
        scanf("%d", &cakes[i]);
    if(stds==2)
        if (cakes[0]>cakes[cks_count-1])
            printf("%d", cakes[cks_count-1]);
        else
            printf("%d", cakes[0]);
    else
    {
        for (int i=0; i<cks_count; i++){
            if (cakes[i]>Max)
                Max=cakes[i];
            if (cakes[i]<Min)
                Min=cakes[i];
        }
        if (stds==1)
            printf("%d", Max);
        else if(stds>=3)
            printf("%d", Min);
    }
}