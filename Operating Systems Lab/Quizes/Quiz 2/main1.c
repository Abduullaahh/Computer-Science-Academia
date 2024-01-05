#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semA, semB, semC;

void* printA(void* arg) {
    while (1) {
        sem_wait(&semA);
        printf("a");
        sem_wait(&semA);
        printf("a");
        sem_wait(&semA);
        printf("a");
        //sem_post(&semB);
        sem_post(&semC);
    }
    return NULL;
}

void* printB(void* arg) {
    while (1) {
        sem_wait(&semB);
        printf("b");
        printf(" ");
        sem_post(&semA);
        sem_post(&semA);
        sem_post(&semA);
       
    }
    return NULL;
}

void* printC(void* arg) {
    while (1) {
        sem_wait(&semC);
        printf("c");
        sem_post(&semB);
        
    }
    return NULL;
}

int main() {
    sem_init(&semA, 0, 3);
    sem_init(&semB, 0, 0);
    sem_init(&semC, 0, 0);

    pthread_t threadA, threadB, threadC;

    pthread_create(&threadA, NULL, printA, NULL);
    pthread_create(&threadB, NULL, printB, NULL);
    pthread_create(&threadC, NULL, printC, NULL);

    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);
    pthread_join(threadC, NULL);

    return 0;
}

