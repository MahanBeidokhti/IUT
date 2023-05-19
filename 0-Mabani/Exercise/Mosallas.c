#include<stdio.h>
#include<math.h>

int main()
{
    int x1 , x2 , x3 , y1 , y2 ,y3 , counter;
    float tan1 , tan2 , tan3 , z1 , z2 , z3;

    scanf("%d", &counter);
    
    for (counter=counter ; counter >= 1; counter--)
    {
        scanf("%d %d %d %d %d %d", &x1 , &y1 , &x2 , &y2 , &x3 , &y3);

        if (x1 == x2 && x2 == x3)
        {
            printf("not a triangle\n");
            continue;
        }
        else if (y1 == y2 && y2 == y3)
        {
            printf("not a triangle\n");
            continue;
        }
        else
        {
            if (x1!=x2 && x1!=x3 && x2!=x3)
            {
            // if(x1-x2 !=0)
            // {
                tan1 = (y1-y2)/(x1-x2);
            // }
            // if(x2-x3 !=0)
            // {
                tan2 = (y2-y3)/(x2-x3);
            // }
            // if(x1-x3 !=0)
            // {
                tan3 = (y1-y3)/(x1-x3);
            // }
                if (tan1 == tan2 || tan1 == tan3 || tan2 == tan3)
                {
                    printf("not a triangle\n");
                    continue;
                }
            }
            
            
        }

        z1 = sqrt((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1));
        z2 = sqrt((y3-y1)*(y3-y1)+(x3-x1)*(x3-x1));
        z3 = sqrt((y3-y2)*(y3-y2)+(x3-x2)*(x3-x2));

        // if (z1 == z2 && z1 == z3 && z2 == z3)
        // {
        //         printf("equilateral ");
        // }
        if (z1 != z2 && z1 != z3 && z2 != z3)
        {
            printf("scalene ");
        }
        else
        {
            printf("isosceles ");
        }


        if (z1 > z2 + z3 || z2 > z1 + z3 || z1 + z2 < z3)
        {
            printf("obtuse ");
        }
        else if (z1 == z2 + z3 || z2 == z1 + z3 || z1 + z2 == z3)
        {
            printf("right ");
        }
        else
        {
            printf("acute ");
        }

        printf("triangle\n");
        
    }

}