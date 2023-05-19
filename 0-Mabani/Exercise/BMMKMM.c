#include<stdio.h>

int main()
{
    long long int n, m,c, a ,b ,bmm, kmm;
    int counter;
    scanf("%lld %lld" , &n , &m);
    a = m;
    b = n;
    if (n>m){
        c = n;
        n = m;
        m = c;
    }

    for (counter = n ; counter >= 1; counter-- )
    {
        c = m % n;
        if (c == 0)
        {
            break;
        }
        m = n;
        n = c;
    }
    bmm = n;

    printf("%lld %lld", bmm, (a*b)/bmm);
}