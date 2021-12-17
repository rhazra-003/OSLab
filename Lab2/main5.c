#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int main()
{
    srand(time(0));
    int x, stat;
    pid_t pid = fork();

    if (pid == 0)
    {
        sleep(5);
        x = rand() % 2;

        if (x)
            printf("Child: World\n");
        else
            printf("Child: Hello\n");
        exit(x);
    }

    waitpid(pid, &stat, 0);

    if (stat)
        printf("Parent: Hello\n");
    else
        printf("Parent: World\n");

    return 0;
}
