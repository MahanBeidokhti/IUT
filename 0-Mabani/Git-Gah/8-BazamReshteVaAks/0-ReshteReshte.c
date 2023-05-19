#include<stdio.h>
#include<malloc.h>
#include<string.h>

int Del_word(char * first_word, char * second_word);
int Edit_word(char * first_word, char * second_word);
int Lowup_word(char * first_word, char * second_word);

int main()
{
    char **first, **second;
    int n, k, *answer;

    scanf("%d %d", &n, &k);

    first = (void *) malloc(n*8);
    second = (void *) malloc(k*8);
    answer = (int *) malloc(k * sizeof(int));

    for (int i=0; i<n; i++)
    {
        first[i] = (char *) malloc(50 * sizeof(char));
        scanf("%s", first[i]);
    }
    for (int i=0; i<k; i++)
    {
        second[i] = (char *) malloc(50 * sizeof(char));
        scanf("%s", second[i]);
    }

    for (int i=0; i<k; i++)
    {
        answer[i]=0;
        for (int j=0; j<n; j++)
        {
            printf("%d \n", strlen(first[j])-strlen(second[i]));
            if ( (strlen(first[j]) - strlen(second[i])) < -1 )
                continue;
            if (Del_word(first[j], second[i]))
            {
                answer[i]++;
            }
            else if(Edit_word(first[j], second[i]))
            {
                answer[i]++;
            }
            else if(Lowup_word(first[j], second[i]))
            {
                answer[i]++;
            }
        }
        printf("%d\n", answer[i]);
    }


}


int Del_word(char * first_word, char * second_word)
{
    int flag =0 ;
    for (int i=0; i<strlen(first_word) || i<strlen(second_word) ; i++)
    {
        if (first_word[i]!=second_word[i])
        {
            flag++;
            if (flag==2)
                return 0;
        }
    }
    if (flag==1)
        return 1;
    else
        return 0;
}

int Edit_word(char * first_word, char * second_word)
{
    return 1;
}
int Lowup_word(char * first_word, char * second_word)
{
    return 1;
}