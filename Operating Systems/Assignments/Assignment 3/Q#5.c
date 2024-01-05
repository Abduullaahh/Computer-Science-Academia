#include <iostream>
#include <semaphore.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t Mutex;
sem_t Sem_Batsman;
sem_t Sem_Bowler;

void* Bowler(void* arg)
{
    sem_post(&Sem_Bowler);
    sem_wait(&Sem_Batsman);
    pthread_mutex_lock(&Mutex);
    printf("Bowler and batsman both playing\n");
    pthread_mutex_unlock(&Mutex);
    sem_post(&Sem_Bowler);
    sem_post(&Sem_Batsman);
    pthread_exit(NULL);
}

void* Batsman(void* arg)
{
    sem_post(&Sem_Batsman);
    sem_wait(&Sem_Bowler);
    pthread_mutex_lock(&Mutex);
    printf("Batsman and bowler both playing\n");
    pthread_mutex_unlock(&Mutex);
    sem_post(&Sem_Batsman);
    sem_post(&Sem_Bowler);
    pthread_exit(NULL);
}

int main()
{
    sem_init(&Sem_Bowler, 0, 0);
    sem_init(&Sem_Batsman, 0, 0);
    pthread_mutex_init(&Mutex, NULL);
    pthread_t BowlerID, BatsmanID;
    pthread_create(&BowlerID, NULL, Bowler, NULL);
    pthread_create(&BatsmanID, NULL, Batsman, NULL);
    pthread_join(BowlerID, NULL);
    pthread_join(BatsmanID, NULL);
    sem_destroy(&Sem_Bowler);
    sem_destroy(&Sem_Batsman);
    pthread_mutex_destroy(&Mutex);
    return 0;
}