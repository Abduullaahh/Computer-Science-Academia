#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/time.h>
#include<sys/wait.h>
#include<ctype.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>

#define PIPE_PERM (S_IRUSR | S_IWUSR)

int main(int argc, char*argv[])
{
  char* p = argv[1];
  int fd = open(p, O_RDWR);
  //printf("idk\n");
  write(fd, "Hello There", 11);
  sleep(3);
  char buff[11];
  read(fd, &buff, 11);
  printf("Reversed array: %s\n", buff);
  return 0;
}
