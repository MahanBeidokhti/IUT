#include "Locus.h"
#include <iostream>
#include <time.h>

using namespace std;

void temp_point()
{
    Point temp();
    return;
}

int main()
{
    srand(time(0));
    //...............using "point" funcs
    Point a, b(10), c(10, 12);
    Point d(c);
    cout << "point d: x and y is : " << d.get_x() << " and " << d.get_y() << endl;
    d.set_x(5);
    d.set_y(5);
    cout << "point d: x and y is : " << d.get_x() << "and " << d.get_y() << endl;

    cout << "\ncheking if distructor is working or not :";
    temp_point();

    b.show();

    //...............using Locus funcs
    Locus one, two(3);

    // using constructor if non of the points are dublicated
    Point NumList1[4] = {a, b, c, d};
    Locus three(4, NumList1);
    three.show_points();
    cout << "\n";

    // using constructor if any of the points are dublicated
    Point f(d);
    Point NumList2[4] = {a, b, d, f};
    Locus four(4, NumList2);
    four.show_points();
    cout << "\n";

    if (four.is_mohdab())
    {
        cout << "four is mohadab!";
        cout << "\nmohit is : " << four.Mohit();
        cout << "\nmasahat is : " << four.Masahat() << endl;
    }
    else
        cout << "four is not mohadab" << endl;


    
    //...............using distructor funcs
    return 0;
}