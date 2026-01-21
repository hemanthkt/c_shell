#ifndef CELL_H
#define CELL_H
#define EX_OSERR 71
#define EX_UNAVAILABLE 69

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <sysexits.h>

#define RED "\033[1;31m"
#define G "\033[1;32m"
#define Y "\033[1;33m"
#define C "\033[1;34m"
#define RST "\033[0m"

#define p(...) printf(__VA_ARGS__)
#define DEL "\t\n\v\f\r "
#define CELL_JR 0

typedef struct s_builtin
{
    const char *builtin_name;
    int (*foo)(char **);
} t_builtin;

void dbzSpinnerLoading(); /* Animated loading spinner */
int cell_exit(char **args);
void Getcwd(char *, size_t);
void printbanner(void);
void *Malloc(size_t);
void *Realloc(void *, size_t);
void Execvp(const char *, char *const[]);
pid_t Fork();
pid_t Wait(int *status);
#endif