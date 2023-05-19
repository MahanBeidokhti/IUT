#include <iostream>
using namespace std;

class Time
{
public:
    Time(string H, string M)
    {
        if ((hour == "00" || hour == "01" || hour == "02" || hour == "03" || hour == "04" || hour == "05" || hour == "06" || hour == "07" || hour == "08" || hour == "09" || hour == "10" || hour == "11" || hour == "12" || hour == "13" || hour == "14" || hour == "15" || hour == "16" || hour == "17" || hour == "18" || hour == "19" || hour == "20" || hour == "21" || hour == "22" || hour == "23") || (hour == "24" || minute == "00"))
        {
            if (((minute[0] == '0' || minute[0] == '1' || minute[0] == '2' || minute[0] == '3' || minute[0] == '4' || minute[0] == '5') || (minute[0] == '6' && minute[1] == '0')) && (minute[1] > 47 && minute[1] < 58))
            {
                hour = H;
                minute = M;
            }
        }
        exit();
    }

    Time(string H)
    {
        hour = H;
        minute = "00";
    }
    void compare(Time temp)
    {
        if (temp.hour[0] == hour[0])
        {
            if (temp.hour[1] == hour[1])
            {
                if (temp.minute[0] == minute[0])
                {
                    if (temp.minute[1] == minute[1])
                    {
                        cout << "barabaran";
                    }
                    else if (temp.minute[0] < minute[0])
                    {
                        cout << "koochik tare";
                    }
                    else
                    {
                        cout << "bozorg tare";
                    }
                }
                else if (temp.minute[0] < minute[0])
                {
                    cout << "koochik tare";
                }
                else
                {
                    cout << "bozorg tare";
                }
            }
            else if (temp.hour[1] < hour[1])
            {
                cout << "koochik tare";
            }
            else
            {
                cout << "bozorg tare";
            }
        }
        else if (temp.hour[0] < hour[0])
        {
            cout << "koochik tare";
        }
        else
        {
            cout << "bozorg tare";
        }
    }

    void rooz()
    {
        if (hour == "00" || hour == "01" || hour == "02" || hour == "03" || hour == "04" || hour == "05" || hour == "06" || hour == "07" || hour == "08" || hour == "09" || hour == "10" || hour == "11")
        {
            cout << "sobh";
        }
        else if (hour == "12" && minute == "00")
        {
            cout << "zohr";
        }
        else if (hour == "12" || hour == "13" || hour == "14" || hour == "15" || hour == "16")
        {
            cout << "bad az zohr";
        }
        else if (hour == "17" || hour == "18" || hour == "19")
        {
            cout << "asr";
        }
        else
        {
            cout << "shab";
        }
    }
    string getter_hour()
    {
        return hour;
    }
    string getter_minute()
    {
        return minute;
    }
    void setter_hour()
    {
        string hours;
        cin >> hours;
        hour = hours;
    }
    void setter_minute()
    {
        string minutes;
        cin >> minutes;
        minute = minutes;
    }

private:
    string hour;
    string minute;
}

int
main()
{
}