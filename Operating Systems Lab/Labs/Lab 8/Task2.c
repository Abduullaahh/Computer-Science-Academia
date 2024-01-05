#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <pthread.h>

void *Summation(void *num) 
{
    int Sum = 0;
    int n = (int)num;
    int i = 1;
    while (i <= n) 
	{
        Sum = Sum + i;
        i++;
    }
    printf("n in thread is: %d\n", Sum);
    pthread_exit((void *)Sum);
}

int main() 
{
    pthread_t id1;
    int num = 5;
    printf("n in main: %d\n", num);
    pthread_create(&id1, NULL, Summation, (void *)num);
    void *Sum;
    pthread_join(id1, &Sum);
    printf("In main, Sum of n is: %d\n", (int)Sum);
    return 0;
}