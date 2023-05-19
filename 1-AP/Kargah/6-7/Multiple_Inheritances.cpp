#include <iostream>
#include <string>

using namespace std;

class Teacher
{
protected:
    int Salary;

public:
    Teacher()
    {
        Salary = 0;
    }
    Teacher(int salary)
    {
        Salary = salary;
    }
    void print()
    {
        cout << Salary << endl;
        return;
    }
};

class Student
{
protected:
    int GPA;

public:
    Student()
    {
        GPA = 0;
    }
    Student(int gpa)
    {
        GPA = gpa;
    }
    void print()
    {
        cout << GPA << endl;
        return;
    }
};

class TeacherAssistant : Student, Teacher
{
protected:
    bool HasYektaAccess;

public:
    TeacherAssistant()
    {
        HasYektaAccess = false;
    }
    TeacherAssistant(int salary, int gpa, bool hasYektaAccess) : Student(gpa), Teacher(salary)
    {
        HasYektaAccess = false;
    }
    void print()
    {
        cout << Salary << "\t" << GPA << "\t" << (HasYektaAccess ? "Have Yekta Access" : "Don't have Yekta Access") << endl;
        return;
    }
};

int main()
{
    Teacher akbar(12);
    akbar.print();
    Student asgar(5);
    asgar.print();
    TeacherAssistant arsalan(20, 10, true);
    arsalan.print();

    return 0;
}