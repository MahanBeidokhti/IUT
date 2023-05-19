#include <iostream>
#include <string>
#include <stdlib.h>

int random_num, number;

int zero()
{
    return number;
}
int one()
{
    number += 1;
    return number;
}
int two()
{
    number -= 1;
    return number;
}

int (*funcs[3])() = { one, two, zero};
int main()
{
    char *list[6] = {"Go to right", "Go to left", "Do not move", "Go to right", "Go to left", "Do not move"};

    std::cin >> number;
    srand(number);
    random_num = rand() % 6;
    std::cout << list[random_num] << ' ' << (*funcs[random_num % 3])();
}