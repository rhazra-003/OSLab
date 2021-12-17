#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int main()
{
    int numProc, numElems, searchElem, i, chldStatus, range, start, end, j, flag = 0, chldPid;
    int *arr;

    printf("Enter the number of elements: ");
    scanf("%d", &numElems);

    arr = malloc(numElems * sizeof(int));
    srand(time(0));

    for (i = 0; i < numElems; i++)
    {
        arr[i] = rand() % 1000;
        printf("%d\t", arr[i]);
    }

    printf("\nEnter the search query: ");
    scanf("%d", &searchElem);

    printf("Enter the number of processes: ");
    scanf("%d", &numProc);

    range = numElems / numProc;

    for (i = 0; i < numProc; i++)
    {
        chldPid = fork();

        if (chldPid < 0)
        {
            fprintf(stderr, "Failed to fork child proc %d\n", i + 1);
            exit(0);
        }

        if (chldPid == 0)
        {
            start = i * range;
            end = i == numProc - 1 ? numElems : (i + 1) * range;

            printf("Child %d PID: %d ... Searching in Range: %d --- %d\n", i + 1, getpid(), start, end);

            for (j = start; j < end; j++)
            {
                if (arr[j] == searchElem)
                {
                    printf("Found at index %d\n", j);
                    exit(1);
                }
            }
            exit(0);
        }
    }

    while (waitpid(-1, &chldStatus, 0) > 0)

    if (chldStatus / 256 == 1)
        flag = 1;
    if (!flag)
        printf("Search query not found\n");
    else
        exit(0);
    exit(1);
}
