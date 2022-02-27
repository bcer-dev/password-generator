#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *generate_password(int length);

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("Usage: cpassword [length]\n");
        return 1;
    }

    int len = atoi(argv[1]);
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
    return pass;
}