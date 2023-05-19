#include <iostream>
#include <string>
#include <cstring>

int num_len(int n)
{
    return n >= 10 ? num_len(n / 10) + 1 : 1;
}

class Number
{
public:
    Number()
    {
        size = 1;
        nmb = new char[size];
        nmb[0] = '0';
    };
    Number(int size, const char *nmb) : size(size), nmb(new char[size + 1])
    {
        std::strcpy(this->nmb, nmb);
    }
    Number(const Number &other) : size(other.size), nmb(new char[other.size + 1])
    {
        std::strcpy(this->nmb, other.nmb);
    }
    ~Number()
    {
        delete[] nmb;
    }

    // Number operator+(int other) const
    // {
    //     int length = num_len(other);
    //     char *str = new char[length + 1];
    //     std::memset(str, '0', length);
    //     str[length] = '\0';
    //     for (int i = length - 1; i >= 0; i--)
    //     {
    //         str[i] = other % 10;
    //         other /= 10;
    //     }
    //     std::cout << "akbarrrrrrrrrrrr" << str << "\n";
    //     Number temp(length, str);
    //     Number result = temp + *this;
    //     return result;
    // }

    Number operator+(const Number &other) const
    {
        int resultSize = std::max(size, other.size) + 1;

        char *result = new char[resultSize + 1];
        std::memset(result, '0', resultSize);
        result[resultSize] = '\0';

        int carry = 0;
        for (int i = 0; i < resultSize; i++)
        {
            int digit1 = (i < size) ? (nmb[size - 1 - i] - '0') : 0;
            int digit2 = (i < other.size) ? (other.nmb[other.size - 1 - i] - '0') : 0;
            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            result[resultSize - 1 - i] = '0' + (sum % 10);
        }

        int startIndex = 0;
        while (result[startIndex] == '0' && startIndex < resultSize - 1)
        {
            startIndex++;
        }

        Number resultNumber(resultSize - startIndex, result + startIndex);

        delete[] result;

        return resultNumber;
    }

    number operator-(const number &other) const
    {
        int largerSize = (size > other.size) ? size : other.size;

        char *result = new char[largerSize];

        int carry = 0;
        for (int i = 0; i < largerSize; i++)
        {
            int digit1 = (i >= size) ? 0 : (nmb[size - i - 1] - '0');
            int digit2 = (i >= other.size) ? 0 : (other.nmb[other.size - i - 1] - '0');

            int difference = digit1 - digit2 - carry;
            if (difference < 0)
            {
                difference += 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }

            result[largerSize - i - 1] = difference + '0';
        }

        int resultSize = largerSize;
        while (resultSize > 1 && result[0] == '0')
        {
            result++;
            resultSize--;
        }

        number resultNumber(resultSize, result);

        delete[] result;

        return resultNumber;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << nmb[i];
        }
    }

private:
    int size;
    char *nmb;
};

int main()
{
    char x[] = "24";
    Number a;
    Number b(2, x);
    Number c(b);

    std::cout << "a is : ";
    a.print();
    std::cout << std::endl;

    std::cout << "b+1 is : ";
    // b = b + 1;
    Number d(b - c);
    d.print();
    std::cout << std::endl;

    std::cout << "c is : ";
    c.print();
    std::cout << std::endl;
}