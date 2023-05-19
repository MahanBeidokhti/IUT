#include<stdio.h>
#include<math.h>

int main()
{
    int n, logar;
    
    scanf("%d", &n);
    logar = pow(2, (int)log2(n) +1);
    printf("%d", logar);
}