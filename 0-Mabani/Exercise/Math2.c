#include<stdio.h>

int main()
{
    unsigned x, y, n ,k;
    float n2;
    scanf("%d %d %d", &y, &x, &n);
    n2 = n - 0.00001;
    printf("%d", (n/x-1)*x+y);

} 