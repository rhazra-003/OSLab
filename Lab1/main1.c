#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int n, i;
	pid_t *chid;

	printf("Enter n:\t");
	scanf("%d", &n);
	chid = (pid_t *)malloc(n * sizeof(pid_t));

	FILE *fp;
	fp = fopen("log.txt", "w");
	fprintf(fp, "Calling Process ID is %d\nCurrent Process Parent ID is %d\n\n", getpid(), getppid());
	fclose(fp);

	printf("Process ID is %d\n", getpid());
	printf("Process' Parent ID is %d\n\n", getppid());
	for (i = 0; i < n; i++)
	{
		chid[i] = fork();
		if (chid[i] == 0)
		{
			fp = fopen("log.txt", "a");
			fprintf(fp, "Current Process ID is %d\nCurrent Process Parent ID is %d\n\n", getpid(), getppid());
			fclose(fp);
			printf("Current Process ID is %d\nCurrent Process Parent ID is %d\n\n", getpid(), getppid());
			exit(0);
		}
	}
	return 0;
}
