#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char anime_name[64];
    int retry_counter, len_name;

    scanf("%d", &retry_counter);

    for (int i=0; i<=retry_counter; i++)
    {
        gets(anime_name);
        
        len_name = strlen(anime_name);

        for (int word=0; word<len_name; word++)
        {
            if (anime_name[word-1]==0 || anime_name[word-1]==' ')
                anime_name[word]=toupper(anime_name[word]);
            else 
                anime_name[word]=tolower(anime_name[word]);
            printf("%c", anime_name[word]);
        }
        printf("\n");

        
    }
    
}