#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

char *generate_password(int length);
bool has_alpha(char *pw);
bool has_numeric(char *pw);
// bool has_special(char *pw);

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("Usage: cpassword [length]\n");
        return 1;
    }

    int len = atoi(argv[1]);
    len = len >= 8 ? len : 2;

    srand(time(NULL));

    char *password = generate_password(len);
    
    printf("%s\n", password);

    free(password);
    return 0;
}

char *generate_password(int length)
{
    char *pass = malloc(sizeof(char) * (length + 1));

    for (int i = 0; i < length; i++)
    {
        pass[i] = (rand() % 94) + 33;
    }
    pass[length] = '\0';

    return has_alpha(pass) && has_numeric(pass) 
        ? pass 
        : generate_password(length);
}

bool has_alpha(char *pw)
{
    for (int i = 0; pw[i] != '\0'; i++)
    {
        if (isalpha(pw[i]))
            return true;
    }

    return false;
}

bool has_numeric(char *pw)
{
    for (int i = 0; pw[i] != '\0'; i++)
    {
        if (isdigit(pw[i]))
            return true;
    }

    return false;
}