#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int fav_count = 0;

class contact
{
private:
    string Name, Num, PhoneCat;
    int Is_Fav = 0;

public:
    contact(string name, string num, string cat);
    void SetName(string name);
    string CheckName();
    string CheckNum();
    string CheckCat();
    void SetNum(string num);
    void SetCat(string cat);
    void SetFav(int order);
    void RemFav();
    int CheckFav();
    void SumFav(int sum);
    void Display();
};

void Reload_Fav();
void Edit_cont(string name);
void Search_cont(string str);

map<string, contact> Book;
map<int, contact> Fav;

int main()
{
    contact ali("Ali", "09111111111", "Home");
    contact reza("Reza", "09111111112", "Home");
    contact mammad("Mammad", "09111111113", "phone");
    string akbar;

    ali.SetFav(1);
    mammad.SetFav(2);
    reza.SetFav(1);

    Book.insert(pair<string, contact>("Ali", ali));
    Book.insert(make_pair("Reza", reza));
    Book.insert(make_pair("Mammad", mammad));

    cout << "Book:\n";
    for (auto person : Book)
    {
        cout << "\t";
        person.second.Display();
    }
    Reload_Fav();
    cout << "\nFavs:\n";
    for (auto person : Fav)
    {
        cout << "\t" << person.first << ". ";
        person.second.Display();
    }

    
    Search_cont("a");
}

contact::contact(string name, string num, string cat)
{
    Name = name;
    Num = num;
    PhoneCat = cat;
}

void contact::SetName(string nme)
{
    cout << nme << this->Name;
    this->Name = nme;
    Name = nme;
    cout << nme << this->Name;
}
string contact::CheckName()
{
    return Name;
}
string contact::CheckNum()
{
    return Num;
}
string contact::CheckCat()
{
    return PhoneCat;
}
void contact::SetNum(string num)
{
    this->Num = num;
}
void contact::SetCat(string cat)
{
    this->PhoneCat = cat;
}
void contact::SetFav(int order)
{
    if (CheckFav())
    {
        cout << "already a favorite!\n";
        return;
    }
    else
    {
        Is_Fav = order;
        for (auto each : Fav)
        {
            if (each.second.CheckFav() >= CheckFav())
                each.second.SumFav(1);
        }
        cout << order << "akbar\n";
        fav_count++;
    }
}
void contact::RemFav()
{
    if (!CheckFav())
    {
        cout << "not a favorite!\n";
        return;
    }
    for (auto each : Fav)
    {
        if (each.second.CheckFav() >= CheckFav())
            each.second.SumFav(-1);
    }
    fav_count--;
    Is_Fav = 0;
}
int contact::CheckFav()
{
    return Is_Fav;
}
void contact::SumFav(int sum)
{
    Is_Fav += sum;
    return;
}

void contact::Display()
{
    cout << Name << "\t\tNumber (" << PhoneCat << "):\t" << Num << endl;
    return;
}

void Reload_Fav()
{
    Fav.clear();
    for (auto person : Book)
    {
        if (person.second.CheckFav())
        {
            Fav.insert(pair<int, contact>(person.second.CheckFav(), person.second));
        }
    }
    return;
}

void Edit_cont(string name)
{
    string temp;
    int choose;
    contact *selected;

    for (auto each : Book)
    {
        if (each.second.CheckName() == name)
        {
            selected = &each.second;
            break;
        }
    }
    cout << "---Which one you want to change?\n1- Name\n2- Num\n3- PhoneCat\nChoose : ";
    cin >> choose;
    switch (choose)
    {

    case 1:
        cout << "what name do you want : ";
        cin >> temp;
        selected->SetName(temp);
        break;

    case 2:
        cout << "what number do you want : ";
        cin >> temp;
        selected->SetNum(temp);
        break;

    case 3:
        cout << "what Category do you want : ";
        cin >> temp;
        selected->SetCat(temp);
        break;
    }
}

void Search_cont(string str)
{
    cout << "finded items :" << endl;
    for (auto each : Book)
    {
        if (each.second.CheckName().find(str) != string::npos)
        {
            cout << "\t";
            each.second.Display();
        }
    }
    return;
}