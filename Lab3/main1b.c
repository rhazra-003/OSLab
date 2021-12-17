#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#define __USE_GNU 1
#include <sched.h>

int func(void *arg)
{
    printf("Hello");
    exit(0);
}

int main()
{
    int i = 0;
    struct timeval start, end;
    gettimeofday(&start, NULL);

    while (i < 20000)
    {
        clone(&func, NULL, CLONE_VM, NULL);
        i++;
    }

    gettimeofday(&end, NULL);
    double diff = (double)(end.tv_usec - start.tv_usec) / 1000000 + (double)(end.tv_sec - start.tv_sec);

    printf("Time to spawn 20000 threads: %.4f s\n", diff);

    return 0;
}