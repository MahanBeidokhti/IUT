#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
protected:
    string Name, Mail, Phone;

public:
    Vehicle()
    {
        Name = "No Name";
        Mail = "Nothing@nithing.none";
        Phone = "09000000000";
    }
    Vehicle(string name, string mail, string phone)
    {
        Name = name;
        Mail = mail;
        Phone = phone;
    }
    void print()
    {
        cout << Name << "\t" << Mail << "\t" << Phone << endl;
        return;
    }
};

class Car : public Vehicle
{
protected:
    string STDNT;
    double AVG;

public:
    Car()
    {
        STDNT = "00000";
        AVG = 00.00;
    }
    Car(string name, string mail, string phone, string stdnt, double avg) : Vehicle(name, mail, phone)
    {
        STDNT = stdnt;
        AVG = avg;
    }
    void print()
    {
        cout << Name << "\t" << Mail << "\t" << Phone << "\t" << STDNT << "\t" << AVG << endl;
        return;
    }
};

int main()
{
    Vehicle Asghar("asgar", "asgar@gmail.com", "09184575701");
    Asghar.print();
    Car akbar("akbar", "akbar@gmail.com", "09184575704", "40101", 18.6);
    akbar.print();

    return 0;
}