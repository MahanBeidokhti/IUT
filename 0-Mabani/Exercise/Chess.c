#include<stdio.h>

int main()
{
    int x1 ,x2 ,x3 ,x4 ,x5 ,y1 ,y2 ,y3 ,y4 ,y5 ,s1 ,s2 ,s3 ,s4 ,s5 ,sub1 ,sub2 ,sub3 ,sub4 ,sub5;
    scanf("%d %d %d %d %d %d %d %d %d %d", &x1 ,&y1 ,&x2 ,&y2 ,&x3 ,&y3 ,&x4 ,&y4 ,&x5 ,&y5);
    s1 = x1 + y1;
    s2 = x2 + y2;
    s3 = x3 + y3;
    s4 = x4 + y4;
    s5 = x5 + y5;

    if (x1 >= y1){
        sub1 = x1 - y1;
    }
    else {
        sub1 = y1 - x1;
    }
    if (x2 >= y2){
        sub2 = x2 - y2;
    }
    else {
        sub2 = y2 - x2;
    }
    if (x3 >= y3){
        sub3 = x3 - y3;
    }
    else {
        sub3 = y3 - x3;
    }
    if (x4 >= y4){
        sub4 = x4 - y4;
    }
    else {
        sub4 = y4 - x4;
    }
    if (x5 >= y5){
        sub5 = x5 - y5;
    }
    else {
        sub5 = y5 - x5;
    }

    if (s1 == s2 || s1 == s3 || s1 == s4 || s1 == s5 || s2 == s3 || s2 == s4 || s2 == s5 || s3 == s4 || s3 == s5 || s4 == s5){
        puts("Yes");}
    else if (x1 == x2 || x1 == x3 || x1 == x4 || x1 == x5 || x2 == x3 || x2 == x4 || x2 == x5 || x3 == x4 || x3 == x5 ||  x4 == x5){
        puts("Yes");}
    else if (sub1 == sub2 || sub1 == sub3 || sub1 == sub4 || sub1 == sub5 || sub2 == sub3 || sub2 == sub4 || sub2 == sub5 || sub3 == sub4 || sub3 == sub5 || sub4 == sub5){
        puts("Yes");}
    else {
        puts("No");}
} 