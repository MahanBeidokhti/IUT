// FirstName_LastName_StudentNumber: Denni_MacAlistair_Ritchie_40100003

#include <stdio.h>
#include <malloc.h>
#include "linkedlist.h"
#include "employee.h"

user *head, *tale;

int main()
{
    int func;
    char melli[10];
    while (1)
    {
        printf("Choose the number of thing you want to do =P \n0. Exit\n1. push an employee to the first of list\n2. push an employee to the end of list\n3. remove first employee\n4. remove last employee\n5. remove one of the employees\n6. show one of the employees\n7. change an employees Salary\n 8. cahnge an employees level\n9. show all the employees");
        scanf("%d", &func);
        system("cls");
        switch (func)
        {
        case 0:
            exit;

        case 1:
            push_front();
            break;

        case 2:
            push_back();
            break;

        case 3:
            remove_front();
            break;

        case 4:
            remove_back();
            break;

        case 5:
            printf("enter the melli code : ");
            scanf("%s", melli);
            remove_middle();
            break;

        case 6:
            printf("enter the melli code : ");
            scanf("%s", melli);
            show_one(head, tale, melli);
            break;

        case 7:
            printf("enter the melli code : ");
            scanf("%s", melli);
            change_salary(head, tale, melli);
            break;

        case 8:
            printf("enter the melli code : ");
            scanf("%s", melli);
            change_level(head, tale, melli);
            break;

        case 9:
            show_all(head, tale);
            break;
        }
    }
}