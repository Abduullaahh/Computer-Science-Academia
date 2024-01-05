#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

#define KEY 99999
#define SIZE 50

int main(int argc, char* argv[])
{
    char* filename = argv[1];

    int fd = open("num.txt", O_RDWR);
    char data[50];
    int i = 0;
    int count;

    count = read(fd, data, 50);
    data[count] = '\0';

    for (i = 0; i < count; i++)
    {
        printf("%c ", data[i]);
    }

    close(fd);

    int id = 0;

    id = shmget(KEY, SIZE, IPC_CREAT);

    if (id < 0)
    {
        printf("shmget failed\n");
        return 3;
    }
    else
    {
        printf("ID = %d\n", id);
    }

    char* ptr = shmat(id, NULL, 0);

    if (ptr == NULL)
    {
        printf("shmat failed\n");
        return 3;
    }

    strncpy(ptr, data, SIZE);
    sleep(10);

    int detach_status = shmdt(ptr);
    if (detach_status < 0)
    {

        printf("shmdt failed\n");
        return 3;
    }
    shmctl(id, IPC_RMID, NULL);

    return 0;
}

