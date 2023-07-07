#include <iostream>
#include <cmath>

using namespace std;

int g(int n)
{
    int result = 0;
    for (; n > 0; n /= 2)
    {
        if (n % 2 == 1)
        {
            result++;
        }
    }
    return result;
}

int f(int a, int b)
{
    return g(a) + g(b) - g(a + b);
}

int main()
{
    int a, b, resultt = 0, poww;
    cin >> a;
    cin >> b;
    // cout << f(a, b);
    poww = pow(2, a);

    for (int i = 0; i < poww; i++)
    {
        for (int j = 0; j < poww; j++)
        {
            if (f(i, j) == b)
                resultt++;
        }
    }
    cout << resultt % 1000000000;
}