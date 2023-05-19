#pragma once
#include "Point.h"

class Locus
{
private:
    int size;
    Point *head;

public:
    Locus();
    Locus(int x2_count);
    Locus(int s, Point *p);
    Locus(Locus &temp);
    ~Locus();
    int dublicate_checker(Point *p);
    bool is_mohdab();
    int jahat_taaghor(int a_x, int a_y, int b_x, int b_y, int c_x, int c_y);
    int Mohit();
    int Masahat();
    Point centroid() const;
    int get_quadrant(const Point &p);
    double get_clockwise_angle(const Point &p);
    bool compare_points(const Point &a, const Point &b);
    void Sorting();
    void show_points();
};