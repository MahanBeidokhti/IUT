#include "Point.h"
#include <iostream>

Point::Point()
{
    x = rand();
    y = rand();
}

Point::Point(int in_x)
{
    x = in_x;
    y = rand();
}
Point::Point(int in_x, int in_y)
{
    x = in_x;
    y = in_y;
}
Point::Point(Point &p)
{
    x = p.get_x();
    y = p.get_y();
}
int Point::get_x()
{
    return x;
}
int Point::get_y()
{
    return y;
}
void Point::set_x(int num)
{
    x = num;
}
void Point::set_y(int num)
{
    y = num;
}
Point::~Point()
{
    std::cout << "data for ("<< x << ","<< y<<") freed!\n";
}
void Point::show()
{
    std::cout << '(' << x << ',' << y << ')' << std::endl;
}