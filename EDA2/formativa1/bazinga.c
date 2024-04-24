#include <stdio.h>
#include <string.h>

int main()
{
    char sheldon[50], raj[50];

    scanf("%s%s", sheldon, raj);

    if (strcmp(raj, sheldon) == 0)
    {
        printf("De novo!\n");
        return 0;
    }

    if ((strcmp(sheldon, "pedra") == 0 && (strcmp(raj, "lagarto") == 0 || strcmp(raj, "tesoura") == 0)) ||
        (strcmp(sheldon, "papel") == 0 && (strcmp(raj, "pedra") == 0 || strcmp(raj, "Spock") == 0)) ||
        (strcmp(sheldon, "tesoura") == 0 && (strcmp(raj, "papel") == 0 || strcmp(raj, "lagarto") == 0)) ||
        (strcmp(sheldon, "lagarto") == 0 && (strcmp(raj, "Spock") == 0 || strcmp(raj, "papel") == 0)) ||
        (strcmp(sheldon, "Spock") == 0 && (strcmp(raj, "tesoura") == 0 || strcmp(raj, "pedra") == 0)))
    {
        printf("Bazinga!\n");
        return 0;
    }
    else
        printf("Raj trapaceou!\n");

    return 0;
}