#include<stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


int main()
{
	FILE  *f1;

    int i,x=2000;

    srand(clock());
    printf("......%ld",clock());

	for(i=0;i<10;i++)
		{
			// reads current balance from text file
			f1=fopen("acc_balance.txt","r");
			fscanf(f1,"bal:%d",&x);
			fclose(f1);

    		x++;

            sleep(random()%50);
    		// writes updated balance to text file
			f1=fopen("acc_balance.txt","w+");
			fprintf(f1,"bal:%d",x);
			fclose(f1);
		}
return 0;
}
