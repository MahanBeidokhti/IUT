#include<stdio.h>
#include<math.h>

int avval(int num)
{
    int number = sqrt(num);
    if ((num%2==0 && num!=2) || num==1)
        return 0;
    for (int i = 3; i<=number; i+=2)
    {
        if (num%i==0)
            return 0;
    }
    return 1;
}

int main()
{
    int t, n, counter=0, flag=1;
    long long int num;
    char answer[1000]={NULL};
    scanf("%d", &t);
    for (int repeat=1 ; repeat<=t; repeat++)
    {

        scanf("%d", &n);

        int chart[n][n];
        
        for (long long int i=0; i < n; i++)
        {
            for (long long int j=0; j < n; j++)
            {
                scanf("%lld", &num);
                chart[i][j] = num;
            }
        }

        int istart, jstart, iend, jend;

        scanf("%d %d %d %d", &istart ,&jstart ,&iend ,&jend);

        chart[istart][jstart]=1;
        while (istart!=iend || jstart!=jend)
        {
            if (istart<n && jstart<n)
            {
                if (avval(chart[istart+1][jstart])==1)
                {
                    answer[counter]='D'; //printf("D");
                    counter+=1;
                    istart+=1;
                    chart[istart][jstart]=1;

                }
                else if (avval(chart[istart][jstart+1])==1)
                {
                    answer[counter]='R'; //printf("R");
                    counter+=1;
                    jstart+=1;
                    chart[istart][jstart]=1;
                }
                else if (avval(chart[istart-1][jstart])==1)
                {
                    answer[counter]='U'; //printf("U");
                    counter+=1;
                    istart-=1;
                    chart[istart][jstart]=1;
                }
                else if (avval(chart[istart][jstart-1])==1)
                {
                    answer[counter]='L'; //printf("L");
                    counter+=1;
                    jstart-=1;
                    chart[istart][jstart]=1;
                }
                else
                {
                    printf("No Monaseb Masir!");
                    flag = 0;
                    break;
                }
            }
            else
            {
                printf("No Monaseb Masir!");
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            printf("%s", answer);
        flag =1;
        printf("\n");
    }
}