#include "cell.h"

int cell_exit(char **args);

t_builtin g_builtin[] = {
    // {.builtin_name = "echo", .foo = cell_echo},
    // {.builtin_name = "env", .foo = cell_env},
    {.builtin_name = "exit", .foo = cell_exit},
    {.builtin_name = NULL}};

int status = 0;

void cell_launch(char **args)
{
    if (Fork() == CELL_JR)
        Execvp(args[0], args);
    else
        Wait(&status);
}

void cell_exec(char **args)
{
    int i = 0;
    const char *curr;

    while ((curr = g_builtin[i].builtin_name))
    {
        if (!strcmp(curr, args[0]))
        {
            status = g_builtin[i].foo(args);
            return;
        }
        ++i;
    }

    cell_launch(args);
}

char **cell_split_line(char *line)
{
    char **tokens;
    unsigned int position = 0;
    size_t bufsize;

    bufsize = BUFSIZ;
    tokens = Malloc(BUFSIZ * sizeof *tokens);
    for (char *token = strtok(line, DEL); token; token = strtok(NULL, DEL))
    {
        tokens[position++] = token;
        if (position >= bufsize)
        {
            bufsize *= 2;
            tokens = Realloc(tokens, bufsize * sizeof(*tokens));
        }
    }
    tokens[position] = NULL;
    return tokens;
}

char *cell_read_line(void)
{
    char *buf;
    size_t bufsize = 0;
    char cwd[BUFSIZ];

    buf = NULL;

    Getcwd(cwd, sizeof(cwd));

    p(C "%s" RST "$>", cwd);

    if (getline(&buf, &bufsize, stdin) == -1)
    {
        free(buf);
        buf = NULL;

        if (feof(stdin))
            printf(RED "[EOF]" RST);
        else
            printf(RED "Getline failed" RST);
    }

    return buf;
}

int main(int ac, char **av)
{
    char *line;
    char **args;
    printbanner();
    // REPL
    // READ->EVALUATE->PRINT->LOOP
    while ((line = cell_read_line()))
    {

        // 2 get tokens gettok
        args = cell_split_line(line);

        cell_exec(args);
        // free
        free(line);
        free(args);
    }

    return EXIT_SUCCESS;
}
