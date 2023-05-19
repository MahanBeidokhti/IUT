// #include "Locus.h"
// #include <iostream>
// #include <time.h>
// #include <algorithm>
// #include <cmath>

// using namespace std;

// class Point
// {
// private:
//     int x, y;

// public:
//     Point()
//     {
//         x = rand();
//         y = rand();
//     }
//     Point(int in_x)
//     {
//         x = in_x;
//         y = rand();
//     }
//     Point(int in_x, int in_y)
//     {
//         x = in_x;
//         y = in_y;
//     }
//     Point(Point &p)
//     {
//         x = p.x;
//         y = p.y;
//     }
//     int get_x()
//     {
//         return x;
//     }
//     int get_y()
//     {
//         return y;
//     }
//     void set_x(int num)
//     {
//         x = num;
//     }
//     void set_y(int num)
//     {
//         y = num;
//     }
//     ~Point()
//     {
//         cout << "finished!\n";
//     }
//     void show()
//     {
//         cout << '(' << x << ',' << y << ')' << endl;
//     }
// };

// class Locus
// {
// private:
//     int size;
//     Point *head;

// public:
//     Locus()
//     {
//         head = new Point[3];
//         for (int i = 0; i < 3; i++)
//         {
//             head[i](rand() % 20 - 10, rand() % 20 - 10);
//         }
//     }
//     Locus(int x2_count)
//     {
//         size = x2_count;
//         head = new Point[size];
//         for (int i = 0; i < size; i++)
//         {
//             head[i](i, i * i);
//         }
//     }
//     Locus(int s, Point *p)
//     {
//         int flag = 0;
//         size = s;

//         if (dublicate_checker())
//         {
//             for (int i = 0; i < size; i++)
//             {
//                 head[i].set_x(p[i].get_x);
//                 head[i].set_y(p[i].get_y);
//             }
//         }
//     }
//     Locus(Locus &temp)
//     {
//         size = temp.size;
//         for (int i = 0; i < size; i++)
//         {
//             head[i].set_x(p[i].get_x);
//             head[i].set_y(p[i].get_y);
//         }
//     }
//     ~Locus()
//     {
//         delete head;
//         cout << "memmory de-allocated!\n";
//     }
//     int dublicate_checker()
//     {
//         for (int i = 0; i < size; i++)
//         {
//             for (int j = i + 1; j < size; j++)
//             {
//                 if (p[i].get_x() == p[j].get_x())
//                 {
//                     if (p[i].get_y() == p[j].get_y())
//                     {
//                         return 0;
//                     }
//                 }
//             }
//         }
//         return 1;
//     }
//     bool is_mohdab()
//     {
//         bool pos = false, neg = false;

//         for (int i = 0; i < size; i++)
//         {
//             int a = i;
//             int b = (i + 1) % size;
//             int c = (i + 2) % size;

//             int taaghor = jahat_taaghor(head[a].get_x(), head[a].get_y(), head[b].get_x(), head[b].get_y(), head[c].get_x(), head[c].get_y());
//             if (taaghor > 0)
//                 pos = true;
//             else if (taaghor < 0)
//                 neg = true;
//             if (pos && neg)
//                 return false;
//         }
//         return true;
//     }
//     int jahat_taaghor(int a_x, int a_y, int b_x, int b_y, int c_x, int c_y)
//     {
//         int X_AB = b_x - a_x;
//         int Y_AB = b_y - a_y;
//         int X_BC = b_x - c_x;
//         int Y_BC = c_y - b_y;

//         return (X_AB * Y_BC - X_BC * Y_AB);
//     }

//     void show_points()
//     {
//         for (int i = 0; i < size; i++)
//         {
//             cout << '(' << head[i].get_x() << ',' << head[i].get_y() << ')' << endl;
//         }
//     }
// };

// int main()
// {
//     srand(time(0));

//     return 0;
// }