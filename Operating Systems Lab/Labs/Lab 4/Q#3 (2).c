#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	pid_t ret = fork();
	if(ret < 0)
	{
		printf("Fork() Failed");
	}
	else if(ret == 0)
	{
		printf("We are in child\n");
		printf("Calling Fibonacci from child process\n");
		char *args[] = {"Fibonacci", NULL };
		execv("Fibonacci.out", args);
	}
	else if(ret > 0)
	{
		printf("We are in Parent\n");
	}
	return 0;
}
