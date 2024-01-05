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
    char data[50];
    char* ptr;
    int id;
    int detach_status;
    id = shmget(KEY, SIZE, 0);

    if (id < 0)
    {
        printf("shmget failed\n");
        return 3;
    }
    else
    {
        printf("ID = %d\n", id);
    }

    ptr = shmat(id, NULL, 0);

    if (ptr == NULL)
    {
        printf("shmat failed\n");
        return 3;
    }

    strncpy(data, ptr, SIZE);
    printf("%s\n", data);

    detach_status = shmdt(ptr);
    if (detach_status < 0)
    {

        printf("shmdt failed\n");
        return 3;
    }
    return 0;
}
