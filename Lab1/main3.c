#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int isPrime(int x)
{
    for(int i=2; i*i <=x; i++){
        if(x%i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int n, m;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter number of process: ");
    scanf("%d", &m);

    for(int i=0; i<m; i++){
        int l = 1;
        pid_t child = fork();;
        if(child == 0){
            for(int j = 1 + i; j<=n; j += m){
                if(isPrime(j) && j!=1)
                printf("pid: %d prime number: %d \n", getpid(), j);
            }
            break;
        }
    }
    sleep(2);
}
