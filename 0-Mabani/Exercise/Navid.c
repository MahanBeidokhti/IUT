#include <stdio.h>
#include <math.h>

int main()
{
  int num, mabna1, mabna2, baghi=0, baghi2, deci=0, counter1=0, counter2; 
  
  scanf("%d\n %d\n %d", &num , &mabna1, &mabna2);

  while(num!=0)
  {
    baghi=num%10;
    num/=10;
    
    for(counter2=counter1 ; counter2<=counter1 ; counter2++)
    {
      deci+= baghi*pow(mabna1,counter2); 
    }

    counter1++;
  }
  baghi=0;

  while(deci!=0)
  {
    baghi=baghi*10 + deci%mabna2;
    deci/=mabna2;
  }

  deci=baghi;
  while(deci!=0)
  {
    baghi2=baghi2*10 + deci%10;
    deci/=10;
  }

  if(baghi2==baghi)
  {
    printf("YES");
    return 0;
  }

  printf("NO");

  return 0;
}
