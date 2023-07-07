#include <iostream>

using namespace std;

int main()
{
    int count, m, min, sum1, sum2;
    int *arr[2];
    cin >> count;
    for (int cnt = 0; cnt < count; cnt++)
    {
        min = 9999999999;
        cin >> m;
        arr[0] = new int[m];
        arr[1] = new int[m];
        for (int i = 0; i < m; i++)
            cin >> arr[0][i];
        for (int i = 0; i < m; i++)
            cin >> arr[1][i];

        sum1 = 0;
        sum2 = 0;
        for (int j = 1; j < m; j++)
        {
            sum1 += arr[0][j];
        }

        for (int i = 0; i < m; i++)
        {

            if (sum1 > sum2)
            {
                if (min > sum1)
                {
                    min = sum1;
                }
            }
            else
            {
                if (min > sum2)
                {
                    min = sum2;
                }
            }
            sum1 -= arr[0][i + 1];
            sum2 += arr[1][i];
        }
        cout << min << endl;
    }
}