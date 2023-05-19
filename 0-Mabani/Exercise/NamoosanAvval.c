#include<stdio.h>

int Prime_Checker(int number)
{
    int counter;
    if (number==2)
        return 1;
    if (number%2==0 || number==0 || number==1)
        return 0;
    for (counter=2;counter<number/2;counter++)
    {
        if (number%counter==0)
            return 0;
    }
    return 1;
}

int main()
{
    int max, prime_counter=0, pc_counter=0;
    long int repeater;

    scanf("%ld", &repeater);

    for (int i=1; i<=repeater; i++)
    {
        prime_counter=0; pc_counter=0;

        scanf("%d", &max);

        for (int number=2; number; number++)
        {
            if(Prime_Checker(number))
            {
                prime_counter++;
                if (Prime_Checker(prime_counter))
                {
                    pc_counter++;
                    // printf("number is : %d\nandis is : %d\n", number, pc_counter);
                    if (pc_counter==max)
                    {
                        printf("%d\n", number);
                        break;
                    }
                }
            }
        }
    }
}





































































// #include <stdio.h>

// int main()
// {
//  int number, flc_flag, first_layer_counter = 0, second_layer_counter = 0, flag = 0;
//  long int retry_counter;

//  scanf("%d", &retry_counter);
//  for (int repeater = 0; repeater < retry_counter; repeater++)
//  {
//   first_layer_counter = 0;
//   second_layer_counter = 0;

//   scanf("%d", &number);

//   for (int first_layer_number = 2; first_layer_number; first_layer_number++)
//   {
//    flag = 0;
//    flc_flag = 0;

//    for (int second_layer_number = 2; second_layer_number <= first_layer_number; second_layer_number)
//    {
//     if (first_layer_number != second_layer_number && first_layer_number % second_layer_number == 0)
//     {
//      flag = 1;
//      continue;
//     }
//    }
//    if (flag == 0)
//    {
//     first_layer_counter++;
//    }
//    for (int flc_checker = 2; flc_checker <= first_layer_counter; flc_checker++)
//    {
//     if (first_layer_counter % flc_checker == 0)
//      flc_flag = 1;
//    }
//    if (flc_flag == 0)
//     second_layer_counter++;
//    if (second_layer_counter == number)
//    {
//     printf("%d", first_layer_number);
//    }
//   }
//  }
// }