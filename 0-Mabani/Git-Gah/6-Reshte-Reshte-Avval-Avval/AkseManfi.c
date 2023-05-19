#include<stdio.h>

void Convert2Negative(int size, int picture_array[size][size])
{
    
    for (int i=0; i<size;i++)
    {
        for(int j=0; j<size;j++)
        {
            scanf("%d", &picture_array[i][j]);
        }
    }

    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
            picture_array[i][j] = 255 - picture_array[i][j];
        }
    }
    return ;
}

void PrintImage(int size, int pic_matris[size][size])
{
    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
            printf("%d ", pic_matris[i][j]);
        }
        printf("\n");
    }
    return;
}

int main()
{
    int picture_array[255][255], size;


    scanf("%d", &size);
    
    Convert2Negative(size, picture_array);
    PrintImage(size, picture_array);

}



























// #include<stdio.h>

// void Convert2Negative(int size, int pic_matris[size])
// {
//     for (int i=0; i<size; i++)
//     {
//             pic_matris[i] = 255 - pic_matris[i];
//     }
//     return ;
// }

// void PrintImage(int size, int pic_matris[size])
// {
//     for (int i=0; i<size; i++)
//     {
//             printf("%d ", pic_matris[i]);
//     }
//         printf("\n");
//     return;
// }

// int main()
// {
//     int picture_array[255][255], size;

//     scanf("%d", &size);
//     for (int i=0; i<size;i++)
//     {
//         for(int j=0; j<size;j++)
//         {
//             scanf("%d", &picture_array[i][j]);
//         }
//     }
    
//     for (int i=0;i<size;i++)
//     {
//         Convert2Negative(size, picture_array[i]);
//         PrintImage(size, picture_array[i]);
//     }

// }

