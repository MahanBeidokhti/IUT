#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
protected:
    int Fuel_Cap;

public:
    Vehicle()
    {
        Fuel_Cap = 0;
    }
    Vehicle(int fule_cap)
    {
        Fuel_Cap = fule_cap;
    }
    void print()
    {
        cout << Fuel_Cap << endl;
        return;
    }
};

class Car : public Vehicle
{
protected:
    int Wheels;

public:
    Car()
    {
        Wheels = 0;
    }
    Car(int wheels, int fuel_cap) : Vehicle(fuel_cap)
    {
        Wheels = wheels;
    }
    void print()
    {
        cout << Fuel_Cap << "\t" << Wheels << endl;
        return;
    }
};

class SportCar : Car
{
protected:
    int Speed;

public:
    SportCar()
    {
        Speed = 0;
    }
    SportCar(int speed, int wheels, int fuel_cap) : Car(wheels, fuel_cap)
    {
        Speed = speed;
    }
    void print()
    {
        cout << Fuel_Cap << "\t" << Wheels << "\t" << Speed << endl;
        return;
    }
};

int main()
{
    Vehicle ford(10);
    ford.print();
    Car mustang(4, 20);
    mustang.print();
    SportCar t11(160, 3, 30);
    t11.print();

    return 0;
}