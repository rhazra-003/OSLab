#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

static int n;

int spawn()
{
    n--;
    FILE* fp;
    pid_t wpid;
    int status = 0;

    if(n >= 0)
    {
        if(fork() == 0)
        {
            fp = fopen("log2.txt", "a");
            fprintf(fp, "Current Process ID is %d\nCurrent Process Parent ID is %d\n\n", getpid(), getppid());
            fclose(fp);
            printf("Current Process ID is %d\nCurrent Process Parent ID is %d\n\n", getpid(), getppid());

            spawn();
            while ((wpid = wait(&status)) > 0);
            exit(0);
        }
    }
}

int main()
{
    printf("Enter n:\t");
    scanf("%d", &n);
    pid_t wpid;
    int status = 0;

    if(n > 0)
    {
        FILE *fp;
        fp = fopen("log2.txt", "w");
        fprintf(fp, "Calling Process ID is %d\nCalling Process Parent ID is %d\n\n", getpid(), getppid());
        fclose(fp);
        printf("Calling Process ID is %d\nCalling Process Parent ID is %d\n\n", getpid(), getppid());

        spawn();
        while ((wpid = wait(&status)) > 0);
    }

    return 0;
}
