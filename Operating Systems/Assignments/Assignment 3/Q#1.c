#include <iostream>
#include <semaphore.h>
#include <stdlib.h>
#include <pthread.h>

int numbers[] = {90, 81, 78, 95, 79, 72, 85};
int size = sizeof(numbers) / sizeof(numbers[0]);
double Avg;
int Min;
int Max;

void *Avg(void *arg)
{
    double sum = 0;
    int i;
    for (i = 0; i < size; i++)
	{
        sum += numbers[i];
    }
    Avg = sum / size;
    pthread_exit(NULL);
}

void *Min(void *arg)
{
    Min = numbers[0];
    int i;
    for (i = 1; i < size; i++)
	{
        if (numbers[i] < Min)
		{
            Min = numbers[i];
        }
    }
    pthread_exit(NULL);
}

void *Max(void *arg)
{
    Max = numbers[0];
    int i;
    for (i = 1; i < size; i++)
	{
        if (numbers[i] > Max)
		{
            Max = numbers[i];
        }
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t threads[3];
    pthread_create(&threads[0], NULL, Avg, NULL);
    pthread_create(&threads[1], NULL, Min, NULL);
    pthread_create(&threads[2], NULL, Max, NULL);
    int i;
    for (i = 0; i < 3; i++)
	{
        pthread_join(threads[i], NULL);
    }
    printf("Avg is %.2f\n", Avg);
    printf("Min is %d\n", Min);
    printf("Max is %d\n", Max);
    return 0;
}