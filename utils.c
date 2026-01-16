#include "cell.h"

void Getcwd(char *buf, size_t size)
{
    if (NULL == getcwd(buf, size))
        perror(RED "getcwd FAILED" RST);
}