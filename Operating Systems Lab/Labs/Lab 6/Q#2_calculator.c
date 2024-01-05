#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/time.h>
#include<sys/wait.h>
#include<ctype.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>

int main(int argc, char*argv[])
{
	char* p = argv[1];
	int fd = open(p, O_RDWR);
	int arr[5];
	read(fd, arr, sizeof(arr));
	int i;
	int sum =0;
	for(i=0; i<(sizeof(arr)/sizeof(int)); i++)
	{
		sum=sum+arr[i];
	}
	write(fd, &sum, 4);
	return 0;
}
