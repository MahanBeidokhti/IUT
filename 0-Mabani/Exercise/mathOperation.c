
#include <stdio.h>
#include <math.h>

int main (){ 
	  	int n[3] , d,D;
	  int b = 0;
	  
	  	scanf("%d %d %d", &n[0] ,&n[1] ,&n[2]);

	
	 if ( n[0] >= n[1])
	 {
	
	 }
	 else {
	 	d=n[0];
	 	n [0] = n[1];
	 	n [1] = d;
	 }
	 if ( n[2] >= n[0]) {
	 	d = n[2];
	 	D = n[1];
	 	n [1] = n [0];
	 	n [2] = D;
	 	n[0]= d;
	 }
	 if (n[2]>= n[1])
	 {
	 	d= n[1];
	 	n[1]= n[2];
	 	n[2] =n[1];
	 }
	 d = n[1]* n[1] + n[2] *n[2];
    
	if (sqrt(d)== n[0]){
        
		printf ("RT");
	}
         else if (n[2] + n[1]> n[0]){

		 printf ("N");

	}
	else printf ("T");
	return 0;

}