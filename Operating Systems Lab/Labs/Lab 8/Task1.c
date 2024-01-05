#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <pthread.h>

int N = 5;

void* worker()
{
    printf("Thread_ID %ld \n",pthread_self());
    printf("Process ID %d \n",getpid());
    pthread_exit(0);
  
}

int main(){
    
    pthread_t t[N];
    int i;
    for(i = 0; i < N; i++)
	{
        pthread_create(&t[i],NULL,worker,NULL);
    }
    for(i = 0; i < N; i++)
	{
        pthread_join(t[i],NULL);
    }
	return 0;
}