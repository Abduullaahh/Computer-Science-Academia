#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

int size;

void* Generator(void* num) 
{
    int number = *(int*) num;
    int i = 0;
    int j = 1;
    int Sum = 0;
    int* arr = (int*) malloc(sizeof(int) * size);
    arr[0] = 0;
    arr[1] = 1;
    int arrindex = 2;
    int count = 0;
    while (count < size) 
	{
        Sum = i + j;
        arr[arrindex] = Sum;
        i = j;
        j = Sum;
        arrindex++;
        count++;
    }
    for (i = 0; i < number; i++) 
	{
        printf("ARRAY IN THREAD %d \n", arr[i]);
    }
    pthread_exit(arr);
}

void* Even_Numbers(void* series) 
{
    printf("Count size : %d \n",size);
    int* arr1 = (int*) series;
    int i;
    for (i = 0; i < size; i++) 
	{
        printf("ARRAY IN EVEN THREAD %d \n", arr1[i]);
    }
    int counteven = 0;
    for (i = 1; i < size; i++) 
	{
        if (arr1[i] % 2 == 0) 
		{
            counteven++;
        }
    }
    printf("Count Even IS %d \n", counteven);
    pthread_exit((void*)counteven);
}

void* Odd_Numbers(void* series)
{
    int* arr2 = (int*) series;
    int i;
    for (i = 0; i < size; i++)
	{
        printf("ARRAY IN ODD THREAD %d \n", arr2[i]);
    }
    int countodd = 0;
    for (i = 1; i < size; i++) 
	{
        if (arr2[i] % 2 != 0) 
		{
            countodd++;
        }
    }
    printf("Count ODD IS %d \n", countodd);
    pthread_exit((void*)countodd);
}

void* Sum(void* series)
{
    int* arr = (int*) series;
    int i = 0;
    
    for (i = 0; i < size; i++) 
	{
        printf("ARRAY IN Sum THREAD %d \n", arr[i]);
    }
    i=0;
    int countSum = 0;
    for (; i < size; i++)
	{
        countSum = countSum + arr[i];
    }
    printf("Sum IS %d \n", countSum);
    int fd=open("Sum.txt",O_RDWR|O_CREAT,0777);
    char buffer[10
   
    snprintf(buffer, sizeof(buffer), "%d", countSum);
    write(fd,buffer,strlen(buffer));
    pthread_exit((void*)countSum);
}

int main(int argc, char* argv[]) 
{
    int num = atoi(argv[1]);
    size = num;
    pthread_t id1;
    void* returnseries;
    printf("NUMBER IN MAIN THROUGH COMMAND PROMPT IS : %d \n", num);
    pthread_create(&id1, NULL, Generator, (void*) &num);
    pthread_join(id1, &returnseries);
    int* arr = (int*) returnseries;
	
    int i;
    for (i = 0; i < size; i++) 
	{
        printf("IN MAIN ARRAY IS %d \n", arr[i]);
    }
    
    pthread_t e1,od,add;
    void*evencount=0;
    void*oddcount=0;
    void*Sumcount=0;
    pthread_create(&e1,NULL,Even_Numbers,arr);
    pthread_create(&od,NULL,Odd_Numbers,arr);
    pthread_create(&add,NULL,Sum,arr);
    pthread_join(e1,&evencount);
    pthread_join(od,&oddcount);
    pthread_join(add,&Sumcount);
    printf("HAVING THREAD ID : %ld ",e1);
    printf("IN MAIN : EVEN COUNT %d \n ",(int)evencount);
    printf("HAVING THREAD ID : %ld ",od);
    printf("IN MAIN : ODD  COUNT %d \n ",(int)oddcount);
    printf("HAVING THREAD ID : %ld ",add);
    printf("IN MAIN : Sum %d \n ",(int)Sumcount);
    return 0;
}