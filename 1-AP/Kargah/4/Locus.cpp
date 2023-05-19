#include "Locus.h"
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <random>

Locus::Locus()
{
    head = new Point[size = 3];
    for (int i = 0; i < 3; i++)
    {
        head[i].set_x(rand() % 20 - 10);
        head[i].set_y(rand() % 20 - 10);
    }
}

Locus::Locus(int x2_count)
{
    size = x2_count;
    head = new Point[size];
    for (int i = 0; i < size; i++)
    {
        head[i].set_x(i);
        head[i].set_y(i * i);
    }
}

Locus::Locus(int s, Point *p)
{
    int flag = 0;
    size = s;
    head = new Point[size];

    if (dublicate_checker(p))
    {
        for (int i = 0; i < size; i++)
        {
            head[i].set_x(p[i].get_x());
            head[i].set_y(p[i].get_y());
        }
    }
    else
    {
        std::cout << "dublicated point!" << std::endl;
    }
}

Locus::Locus(Locus &temp)
{
    size = temp.size;
    head = new Point[size];
    for (int i = 0; i < size; i++)
    {
        head[i].set_x(temp.head[i].get_x());
        head[i].set_y(temp.head[i].get_y());
    }
}

Locus::~Locus()
{
    delete[] head;
    std::cout << "memmory de-allocated!\n";
}

int Locus::dublicate_checker(Point *p)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (p[i].get_x() == p[j].get_x())
            {
                if (p[i].get_y() == p[j].get_y())
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

bool Locus::is_mohdab()
{
    bool pos = false, neg = false;
    // Sorting();

    for (int i = 0; i < size; i++)
    {
        int a = i;
        int b = (i + 1) % size;
        int c = (i + 2) % size;

        int taaghor = jahat_taaghor(head[a].get_x(), head[a].get_y(), head[b].get_x(), head[b].get_y(), head[c].get_x(), head[c].get_y());
        if (taaghor > 0)
            pos = true;
        else if (taaghor < 0)
            neg = true;
        if (pos && neg)
            return false;
    }
    return true;
}

int Locus::jahat_taaghor(int a_x, int a_y, int b_x, int b_y, int c_x, int c_y)
{
    int X_AB = b_x - a_x;
    int Y_AB = b_y - a_y;
    int X_BC = b_x - c_x;
    int Y_BC = c_y - b_y;

    return (X_AB * Y_BC - X_BC * Y_AB);
}

int Locus::Mohit()
{
    int mohit = 0;
    for (int i = 0; i < size; i++)
        mohit += sqrt(((head[i].get_x() - head[(i + 1) % size].get_x()) * (head[i].get_x() - head[(i + 1) % size].get_x())) + (head[i].get_y() - head[(i + 1) % size].get_y()) * (head[i].get_y() - head[(i + 1) % size].get_y()));
    return mohit;
}

int Locus::Masahat()
{
    int masahat = 0;
    for (int i = 0; i < size - 2; i++)
        masahat += fabs((double)jahat_taaghor(head[i].get_x(), head[i].get_y(), head[i + 1].get_x(), head[i + 1].get_y(), head[i + 2].get_x(), head[i + 2].get_y()) / 2);
    return masahat;
}

Point Locus::centroid()const 
{
    int cx = 0, cy = 0;
    for (int i = 0; i < size; i++)
    {
        cx += head[i].get_x();
        cy += head[i].get_y();
    }
    Point a(cx / size, cy / size);
    return a;
}

double Locus::get_clockwise_angle(const Point &p)
{
    double angle = 0.0;
    // angle = -atan2(p.get_x, p.get_y);
    return angle;
}

bool Locus::compare_points(const Point &a, const Point &b)
{
    return (get_clockwise_angle(a) < get_clockwise_angle(b));
}

void Locus::Sorting()
{
    // the bellow command has a bug that i couldn't fix. but all the other parts are completley working.
    // std::sort(head, head+ size - 1, compare_points);
}

void Locus::show_points()
{
    for (int i = 0; i < size; i++)
    {
        std::cout << '(' << head[i].get_x() << ',' << head[i].get_y() << ')' << std::endl;
    }
}