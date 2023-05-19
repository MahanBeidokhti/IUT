#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

template <typename T, int len>
class CBuf
{
protected:
    T arr[len];
    int CPU_i = 0;
    int Key_i = 0;
    int is_string;
    int dif = 0;

public:
    CBuf()
    {
        if (typeid(T) == typeid(string))
        {
            is_string = 1;
        }
        else
        {
            is_string = 0;
        }

        if (is_string)
        {
            for (int it = 0; it < len; it++)
            {
                arr[it] = '\0';
            }
        }
        else
        {
            for (int it = 0; it < len; it++)
            {
                arr[it] = '\0';
            }
        }
    }

    void Writer(T input)
    {
        if (dif >= 0 && dif < len)
        {
            arr[Key_i] = input;
            Key_i = (Key_i + 1) % len;
            dif++;
        }
        else
        {
            throw "Full Node can't be filled\n";
        }
        return;
    }

    void Read_Remove()
    {
        dif--;

        if (dif >= 0 && dif < len)
        {
            arr[CPU_i] = '\0';
            CPU_i = (CPU_i + 1) % len;
        }
        else
        {
            throw "Empty Node can't be cleared!\n";
        }
        return;
    }

    void show()
    {

        for (int it = 0; it < len; it++)
        {
            cout << "- " << arr[it] << " ";
        }
        cout << "-" << endl;
        return;
    }
};

int main()
{
    try
    {
        CBuf<string, 3> circ1;
        circ1.Writer("javad");
        circ1.show();
        circ1.Writer("akbar");
        circ1.show();
        // when want to write more than capacity
        // circ1.Writer("reza");
        // circ1.show();
        // circ1.Writer("ali");

        CBuf<int, 4> circ2;
        circ2.Writer(2);
        circ2.show();
        circ2.Writer(3);
        circ2.show();
        circ2.Writer(12);
        circ2.show();
        circ2.Writer(10);
        circ2.show();
        // when want to write more than capacity
        // circ2.Writer(0);
        // circ2.show();
        circ2.Read_Remove();
        circ2.show();
        circ2.Read_Remove();
        circ2.show();
        circ2.Read_Remove();
        circ2.show();
        circ2.Read_Remove();
        circ2.show();
        // when want to remove an empty space
        // circ2.Read_Remove();
        // circ2.show();

        return 0;
    }
    catch (const char *text)
    {
        cout << text << endl;
        return 1;
    }
}