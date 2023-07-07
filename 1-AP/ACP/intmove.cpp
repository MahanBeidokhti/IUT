#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int count, a, b;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> a;
        cin >> b;

        if (a == 0 && b == 0)
        {
            cout << 0 << endl;
        }
        else if ((pow((a * a) + (b * b), 0.5)) - (int)(pow((a * a) + (b * b), 0.5)) == 0)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 2 << endl;
        }
    }
}