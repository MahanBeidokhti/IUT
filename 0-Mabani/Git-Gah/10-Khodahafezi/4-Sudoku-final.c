#include <stdio.h>

int possibility(int number, int chart[][9], int i, int j)
{
    int sqr_row, sqr_col;
    sqr_row = 3 * (i/3);
    sqr_col = 3 * (j/3);

    for (int iterator=0; iterator<9; ++iterator)
        if (chart[i][iterator]==number || chart[iterator][j]==number || chart[sqr_row + (iterator%3)][sqr_col + (iterator%3)]== number)
            return 0;
        
    return 1;
}

int GiveNumber(int puzzle[][9], int row, int col)
{
    int i;
    if(row<9 && col<9)
    {
        if(puzzle[row][col] != 0)
        {
            if((col+1)<9) return GiveNumber(puzzle, row, col+1);
            else if((row+1)<9) return GiveNumber(puzzle, row+1, 0);
            else return 1;
        }
        else
        {
            for(i=0; i<9; ++i)
            {
                if(possibility(i+1, puzzle, row, col))
                {
                    puzzle[row][col] = i+1;
                    if((col+1)<9)
                    {
                        if(GiveNumber(puzzle, row, col +1)) return 1;
                        else puzzle[row][col] = 0;
                    }
                    else if((row+1)<9)
                    {
                        if(GiveNumber(puzzle, row+1, 0)) return 1;
                        else puzzle[row][col] = 0;
                    }
                    else return 1;
                }
            }
        }
        return 0;
    }
    else return 1;
}

int main()
{
    int i, j;
    int puzzle[9][9];
    for (int i=0; i<9; i++)
    {
        for (int j=0; j<9; j++)
        {
            scanf("%d", &puzzle[i][j]);
        }
    }
    
    GiveNumber(puzzle, 0, 0);

    for (int i=0; i<9; i++)
    {
        for (int j=0; j<9; j++)
            printf("%d ", puzzle[i][j]);
        printf("\n");
    }

    return 0;
}