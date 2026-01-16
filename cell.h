#ifndef CELL_H
#define CELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define RED "\033[1;31m"
#define G "\033[1;32m"
#define Y "\033[1;33m"
#define C "\033[1;34m"
#define RST "\033[0m"

#define p(...) printf(_VA_ARGS_)

#endif