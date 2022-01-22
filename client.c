#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char **argv)
{
    int pid;
    int temp;
    int ptr;
    char c;

    if (argc != 3)
        return 0;

    pid = atoi(argv[1]);
    temp = 0;
    ptr = 0;
    while (argv[2][ptr])
    {
        c = argv[2][ptr];
        while (temp < 8)
        {
            if (c < 0)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            temp++;
            c = c << 1;
        }
        ptr++;
    }
}