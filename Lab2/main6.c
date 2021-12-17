#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

static int sigusr2Count = 0;
pid_t child;

void sigusr1(int signal)
{
    printf("Parent: World\n");
    return;
}

void sigusr2(int signal)
{
    sigusr2Count++;
    printf("Parent: Hello\n");

    if (sigusr2Count >= 5)
    {
        kill(child, SIGSTOP);
        kill(getpid(), SIGSTOP);
    }
    return;
}

int main()
{
    int n, x;
    pid_t ppid;
    srand(time(0));

    signal(SIGUSR1, sigusr1);
    signal(SIGUSR2, sigusr2);
    child = fork();

    if (child == 0)
    {
        while(1)
        {
            sleep(5);
            x = rand() % 2;
            ppid = getppid();

            if(x)
            {
                printf("Child: World\n");
                kill(ppid, SIGUSR2);
            }
            else
            {
                printf("Child: Hello\n");
                kill(ppid, SIGUSR1);
            }
        }
        exit(0);
    }

    waitpid(child, NULL, 0);
    return 0;
}
