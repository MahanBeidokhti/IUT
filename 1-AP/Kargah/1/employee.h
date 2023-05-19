// FirstName_LastName_StudentNumber: Denni_MacAlistair_Ritchie_40100003

typedef enum Level
{
    junior,
    midlevel,
    senior
} Level;

typedef struct user
{
    char Name[10];
    char Last_Name[10];
    char Melli_Code[10];
    char Birth_Day[10];
    int MoneyPerHour;
    int HoursPerMounth;
    Level Sath;
    int Salary;
    struct user *next;
} user;