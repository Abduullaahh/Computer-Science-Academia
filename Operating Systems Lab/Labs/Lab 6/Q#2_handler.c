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
  int arr[5] = {1,2,3,4,5};
  write(fd, arr, sizeof(arr));
  sleep(5);
  int sum;
  read(fd, &sum, 4);
  printf("SUM OF ARRAY: %d\n", sum);
  return 0;
}
