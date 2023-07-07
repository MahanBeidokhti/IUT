#include <iostream>

using namespace std;

int main()
{
    int num, result = 0;
    while (cin >> num)
    {
        if (!(num > 20 || num < -2) && num > 4)
        {
            result++;
        }
    }
    cout << result;
}