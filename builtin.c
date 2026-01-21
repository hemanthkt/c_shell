#include "cell.h"

int cell_exit(char **args)
{
    (void)args;
    printf("Shell Exited succesfully. Thank you for using HKT shell :)\n");

    fflush(stdout);
    exit(EXIT_SUCCESS);
}

int cell_env(char **args)
{
    extern char **environ;

    (void)args;
    if (!environ)
        return (1);

    for (int i = 0; environ[i]; i++)
    {
        printf("%s\n", environ[i]);
    }
    return (0);
}