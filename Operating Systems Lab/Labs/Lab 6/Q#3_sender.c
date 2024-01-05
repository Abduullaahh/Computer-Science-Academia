#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc , char* argv[])
{
    int fd = open("pipe", O_RDWR);
    int myId = getpid();
    int n1 = 4, n2 = 5;
    char operator = '+';
    printf("ID P%d: ", myId);
    write(fd, &n1 , sizeof(int));
    write(fd, &n2 , sizeof(int));
    write(fd, &operator , sizeof(char));
    sleep(4);
    int res = 0 ;
    read(fd , &res, sizeof(int));
    printf("The Result is: %d", res);
    close(fd);
    return 0;
}