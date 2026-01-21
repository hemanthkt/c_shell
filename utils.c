#include "cell.h"

void Getcwd(char *buf, size_t size)
{
    if (NULL == getcwd(buf, size))
        perror(RED "getcwd FAILED" RST);
}

void printbanner(void)
{
    printf(
        G
        "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
        "@,--.     ,--.     ,--.            ,--.            ,--.,--.@\n"
        "@|  ,---. |  |,-.,-'  '-.    ,---. |  ,---.  ,---. |  ||  |@\n"
        "@|  .-.  ||     /'-.  .-'   (  .-' |  .-.  || .-. :|  ||  |@\n"
        "@|  | |  ||  \\  \\  |  |     .-'  `)|  | |  |\\   --.|  ||  |@\n"
        "@`--' `--'`--'`--' `--'     `----' `--' `--' `----'`--'`--'@\n"
        "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n" RST);
}

void *Malloc(size_t size)
{
    void *ptr;
    if (size == 0)
        return (NULL);
    ptr = malloc(size);
    if (!ptr)
    {
        perror(RED "Malloc failed" RST);
        exit(EXIT_FAILURE);
    }
    return (ptr);
}

void *Realloc(void *ptr, size_t size)
{
    void *new_ptr;

    new_ptr = realloc(ptr, size);
    if (!new_ptr && size != 0)
    {
        perror(RED "Realloc failed" RST);
        exit(EXIT_FAILURE);
    }
    return (new_ptr);
}

pid_t Fork(void)
{
    pid_t pitd;
    pitd = fork();

    if (pitd < 0)
    {
        perror(RED "Fork failed" RST);
        exit(EX_OSERR);
    }
    return (pitd);
}

pid_t Wait(int *status)
{
    pid_t result;

    if (!status)
    {
        fprintf(stderr, RED "Wait: status argument required\n" RST);
        return (-1);
    }
    result = wait(status);
    if (result == -1)
        perror(RED "Wait failed" RST);
    if (WIFEXITED(*status))
        *status = WEXITSTATUS(*status);
    return (result);
}

void Execvp(const char *file, char *const argv[])
{
    if (!file || !argv)
    {
        fprintf(stderr, RED "Excevp: Invalid arguments" RST);
        exit(EXIT_FAILURE);
    }
    if (execvp(file, argv) == -1)
    {
        perror(RED "Cell_Jr failed" RST);
        exit(EX_UNAVAILABLE);
    }
}

void dbzSpinnerLoading()
{
    const char *charging[] = {
        "[            ]",
        "[=           ]",
        "[==          ]",
        "[===         ]",
        "[====        ]",
        "[=====       ]",
        "[======      ]",
        "[=======     ]",
        "[========    ]",
        "[=========   ]",
        "[==========  ]",
        "[=========== ]",
        "[===========💥]",
    };
    const int frames = sizeof(charging) / sizeof(charging[0]);

    p(RED "Shutting down...\n" RST);

    // Loop through the "charging" animation for 3 seconds
    for (int i = 0; i < frames; i++)
    {
        p("\r" Y "%s" RST, charging[i]);
        fflush(stdout); // Force update the console
        usleep(421337);
    }
    p(C "\n✅ EXIT ✅\n" RST);
    exit(EXIT_SUCCESS);
}
