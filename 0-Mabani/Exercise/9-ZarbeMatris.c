#include<stdio.h>
#include<malloc.h>

void CreateMatrix(int ***matris, int i, int j);
void FillMatrix(int **matris, int i, int j);
void PrintMatrix(int **matris, int i, int j);

int main()
{
    int **Matris1, **Matris2, **Matris_Answer, i, j, k, sum;
    scanf("%d %d %d", &i, &j, &k);

    CreateMatrix(&Matris1, i, j);
    CreateMatrix(&Matris2, j, k);
    CreateMatrix(&Matris_Answer, i, k);

    FillMatrix(Matris1, i, j);
    FillMatrix(Matris2, j, k);

    for (int a=0; a<i; a++)
    {
        for (int b=0; b<k; b++)
        {
            sum = 0;
            for (int c=0; c<j; c++)
            {
                sum += Matris1[a][c] * Matris2[c][b];
            }
            Matris_Answer[a][b] = sum;
        }
    }

    PrintMatrix(Matris_Answer, i, k);
}

void CreateMatrix(int ***matris, int i, int j)
{
    *matris = (int **) malloc(i * sizeof(int *));
    
    for (int counter=0; counter<i; counter++)
        (*matris)[counter] = calloc(j , sizeof(int));
    return;
}

void FillMatrix(int **matris, int i, int j)
{
    for (int counter=0; counter<i; counter++)
    {
        for (int counter2=0; counter2<j; counter2++)
        {
            scanf("%d", &matris[counter][counter2]);
        }
    }
    return;
}

void PrintMatrix(int **matris, int i, int j)
{
    for (int a=0; a<i; a++)
    {
        for (int b=0; b<j; b++)
            printf("%d ", matris[a][b]);
        printf("\n");
    }
}