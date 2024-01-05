#include <iostream>
#include <semaphore.h>
#include <stdlib.h>
#include <pthread.h>

void *print_primes(void *arg)
{
    int n = *(int *)arg;
    int i, j;
    for (i = 2; i <= n; i++)
	{
        int Prime = 1;
        for (j = 2; j <= i / 2; j++)
		{
            if (i % j == 0)
			{
                Prime = 0;
                break;
            }
        }
        if (Prime)
		{
            printf("%d ", i);
        }
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
	{
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
    if (n <= 1)
	{
        printf("Please enter a positive number greater than 1.\n");
        return 1;
    }
    pthread_t thread;
    pthread_create(&thread, NULL, print_primes, (void *)&n);
    pthread_join(thread, NULL);
    printf("\n");
    return 0;
}
