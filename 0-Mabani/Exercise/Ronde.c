#include<stdio.h>

int main()
{
    int mirror_checker=0, nums_count, repeat_counter=1, zero_counter=0, one_counter=0, two_counter=0, three_counter=0, four_counter=0, five_counter=0, six_counter=0, seven_counter=0, eight_counter=0, nine_counter=0;
    char num[9];
    
    scanf("%d", &nums_count);

    for (int i = 0; i < nums_count; i++)
    {    
        scanf(" %s", num);
        zero_counter=0; one_counter=0; two_counter=0; three_counter=0; four_counter=0; five_counter=0; six_counter=0; seven_counter=0; eight_counter=0; nine_counter=0;
        repeat_counter=1;
        mirror_checker=0;

        
        for (int digit=0; digit<8; digit++)
        {
            switch (num[digit])
            {
            case '0':
                zero_counter++;
                break;
            case '1':
                one_counter++;
                break;
            case '2':
                two_counter++;
                break;
            case '3':
                three_counter++;
                break;
            case '4':
                four_counter++;
                break;
            case '5':
                five_counter++;
                break;
            case '6':
                six_counter++;
                break;
            case '7':
                seven_counter++;
                break;
            case '8':
                eight_counter++;
                break;
            case '9':
                nine_counter++;
                break;
            }

            if (num[digit+1]==num[digit])
            {
                repeat_counter++;
            }
            else if (repeat_counter<3)
            {
                repeat_counter=1;
            }
        }

        if (zero_counter>3 || one_counter>3 ||two_counter>3 ||three_counter>3 ||four_counter>3 ||five_counter>3 ||six_counter>3 ||seven_counter>3 ||eight_counter>3 ||nine_counter>3)
        {
            printf("Ronde!\n");
            continue;
        }

        if (repeat_counter>=3)
        {
            printf("Ronde!\n");
            continue;
        }

        for (int digit=0; digit<4; digit++)
        {
            if (num[digit]==num[7-digit])
                mirror_checker++;
        }
        if (mirror_checker==4)
        {
            printf("Ronde!\n");
            continue;
        }
        printf("Rond Nist\n");
    }

}