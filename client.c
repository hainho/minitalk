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
    ptr = 0;
    while (argv[2][ptr])
    {
        temp = 0;
        c = argv[2][ptr++];
        while (temp < 8)
        {
            if (c < 0)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            temp++;
            c = c << 1;
            usleep(100);
        }
        usleep(100);
    }
}