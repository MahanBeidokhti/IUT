#include<stdio.h>

int * f(int number)
{
    static int majzoors[255];
    
    for (int i=0; i<number; i++)
        majzoors[i]= i*i;
    
    return majzoors;
}

int main(){
    int n;
    scanf("%d", &n);
    int* b = f(n);
    for(int i = 0; i < n; i++){
        printf("%d ", b[i]);
    }
}