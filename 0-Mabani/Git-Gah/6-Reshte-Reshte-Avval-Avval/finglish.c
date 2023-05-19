#include<stdio.h>

int main()
{
    char name[6];
    int final_answer=1;

    scanf("%s", name);

    for (int i=0; i<6 ;i++)
        if (name[i]=='a' || name[i]=='e' || name[i]=='o' || name[i]=='i' || name[i]=='u')
            final_answer*=2;
    
    printf("%d", final_answer);
}