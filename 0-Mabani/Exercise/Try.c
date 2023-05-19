#include<stdio.h>

int main()
{
  int n[3] , c[3] , d;
  char a[3];
  scanf ("%d %d %d %c %c %c", &n[0], &n[1] , &n[2] , &a[0] ,&a[1] ,&a[2]); //scanning...

      if ( n[0] >= n[1]) 
                if ( n[0]>= n[2]) c[0] = n[0];
                else c[0] = n[2];
     else if ( n[1] >= n[2]) c[0] = n[1];         
 }