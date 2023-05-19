#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <malloc.h>
#include <ctype.h>

int main()
{
    char *name, *add, *name2, *add2;
    add = calloc(260, sizeof(char));
    scanf("%s", add);
    DIR *addres = opendir(add);
    struct dirent *thing;

    thing = readdir(addres);
    thing = readdir(addres);

    while (thing = readdir(addres))
    {
        name = calloc(260, sizeof(char));
        name2 = calloc(260, sizeof(char));
        add2 = calloc(260, sizeof(char));

        strcpy(name, thing->d_name);

        strcat(add2, add);
        strcat(add2, "\\");
        strcat(add2, thing->d_name);

        for (int i = 0; i < 256; i++)
            if (i == 0 || name[i - 1] == ' ')
                name[i] = toupper(name[i]);
            else
                name[i] = tolower(name[i]);

        strcat(name2, add);
        strcat(name2, "\\");
        strcat(name2, name);

        rename(add2, name2);
    }

    return 0;
}