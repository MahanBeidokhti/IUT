#include<stdio.h>

int main()
{
    char Amar[5]={};
    int g_counter=0, r_counter=0, y_counter=0;

    scanf("%s", Amar);

    for (int i=0; i<5; i++)
    {
        switch (Amar[i])
        {
        case 'G':
        case 'g':
            g_counter++;
            break;
        case 'R':
        case 'r':
            r_counter+=2;
            break;
        case 'Y':
        case 'y':
            y_counter++;
            break;
        default:
            break;
        }
    }

    if (g_counter==0)
    {
        printf("nakhor lite");
        return 0;
    }
    else if( r_counter+y_counter>=6)
    {
        printf("nakhor lite");
        return 0;
    }
    printf("rahat baash");
}