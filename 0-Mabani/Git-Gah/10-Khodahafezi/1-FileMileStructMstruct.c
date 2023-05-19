#include <stdio.h>

typedef struct input
{
    int id;
    char name[20];
} inp;

int main()
{
    int n;
    FILE *binfile;
    inp temp;
    binfile = fopen("data.bin", "rb");

    scanf("%d", &n);

    fseek(binfile, sizeof(inp)* (n-1), 1);

    fread(&temp, sizeof(inp), 1, binfile);

    printf("%d:%s", temp.id, temp.name);
}