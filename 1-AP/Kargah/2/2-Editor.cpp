#include <iostream>
#include <string>

using namespace std;

string str;
int counter = 0;

int LR(int &a)
{
    if (str[a] == 'L')
    {
        if (counter <= a)
            counter++;
        LR(++a);
    }
    else if (str[a] == 'R')
    {
        if (counter != 0)
            counter--;
        LR(--a);
    }
    else
    {
        return counter;
    }
}

int main()
{
    cin >> str;
    string result = str;
}

// #include <iostream>
// #include <string>

// int main()
// {
//     char temp;
//     int size;
//     // std::cin >> size;
//     // char *str = new char[size];
//     std::string str;
//     std::cin >> str;
//     size = str.length();
//     for (int i = 0; i < size - 1; i++)
//     {
//         if (str[i + 1] == 'L')
//         {
//             temp = str[i];
//             for (int j = i; j < size - 2; j++)
//             {
//             str[i] = str[size - 1];
//                 str[j] = str[j + 1];
//             }
//             str[size - 2] = str[size - 1];
//             str[size - 1] = temp;
//             i++;
//         }
//         if (str[i] == 'R')
//         {
//             i++;
//         }
//         else
//         {
//             std::cout << str[i];
//         }
//     }
//     std::cout << str[size - 1];
// }