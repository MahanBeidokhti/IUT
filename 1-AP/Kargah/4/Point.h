#pragma once

class Point
{
private:
    int x, y;

public:
    Point();
    Point(int in_x);
    Point(int in_x, int in_y);
    Point(Point &p);
    int get_x();
    int get_y();
    void set_x(int num);
    void set_y(int num);
    ~Point();
    void show();
};