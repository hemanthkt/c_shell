#include "cell.h"

char *cell_read_line(void)
{
    char *buf;
    size_t bufsize = 0;
    char cwd[BUFSIZ];

    buf = NULL;

    printf("$>");

    if (getline(&buf, &bufsize, stdin) == -1)
    {

        buf = NULL;

        if (feof(stdin))
            printf(RED "[EOF]" RST);
        else
            printf(RED "Getline failed" RST);

        free(buf);
        return NULL;
    }

    return buf;
}

int main(int ac, char **av)
{
    char *line;
    // REPL
    // READ->EVALUATE->PRINT->LOOP
    while (1)
    {
        // 1 get line
        line = cell_read_line();
        printf("%s\n", line);

        // 2 get tokens gettok

        // 3 exec
    }

    return EXIT_SUCCESS;
}