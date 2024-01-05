#include <iostream>
#include <semaphore.h>
#include <stdlib.h>
#include <pthread.h>

class Stack
{
private:
    int* a;               // array for stack
    int max;              // max size of array
    int top;              // stack top
    sem_t empty;          // semaphore for empty spaces
    sem_t full;           // semaphore for items in stack
    pthread_mutex_t lock; // mutex lock for mutual exclusion

public:
    Stack(int m)
	{
        a = new int[m];
        max = m;
        top = 0;
        sem_init(&empty, 0, max);      // initialize empty semaphore to max
        sem_init(&full, 0, 0);         // initialize full semaphore to 0
        pthread_mutex_init(&lock, NULL); // initialize mutex lock
    }

    void push(int x)
	{
        sem_wait(&empty);                 // decrement empty semaphore
        pthread_mutex_lock(&lock);        // acquire lock
        a[top] = x;
        ++top;
        pthread_mutex_unlock(&lock);      // release lock
        sem_post(&full);                  // increment full semaphore
    }

    int pop()
	{
        sem_wait(&full);                  // decrement full semaphore
        pthread_mutex_lock(&lock);        // acquire lock
        --top;
        int tmp = a[top];
        pthread_mutex_unlock(&lock);      // release lock
        sem_post(&empty);                 // increment empty semaphore
        return tmp;
    }
};