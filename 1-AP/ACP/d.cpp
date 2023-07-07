#include <iostream>
using namespace std;

int main()
{
    int n, k, result = 0;
    cin >> n;
    cin >> k;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if ((5 - temp) >= k)
            result++;
    }
    cout << result / 3;
}