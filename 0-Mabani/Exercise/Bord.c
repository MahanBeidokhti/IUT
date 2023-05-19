#include<stdio.h>
#include<math.h>

int main()
{
    float t1 , t2 , y, vy , vx , h , deltah , delta;

    scanf("%f %f %f %f", &vx, &vy, &y , &h);

    deltah = y - h;

    delta = vy*vy - 4 * (-5) * deltah;

    if  (delta == 0)
    {
        t1 = vy/10;
        if (t1>=0){
            printf("%.2f", vx*t1);
        }
        if (t1<0) {
            printf("impossible");
        }
    }

    if (delta < 0)
    {
        printf("impossible");
    }

    if (delta > 0)
    {
        t1 = (-(-vy+sqrt(delta))/10);
        t2 = (-(-vy-sqrt(delta))/10);
        if (t1>=0){
            printf("%.2f " , (vx * t1));
        }
        if (t2>=0){
            printf("%.2f" , (vx * t2));
        }
        if (t1<0 && t2<0){
            printf("impossible");
        }
    }
}   