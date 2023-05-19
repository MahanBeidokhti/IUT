#include <iostream>
#include <algorithm>

using namespace std;

int lcm(int a, int b)
{

    int max_num;

    max_num = max(a, b);

    while (1)
    {
        if (max_num % a == 0 && max_num % b == 0)
        {
            return max_num;
        }
        ++max_num;
    }
}

class Rational
{
public:
    Rational(int a, int b)
    {
        soorat = a;
        makhraj = b;
    }
    string sub(Rational v1, Rational v2)
    {

        int makh_moshtarak, soor_nahayee, gcd;

        // kmm gereftan
        makh_moshtarak = lcm(v1.makhraj, v2.makhraj);

        // be dast avordane soorat ha dar halate nahayee
        v1.soorat = (makh_moshtarak / v1.makhraj) * v1.soorat;
        v2.soorat = (makh_moshtarak / v2.makhraj) * v2.soorat;
        soor_nahayee = v1.soorat - v2.soorat;

        // sade kardane soorat va makhraj

        gcd = __gcd(soor_nahayee, makh_moshtarak);
        if (gcd < 0)
            gcd *= -1;

        soor_nahayee /= gcd;
        makh_moshtarak /= gcd;

        string result = "" + to_string(soor_nahayee) + '/' + to_string(makh_moshtarak);
        return result;
    }

    int getter_soorat()
    {
        return soorat;
    }
    int getter_makhraj()
    {
        return makhraj;
    }
    void setter_soorat(int number)
    {
        soorat = number;
    }
    void setter_makhraj(int number)
    {
        makhraj = number;
    }

private:
    int soorat;
    int makhraj;
};

int main()
{
    int soorat1, soorat2, makhraj1, makhraj2;

    scanf(" %d/%d", &soorat1, &makhraj1);
    scanf(" %d/%d", &soorat2, &makhraj2);

    Rational num1(soorat1, makhraj1), num2(soorat2, makhraj2);

    cout << num1.sub(num1, num2);
}