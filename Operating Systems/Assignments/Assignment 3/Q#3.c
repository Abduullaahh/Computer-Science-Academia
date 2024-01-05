#include <iostream>
#include <semaphore.h>
#include <stdlib.h>
#include <pthread.h>

int *Fibonacci_Series;
int Length; 

void *generate_fibonacci(void *arg)
{
    int i;
    for (i = 2; i < Length; i++)
	{
        Fibonacci_Series[i] = Fibonacci_Series[i - 1] + Fibonacci_Series[i - 2];
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
	{
        printf("Usage: %s <number_of_fibonacci_numbers>\n", argv[0]);
        return 1;
    }
    Length = atoi(argv[1]);
    if (Length <= 0)
	{
        printf("Please enter a positive integer greater than 0.\n");
        return 1;
    }
    Fibonacci_Series = (int *)malloc(Length * sizeof(int));
    if (Fibonacci_Series == NULL)
	{
        printf("Failed to allocate memory.\n");
        return 1;
    }
    Fibonacci_Series[0] = 0;
    Fibonacci_Series[1] = 1;
    pthread_t thread;
    pthread_create(&thread, NULL, generate_fibonacci, NULL);
    pthread_join(thread, NULL);
    printf("Fibonacci sequence:\n");
    int i;
    for (i = 0; i < Length; i++)
	{
        printf("%d ", Fibonacci_Series[i]);
    }
    printf("\n");
    free(Fibonacci_Series);
    return 0;
}