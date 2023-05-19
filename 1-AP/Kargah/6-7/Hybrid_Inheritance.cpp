#include <iostream>
#include <string>

using namespace std;

class Employee
{
protected:
    string ID;
    int Salary;

public:
    Employee()
    {
        ID = "0000";
        Salary = 0;
    }
    Employee(string id, int salary)
    {
        ID = id;
        Salary = salary;
    }
    void print()
    {
        cout << ID << "\t" << Salary << endl;
        return;
    }
};

class Manager : public virtual Employee
{
protected:
    string Department;

public:
    Manager()
    {
        Department = "No Where";
    }
    Manager(string id, int salary, string department) : Employee(id, salary)
    {
        Department = department;
    }
    void print()
    {
        cout << ID << "\t" << Salary << "\t" << Department << endl;
        return;
    }
};

class Salesperson : public virtual Employee
{
protected:
    string Commission;

public:
    Salesperson()
    {
        Commission = "Nothing";
    }
    Salesperson(string id, int salary, string commission) : Employee(id, salary)
    {
        Commission = commission;
    }
    void print()
    {
        cout << ID << "\t" << Salary << "\t" << Commission << endl;
        return;
    }
};

class SalesManager : public Manager, public Salesperson
{
protected:
    int Sales_Count;

public:
    SalesManager()
    {
        Sales_Count = 0;
    }
    SalesManager(string id, int salary, string department, string commission, int sales_count) : Manager(id, salary, department), Salesperson(id, salary, commission)
    {
        Sales_Count = 0;
        ID = id;
        Salary = salary;
    }
    void print()
    {
        cout << ID << "\t" << Salary << "\t" << Department << "\t" << Commission << endl;
        return;
    }
};

int main()
{
    Employee akbar("40101", 100);
    akbar.print();
    Manager asgar("40101", 200, "digikala");
    asgar.print();
    Salesperson mammad("40101", 300, "snap");
    mammad.print();
    SalesManager reza("40102", 400, "digikala", "snap", 10);
    reza.print();
    return 0;
}