#include<stdio.h>
#include <malloc.h>

int main()
{
    int *teams, team, teams_count, counter=0;

    scanf("%d %d", &teams_count, &team);

    teams = (int*) malloc(teams_count * sizeof(teams));

    for (int i=0;i<teams_count; i++)
    {
        scanf("%d", (teams+i));
    }
    for (int i=0;i<teams_count; i++)
    {
        if (*(teams+i)>=*(teams+team-1) && *(teams+i)!=0)
        {
            counter++;
        }
    }
    printf("%d",counter);
}