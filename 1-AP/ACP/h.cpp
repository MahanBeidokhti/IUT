#include <iostream>

using namespace std;

long long int tabe(long long int a, long long int b)
{
    if ((a < 2 && b < 2))
    {
        return 0;
    }
    else if (a / b == 2 || b / a == 2)
    {
        return 1;
    }

    for (int i = 1; i < b / 2; i++)
    {
        if (tabe(a - i, b - 2 * i))
        {
            return 1;
        }
        else if (tabe(a - 2 * i, b - i))
        {
            return 1;
        }
        else
            return 0;
    }

    // long long int temp = tabe(a - 1, b - 2);
    // if (!temp)
    // {
    //     return tabe(a - 2, b - 1);
    // }
    // return temp;
}

int main()
{
    int count;
    long long int a, b, temp;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> a;
        cin >> b;
        if (a > b)
        {
            temp = a;
            a = b;
            b = temp;
        }
        if (tabe(a, b))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}