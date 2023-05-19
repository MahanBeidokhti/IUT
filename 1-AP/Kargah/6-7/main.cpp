// for now it has lots of bugs
// after entering the second phase , i will debug theme

#include <iostream>
#include <string>
#include <list>

using namespace std;

static int ID_Gen = 0;
// static list<Ostad> Ostad_list;
// static list<Daneshjoo> Daneshjoo_list;

// void print_Teachers()
// {
//     for (auto x : Ostad_list)
//     {
//         cout << x.Get_name();
//     }
// }
// void print_Students()
// {
//     for (auto x : Daneshjoo_list)
//     {
//         cout << x.Get_name();
//     }
// }


class Person
{
protected:
    bool Is_Teacher, Is_Student;

    // if right digit of Yekta_ID was 1 , the Person is a Teacher and if it was 2 , it is a Student
    string Name, Yekta_ID;
    int ID, Age;

public:
    Person()
    {
        ID_Gen++;
        Name = "None";
        ID = ID_Gen;
        Yekta_ID = "00000000";
        Age = 0;
        Is_Student = false;
        Is_Teacher = false;
    }
    Person(string name, string yekta_id, int age)
    {
        ID_Gen++;
        Name = name;
        ID = ID_Gen;
        Yekta_ID = yekta_id;
        Age = age;
        if (Yekta_ID[7] == '1')
        {
            Is_Teacher = true;
            Is_Student = false;
        }
        else if (Yekta_ID[7] == '2')
        {
            Is_Student = true;
            Is_Teacher = false;
        }
    }

    virtual void Personal_Print() = 0;
};

class Lesson
{
protected:
    string Start_Time, End_Time, Name, Place;
    Ostad *Teacher;
    int ID;
    list<Daneshjoo *> ShagerdHa;

public:
    Lesson()
    {
        ID_Gen++;
        ID = ID_Gen;
        Start_Time = "00:00";
        End_Time = "00:00";
        Name = "None";
        Place = "No_Where";
    }
    Lesson(string start, string end, string name, string place, Ostad &teacher)
    {
        ID_Gen++;
        ID = ID_Gen;
        Start_Time = start;
        End_Time = end;
        Name = name;
        Place = place;
        Teacher = teacher;
    }
    void Set_Teacher(Ostad &teacher)
    {
        Teacher = teacher;
        Teacher.Add_Lesson(*this);
    }
    void Add_Daneshjoo(Daneshjoo &bache)
    {
        ShagerdHa.push_back(&bache);
    }
    void Remove_Daneshjoo(Daneshjoo &bache)
    {
        // bache.//remove dars from bache   aaaaaaaaaaaaaaaaaaaaaaaaaa
        ShagerdHa.remove(&bache);
    }
    void time_print()
    {
        cout << Start_Time << " - " << End_Time;
    }
    void full_print()
    {
        cout << "Lesson : " << Name << " with ID " << ID << "\nTeacher : " << Teacher << "\nStudents : \n";
        int i = 0;
        for (auto bache : ShagerdHa)
        {
            i++;
            cout << i << ". " << bache. // tabe name baraye daneshjooo;
        }
        cout << "Time : " << Start_Time << " - " << End_Time << "\nPlace : " << Place << endl;
    }
};

class Ostad : public Person
{
protected:
    list<Lesson *> Doroos;
    list<Daneshjoo *> Class;

public:
    Ostad()
    {
    }
    Ostad(string name, string yekta_id, int age, list<Lesson> doroos, list<Daneshjoo> clas) : Person(name, yekta_id, age)
    {
        Doroos = doroos;
        for (auto dars : doroos)
        {
            dars.Add_Ostad(*this);
        }
        Class = clas;
        for (auto daneshjoo : clas)
        {
            daneshjoo.
        }
    }
    Ostad(string name, string yekta_id, int age) : Person(name, yekta_id, age)
    {
        Lesson none1;
        Doroos.push_front(none1);
        Daneshjoo none2;
        Doroos.push_front(none2);
    }
    Ostad(Ostad &temp)
    {
        this->Name = temp.Name;
        this->Age = temp.Age;
        this->ID = temp.ID;
        this->Yekta_ID = temp.Yekta_ID;
        this->Is_Student = temp.Is_Student;
        this->Is_Teacher = temp.Is_Teacher;
        this->Class = temp.Class;
        this->Doroos = temp.Doroos;
    }
    void Add_Lesson(Lesson &Dars)
    {
        Doroos.push_front(&Dars);
    }
    void Personal_Print()
    {
        cout << "Teacher Code : " << Yekta_ID << " Name : " << Name << "\nAge : " << Age << "\nID : " << ID << endl;
    }
    void Get_name()
    {
        cout << Name;
    }
};

class Daneshjoo : public Person
{
protected:
    list<Lesson> Doroos;

public:
    Daneshjoo()
    {
        Lesson none;
        Doroos.push_front(none);
    }
    Daneshjoo(string name, string yekta_id, int age, list<Lesson> doroos) : Person(name, yekta_id, age)
    {
        Doroos = doroos;
    }
    Daneshjoo(Daneshjoo &temp)
    {
        this->Name = temp.Name;
        this->Age = temp.Age;
        this->ID = temp.ID;
        this->Yekta_ID = temp.Yekta_ID;
        this->Is_Student = temp.Is_Student;
        this->Is_Teacher = temp.Is_Teacher;
        this->Doroos = temp.Doroos;
    }
    void Add_Lesson(Lesson &Dars)
    {
        Doroos.push_front(&Dars);
    }
    void Remove_Lesson(Lesson &Dars)
    {
        Doroos.remove(&Dars);
    }
    void Personal_Print()
    {
        cout << "Student Code : " << Yekta_ID << " Name : " << Name << "\nAge : " << Age << "\nID : " << ID << endl;
    }
    void Get_name()
    {
        cout << Name;
    }
};

int main()
{
}