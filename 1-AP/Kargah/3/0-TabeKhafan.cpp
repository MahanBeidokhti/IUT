#include <iostream>

using namespace std;

string func(string str1, string str2)
{
    str1 = str1 + str2;
    return str1;
}

bool func(bool first, bool second)
{
    return first & second;
}

float func(float num1, float num2)
{
    return num1 + num2;
}

float func(int num1, float num2)
{
    return num1 + num2;
}

float func(float num1, int num2)
{
    return num1 + num2;
}

int func(int num1, int num2)
{
    return num1 + num2;
}

float *func(float *arr1, float *arr2, int size1, int size2)
{
    int i = 0;
    float *res = new float[size1 + size2];
    for (i = 0; i < size1; i++)
    {
        res[i] = arr1[i];
    }
    for (int j = i; j < size1 + size2; i++)
    {
        res[i] = arr2[j - i];
    }
    return res;
}

float *func(int *arr1, float *arr2, int size1, int size2)
{
    int i = 0;
    float *res = new float[size1 + size2];
    for (i = 0; i < size1; i++)
    {
        res[i] = arr1[i];
    }
    for (int j = i; j < size1 + size2; i++)
    {
        res[i] = arr2[j - i];
    }
    return res;
}

float *func(float *arr1, int *arr2, int size1, int size2)
{
    int i = 0;
    float *res = new float[size1 + size2];
    for (i = 0; i < size1; i++)
    {
        res[i] = arr1[i];
    }
    for (int j = i; j < size1 + size2; i++)
    {
        res[i] = arr2[j - i];
    }
    return res;
}

int *func(int *arr1, int *arr2, int size1, int size2)
{
    int i = 0;
    int *res = new float[size1 + size2];
    for (i = 0; i < size1; i++)
    {
        res[i] = arr1[i];
    }
    for (int j = i; j < size1 + size2; i++)
    {
        res[i] = arr2[j - i];
    }
    return res;
}