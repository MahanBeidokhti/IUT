// FirstName_LastName_StudentNumber: Denni_MacAlistair_Ritchie_40100003

#include "employee.h"

void *New_Node();
void push_front(user **head, user **tale);
void push_back(user **head, user **tale);
void remove_front(user **head, user **tale);
void remove_back(user **head, user **tale);
void remove_middle(user **head, user **tale, char melli[10]);
void show_one(user *head, user *tale, char melli_code[10]);
void change_salary(user *head, user *tale, char melli_code[10]);
void change_level(user *head, user *tale, char melli_code[10]);
void show_all(user *head, user *tale);