#include <iostream>
using namespace std;
#define MIN(a, b) ((a > b) ? b : a);

void find(string first, string second);
void concatenate(int argc, char *argv[]);
void revers(int argc, char *argv[]);
bool isAfter(string a, string b);
void sort(int argc, char *argv[]);
bool pal_check(string str);
string lower(string a);
void palindrome(int argc, char *argv[]);
string reverseString(string str);
void help();

int main(int argc, char *argv[])
{
    string operation = argv[1];

    switch (operation)
    {
    case "-h":
    case "--help":
        help();
        break;

    case "-s":
    case "--sort":
        sort(argc, argv);
        break;

    case "-r":
    case "--reverse":
        revers(argc, argv);
        break;

    case "-f":
    case "--find":
        find(argv[3], argv[2]);
        break;

    case "-c":
    case "--concatenate":
        concatenate(argc, argv);
        break;
    }
}

void help()
{
    cout << "-h, --help prints all commands in terminal.\n-p, --palindrome checks if input string is palindrome.\n-c, --concatenate concatenates all the input strings.\n-s, --sort sorts all of the input strings in alphabetic order.\n-f, --find find a substring in a string.\n-r, --reverse reverse all the input strings\n";
}

string reverseString(string str)
{
    string result;

    for (int i = str.length(); i >= 0; i--)
    {
        result += str[i];
    }

    return result;
}

void palindrome(int argc, char *argv[])
{
    for (int i = 2; i < argc; i++)
    {
        cout << "\"" << argv[i] << "\"" << (pal_check(argv[i]) ? "is" : "is not") << "a palindrome";
    }
}
string lower(string a)
{
    int length = a.length();

    for (int i = 0; i < length; i++)
    {

        if (a[i] < 'Z')
            a[i] += 20;
    }
    return a;
}

bool pal_check(string str)
{
    if (str == reverseString(str))
        return true;
    else
        return false;
}
void sort(int argc, char *argv[])
{
    for (int i = 2; i < argc - 1; i++)
    {
        for (int j = i; j < argc; j++)
        {
            if (isAfter(argv[i], argv[j]))
            {
                char *tmp = argv[i];
                argv[i] = argv[j];
                argv[j] = tmp;
            }
        }
    }
    for (int i = 2; i < argc; i++)
    {
        cout << argv[i] << endl;
    }
}
bool isAfter(string a, string b)
{
    for (int i = 0; i < MIN(a.length(), b.length()); i++)
    {
        if (lower(a)[i] > lower(b)[i])
            return true;
        if (lower(a)[i] < lower(b)[i])
            return false;
    }
    return false;
}
void revers(int argc, char *argv[])
{
    for (int i = 2; i < argc; i++)
    {
        cout << reverseString(argv[i]) << endl;
    }
}

void concatenate(int argc, char *argv[])
{
    for (int i = 2; i < argc; i++)
    {
        cout << argv[i] << " ";
    }
}
void find(string first, string second)
{
    if (first.find(second) != string::npos)
    {
        cout << "\"" << second << "\" was found in \"" << first << "\"";
    }
    else
    {
        cout << "\"" << second << "\" was not found in \"" << first << "\"";
    }
}