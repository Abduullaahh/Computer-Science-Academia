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
	char buffer[11];
	read(fd, &buffer, 11);
	int i;
	for(i=0; i<11; i++)
	{
		if(buffer[i] >= 65 && buffer[i] <= 90)
		{
		buffer[i] = buffer[i] + 32;
		}
		else if(buffer[i] >= 97 && buffer[i] <= 122)
		{
		buffer[i] = buffer[i] - 32;
		}
	}
	write(fd, &buffer, 11);
	return 0;
}
