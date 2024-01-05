#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <sys/wait.h>
#include <ctype.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc , char* argv[])
{
    char* str =  {argv[1]};
    char* str2 = {argv[2]};
    int pipefd[2] ;
    int p = pipe(pipefd);
    int pid = fork();
    if(pid < 0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid > 0)
    {
        close(pipefd[0]);
        int fileDesc = open(str2, O_RDONLY);
        char buff[1024];
        read(fileDesc, buff, 1024);
        write(pipefd[1], buff , strlen(buff));
        close(pipefd[1]);
        close(fileDesc);
    }
    else
    {
        close(pipefd[1]);
        char buff[1024];
        int fDesc = open(str, O_WRONLY);
        read(pipefd[0], buff, 1024);
        write(fDesc, buff, strlen(buff));
        close(pipefd[0]);
        close(fDesc);
    }
    return 0;
}