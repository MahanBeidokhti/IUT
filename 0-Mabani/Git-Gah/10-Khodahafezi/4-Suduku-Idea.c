#include <stdio.h>

int possibility(int number, int chart[][9], int i, int j);
int GiveNumber(int chart[][9], int row, int col);


int main()
{
    int i, j;
    int chart[9][9];
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            scanf("%d", &chart[i][j]);

    GiveNumber(chart, 0, 0);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            printf("%d ", chart[i][j]);
        printf("\n");
    }

    return 0;
}

int possibility(int number, int chart[][9], int i, int j)
{
    int sqr_row, sqr_col;
    sqr_row = 3 * (i / 3);
    sqr_col = 3 * (j / 3);

    for (int iterator = 0; iterator < 9; ++iterator)
        if (chart[i][iterator] == number || chart[iterator][j] == number || chart[sqr_row + (iterator % 3)][sqr_col + (iterator / 3)] == number)
            return 0;

    return 1;
}

int GiveNumber(int chart[][9], int row, int col)
{
    if (row < 9 && col < 9)
    {
        if (chart[row][col] == 0)
        {
            for (int i = 1; i < 10; i++)
            {
                if (possibility(i, chart, row, col))
                {
                    chart[row][col] = i;

                    if (col < 8)
                        if (GiveNumber(chart, row, col + 1))
                            return 1;
                        else
                            chart[row][col] = 0;

                    else if (row < 8)
                        if (GiveNumber(chart, row + 1, 0))
                            return 1;
                        else
                            chart[row][col] = 0;

                    else
                        return 1;
                }
            }
        }
        else
        {
            if (col < 8)
                return GiveNumber(chart, row, col + 1);
            else if (row < 8)
                return GiveNumber(chart, row + 1, 0);
            else
                return 1;
        }
        return 0;
    }
    else
        return 1;
}