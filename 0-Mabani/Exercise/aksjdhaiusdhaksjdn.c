#include <stdio.h>

void ShowFibNth(long int N1, long int N2)
{
    printf("%d\n",N1);
    long int fb;

    fb=N2-N1;
    N2=N1;
    N1=fb;

    if (fb==0)
        return;
    
    ShowFibNth(N1, N2);
    // printf("%d\n", fb);
    // while(N1>=1 && N2>=1)
    // {
    //     fb=N2-N1;
    //     N2=N1;
    //     N1=fb;
    //     if (fb!=0)
    //         printf("%ld\n",fb);
    // }
}
int main()
{
    int a,b;
    scanf("%d\n%d",&a,&b);
    printf("\n");
    ShowFibNth(a,b);
    return 0;
}