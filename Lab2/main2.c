#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    FILE *fp;
    fp = fopen("prime_nos.txt", "w");

    int i, x, y, start, stop, numProc, range, childStatus;
    pid_t child;

    printf("Enter the range (x-y): ");
    scanf("%d-%d", &x, &y);

    fprintf(fp, "Searching Primes in range %d --- %d\n", x, y);
    fclose(fp);

    printf("Enter number of child processes: ");
    scanf("%d", &numProc);

    range = (y - x) / numProc;

    if (y <= x)
    {
        printf("Invalid range\n");
        exit(0);
    }

    for (i = 0; i < numProc; i++)
    {
        if ((child = fork()) == 0)
        {
            start = i * range + x;
            stop = (i == numProc - 1 ? y : start + range) + 1;

            printf("Child %d PID: %d ... Searching in Range: %d --- %d\n", i + 1, getpid(), start, stop);
            fp = fopen("prime_nos.txt", "a");

            for (int i = start; i < stop; i++)
            {
                int flag = 0;

                for (int j = 2; j <= i / 2; j++)
                {
                    if (i % j == 0)
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    fprintf(fp, "%d\n", i);
                }
            }
            fclose(fp);
            exit(0);
        }
    }
    while (wait(&childStatus) > 0)
        ;
    return 0;
}
