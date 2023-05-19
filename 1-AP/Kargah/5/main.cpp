#include <iostream>
#include <string>

class number
{
private:
    char *nmb;
    int size;

public:
    number()
    {
        size = 1;
        nmb = new char[size];
        nmb[0] = '0';
    };
    number(int size, char *input_nmb)
    {
        this->size = size;
        nmb = new char[2];
        for (int i = 0; i <= size; i++)
        {
            nmb[i] = input_nmb[i];
        }
    };
    number(number &inpt)
    {
        size = inpt.size;

        nmb = new char[size];

        for (int i = 0; i < size; i++)
        {
            nmb[i] = inpt.nmb[i];
        }
    };
    ~number()
    {
        std::cout << "memory de-allocated!\n";
    };

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << nmb[i];
        }
    }

    char *operator=(number num2)
    {
        nmb = new char[num2.size];
        for (int i = 0; i < num2.size; i++)
        {
            nmb[i] = num2.nmb[i];
        }
        return nmb;
    }
    char *operator=(int num2)
    {
        int len = 0, temp = num2, digit;
        for (; temp; len++)
        {
            temp /= 10;
        }

        nmb = new char[len];
        for (int i = 0; i < len; i++)
        {
            digit = num2 % 10;
            num2 /= 10;
            nmb[i] = digit;
        }
        return nmb;
    }

    number operator+(int num2) 
    {
        int flag = 0, digit, sum = 0;

        for (int i = size - 1; i >= 0; i--)
        {
            if (flag == 1)
            {
                num2 += 1;
                flag = 0;
            }
            else if (num2 == 0)
            {
                break;
            }
            digit = num2 % 10;

            num2 /= 10;

            sum = (nmb[i] - 48) + digit;
            if (sum > 9)
            {
                flag = 1;
                sum -= 10;
            }

            nmb[i] = sum + 48;
        }
        if (flag == 1)
        {
            char *temp;
            temp = new char[size];
            for (int i = 0; i < size; i++)
            {
                temp[i] = nmb[i];
            }

            nmb = new char[size + 1];

            for (int i = 0; i < size; i++)
            {
                nmb[i + 1] = temp[i];
            }

            nmb[1] -= 1;

            nmb[0] = '1';
        }
        return *this;
    };
    char *operator+(number num2)
    {
        int flag = 0, digit, sum = 0;

        for (int i = size - 1; i >= 0; i--)
        {
            if (flag == 1)
            {
                num2 = num2 + 1;
                flag = 0;
            }

            digit = num2[i] - 48;

            sum = (nmb[i] - 48) + digit;
            if (sum > 9)
            {
                flag = 1;
                sum -= 10;
            }

            nmb[i] = sum + 48;
        }
        if (flag == 1)
        {
            char *temp;
            temp = new char[size];
            for (int i = 0; i < size; i++)
            {
                temp[i] = nmb[i];
            }

            nmb = new char[size + 1];

            for (int i = 0; i < size; i++)
            {
                nmb[i + 1] = temp[i];
            }

            nmb[1] -= 1;

            nmb[0] = '1';
        }
        return nmb;
    }

    char *operator-(int num2)
    {
        int flag = 0, digit, sum = 0;

        for (int i = size - 1; i >= 0; i--)
        {
            if (flag == 1)
            {
                nmb[i] += 10;
                flag = 0;
            }
            else if (num2 == 0)
            {
                break;
            }
            digit = num2 % 10;

            num2 /= 10;

            sum = (nmb[i] - 48) + digit;
            if (sum > 9)
            {
                flag = 1;
                sum -= 10;
            }

            nmb[i] = sum + 48;
        }
        if (flag == 1)
        {
            char *temp;
            temp = new char[size];
            for (int i = 0; i < size; i++)
            {
                temp[i] = nmb[i];
            }

            nmb = new char[size + 1];

            for (int i = 0; i < size; i++)
            {
                nmb[i + 1] = temp[i];
            }

            nmb[1] -= 1;

            nmb[0] = '1';
        }

        return nmb;
    }
};

int main()
{
    char x[] = "24";
    number a;
    number b(2, x);
    number c(b);

    std::cout << "a is : ";
    a.print();
    std::cout << std::endl;

    std::cout << "b+1 is : ";
    // b = b + 1;
    // std::cout << b + 190;
    std::cout << std::endl;

    std::cout << "c is : ";
    c.print();
    std::cout << std::endl;
}