// FirstName_LastName_StudentNumber: Denni_MacAlistair_Ritchie_40100003

#include <stdio.h>
#include <malloc.h>
#include "employee.h"
#include <time.h>

user *New_Node()
{
    user *temp = malloc(sizeof(user));
    int sath;

    printf("name : ");
    scanf("%s", temp->Name);
    printf("last_name : ");
    scanf("%s", temp->Last_Name);
    printf("melli_code : ");
    scanf("%s", temp->Melli_Code);
    printf("birth_day : ");
    scanf("%s", temp->Birth_Day);
    printf("Money_per_hour : ");
    scanf("%d", &temp->MoneyPerHour);
    printf("Hours_Per_Mounth : ");
    scanf("%d", &temp->HoursPerMounth);
    printf("Level(1, 2 or 3) : ");
    scanf("%d", &sath);
    switch (temp->Sath)
    {
    case 1:
        temp->Sath = junior;
        break;

    case 2:
        temp->Sath = midlevel;
        break;

    case 3:
        temp->Sath = senior;
        break;
    }
    printf("Padash : ");
    scanf("%d", &temp->Salary);
    temp->next = NULL;
    return temp;
}
void push_front(user **head, user **tale)
{
    user *temp = New_Node();
    if (*head == NULL)
    {
        *head = temp;
        *tale = temp;
    }
    else
    {
        temp->next = *head;
        *head = temp;
    }
    return;
}
void push_back(user **head, user **tale)
{
    user *temp = New_Node();
    if (*head == NULL)
    {
        *head = temp;
        *tale = temp;
    }
    else
    {
        *tale->next = temp;
        *tale = temp;
    }
    return;
}
void remove_front(user **head, user **tale)
{
    if (*head == NULL)
    {
        printf("Empty linked list!");
    }
    else
    {
        *head = *head->next;
    }
    return;
}
void remove_back(user **head, user **tale)
{
    user *temp;
    if (head == NULL)
    {
        printf("Empty linked list!");
    }
    else
    {
        temp = *head;
        while (temp != tale)
        {
            temp = temp->next;
        }
        *tale = temp;
        *tale->next = NULL;
    }
    return;
}
void remove_middle(user **head, user **tale, char melli[10])
{
    user *temp;
    if (head == NULL)
    {
        printf("Empty linked list!");
    }
    else
    {
        temp = *head;
        while (temp->next != NULL && temp->next->Melli_Code != melli)
        {
            temp = temp->next;
        }
        if (temp->next != NULL)
        {
            temp->next = temp->next->next;
        }
    }
    return;
}
void show_one(user *head, user *tale, char melli_code[10])
{
    user *temp;
    temp = head;
    if (temp == NULL)
    {
        printf("No employee!\n");
        return;
    }

    while (temp != tale)
    {
        if (melli_code == temp->Melli_Code)
        {
            printf("the employee named %s %s, is on level ", temp->Name, temp->Last_Name);
            switch (temp->Sath)
            {
            case 0:
                printf("junior, ");
                break;

            case 1:
                printf("midlevel, ");
                break;

            case 2:
                printf("senior, ");
                break;
            }
            printf("and his final salary per mounth is %d\n", temp->MoneyPerHour * temp->Salary * temp->HoursPerMounth);
            return;
        }
        temp = temp->next;
    }
    if (melli_code == temp->Melli_Code)
    {
        printf("the employee named %s %s, is on level ", temp->Name, temp->Last_Name);
        switch (temp->Sath)
        {
        case 0:
            printf("junior, ");
            break;

        case 1:
            printf("midlevel, ");
            break;

        case 2:
            printf("senior, ");
            break;
        }
        printf("and his final salary per mounth is %d\n", temp->MoneyPerHour * temp->Salary * temp->HoursPerMounth);
        return;
    }
    printf("No user with this Melli_code exists!");
    return;
}
void change_salary(user *head, user *tale, char melli_code[10])
{
    user *temp;
    int Salary;
    temp = head;
    if (temp == NULL)
    {
        printf("No employee!\n");
        return;
    }

    while (temp != tale)
    {
        if (melli_code == temp->Melli_Code)
        {
            printf("enter the Salary you want : \n");
            scanf("%d", Salary);
            temp->Salary = Salary;
            system("cls");
            return;
        }
        temp = temp->next;
    }
    if (melli_code == temp->Melli_Code)
    {
        printf("enter the level you want :\n1. junior\n2. midlevel\n3. senior\n");
        scanf("%d", Salary);
        temp->Salary = Salary;
        system("cls");
        return;
    }
    system("cls");
    printf("No user with this Melli_code exists!\n");
    return;
}
void change_level(user *head, user *tale, char melli_code[10])
{
    user *temp;
    int sath;
    temp = head;
    if (temp == NULL)
    {
        printf("No employee!\n");
        return;
    }

    while (temp != tale)
    {
        if (melli_code == temp->Melli_Code)
        {
            printf("enter the level you want :\n1. junior\n2. midlevel\n3. senior\n");
            scanf("%d", sath);
            temp->Sath = sath;
            system("cls");
            return;
        }
        temp = temp->next;
    }
    if (melli_code == temp->Melli_Code)
    {
        printf("enter the level you want :\n1. junior\n2. midlevel\n3. senior\n");
        scanf("%d", sath);
        temp->Sath = sath;
        system("cls");
        return;
    }
    system("cls");
    printf("No user with this Melli_code exists!\n");
    return;
}
void show_all(user *head, user *tale)
{
    user *temp;
    temp = head;
    if (temp == NULL)
    {
        system("cls");
        printf("No employee!\n");
        return;
    }

    int counter = 1;

    while (temp != tale)
    {
        printf("%d.\t", counter++);
        printf("the employee named %s %s, is on level ", temp->Name, temp->Last_Name);
        switch (temp->Sath)
        {
        case 0:
            printf("junior, ");
            break;

        case 1:
            printf("midlevel, ");
            break;

        case 2:
            printf("senior, ");
            break;
        }
        printf("and his final salary per mounth is %d\n", temp->MoneyPerHour * temp->Salary * temp->HoursPerMounth);

        temp = temp->next;
    }

    printf("%d.\t", counter++);
    printf("the employee named %s %s, is on level ", temp->Name, temp->Last_Name);
    switch (temp->Sath)
    {
    case 0:
        printf("junior, ");
        break;
    case 1:
        printf("midlevel, ");
        break;
    case 2:
        printf("senior, ");
        break;
    }
    printf("and his final salary per mounth is %d\n", temp->MoneyPerHour * temp->Salary * temp->HoursPerMounth);

    Sleep(1000 * counter);
    system("cls");
    return;
}