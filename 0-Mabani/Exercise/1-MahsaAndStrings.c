#include<stdio.h>
#include<malloc.h>

int main()
{
    char *str;
    int size,num, flag=0, i=0;

    scanf("%d", &size);
    str = (char*) malloc(size * sizeof(char));

    scanf("%s", str);

    size-=1;
    
    while (i < size-2)
    {
        flag=0;
        
        num = (int) str[i] - 48;

        if (str[i+2]=='0')
        {
            if (str[i+3]=='0')
            {
                printf("%c", (char)(num+96));
                i++;
                continue;
            }

            printf("%c", (char)(10*num+((int)(str[i+1])-48)+96));
            i+=3;
            continue;
        }

        printf("%c", (char)(num+96));
        i++;
    }

    if (i < size-1 && str[i+2]=='0')
    {
        printf("%c", (char)(10*num+((int)(str[i+1])-48)+96));
        return 0;
    }

    for (int j = i; j <= i+size-i; j++)
        printf("%c", (char)(str[j]+48));

    return 0;
}