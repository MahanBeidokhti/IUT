#include <stdio.h>

int main()
{   
    int a, b, c, c2, result1=0, baghi=0, baghi1, baghi2, baghi3, sum1, sum2;
    scanf("%d %d",&a,&b);
    int result=0;
    while(a!=0)
    {
        result=result*10 + a%b; 
        a/=b;
    }
    a=result;

    while(a!=0)
    {
        result1 = result1*10 + a%10; 
        a/=10;
    }


    c=result1;
    c2=c;
    
    while(c!=0)
    {
        baghi=c%10;
        if(c<=9)
            baghi1=baghi;
        c/=10;
    }

    c=c2;
    baghi=0;
    
    while(c!=0)
    {
        baghi=c%10;
        if(c<=999 && c>=100)
            baghi2=baghi;
        c/=10;
    }

    c=c2;
    baghi=0;
    
    while(c!=0)
    {
        baghi=c%10;
        if(c<=99999 && c>=10000)
            baghi3=baghi;
        c/=10;
    }

    c=c2;

    if(c<=99999 && c>=10000)
        sum1=baghi1+baghi2+baghi3;
    else if(c<=9999 && c>=1000)
        sum1=baghi1+baghi2;
    else if(c<=999 && c>=100)
        sum1=baghi1+baghi2;
    else if(c<=99 && c>=10)
        sum1=baghi1;
    else if(c<=9 && c>=1)
        sum1=baghi1;

 
    c=c2;
    baghi=0;
    baghi1=0;
    baghi2=0;
    
    while(c!=0)
    {
        baghi=c%10;
        if(c>=10 && c<=99)
            baghi1=baghi;
        c/=10;
    }
    
    c=c2;
    baghi=0;

    while(c!=0)
    {
        baghi=c%10;
        if(c>=1000 && c<=9999)
            baghi2=baghi;
        c/=10;
    }

    c=c2;
    if(c<=99999 && c>=10000)
        sum2=baghi1+baghi2;
    else if(c<=9999 && c>=1000)
        sum2=baghi1+baghi2;
    else if(c<=999 && c>=100)
        sum2=baghi1+baghi2;
    else if(c<=99 && c>=10)
        sum2=baghi1;
    else if(c<=9 && c>=1)
        sum2=0;


    if(sum1==sum2)
      printf("Yes");
      return 0;

    printf("No");

    return 0;
}