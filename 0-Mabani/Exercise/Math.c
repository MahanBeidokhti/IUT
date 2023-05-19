#include<stdio.h>

int main()
{
    float num1, num2, num3, num4, num5, mid;

    scanf("%f %f %f %f %f",&num1 ,&num2 ,&num3 ,&num4 ,&num5);
    printf("%0.3f\n",(num1+num2+num3+num4+num5));
    mid = (num1+num2+num3+num4+num5)/5;
    printf("%0.3f\n",mid);
    printf("%0.3f\n",((num1-mid)*(num1-mid)+(num2-mid)*(num2-mid)+(num3-mid)*(num3-mid)+(num4-mid)*(num4-mid)+(num5-mid)*(num5-mid))/5);
}