#include <iostream>

using namespace std;

int main()
{
    int count = 0, arr[4], result, temp;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> arr[0];
        cin >> arr[1];
        cin >> arr[2];
        cin >> arr[3];

        result = 0;

        if (arr[0] == 0)
        {
            cout << 1 << endl;
            continue;
        }
        if (arr[1] > arr[2])
        {
            result += arr[2] * 2;
            temp = arr[1] - arr[2];
        }
        else
        {
            result += arr[1] * 2;
            temp = arr[2] - arr[1];
        }
        temp += arr[3];
        result += arr[0];

        if (arr[0] >= temp)
        {
            result += temp;
        }
        else
            result += arr[0] + 1;

        cout << result << endl;
    }
}
