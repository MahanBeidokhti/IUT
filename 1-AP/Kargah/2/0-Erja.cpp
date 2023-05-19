#include <iostream>

void update(int &a, int &b);

int main()
{
    int a, b;

    std ::cin >> a;
    std ::cin >> b;

    update(a, b);

    std::cout << a << '\n'
              << b;
}

void update(int &a, int &b)
{
    int temp_a = a, temp_b = b;
    a = temp_a + temp_b;
    if (temp_a >= temp_b)
    {
        b = temp_a - temp_b;
        return;
    }
    b = temp_b - temp_a;
    return;
}