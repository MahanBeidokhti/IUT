#include <iostream>

using namespace std;

class temp
{
protected:
public:
    int a;
    temp()
    {
        a = 2;
    }
    temp(int A)
    {
        a = A;
    }
};

class temppp
{
protected:
    temp *akbar;

public:
    temppp()
    {
        cout << "akbar\n";
    }
    temppp(temp &a)
    {
        akbar = &a;
        cout << akbar->a;
        cout << a.a<<endl;
        a.a = 12;
        cout << akbar->a;
        cout << a.a<<endl;

    }
    // temppp()
    // {
    //     cout<<"akbar\n";
    // }
};

int main()
{
    temp ak;
    temppp a(ak);
    temppp b;


    return 0;
}