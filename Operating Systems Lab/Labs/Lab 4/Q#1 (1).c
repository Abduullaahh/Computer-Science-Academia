#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	printf("getpid() of main.c : %d",getpid());
	printf("\n");
	pid_t ret, PID;
	ret = fork();
	if(ret < 0)
	{
		printf("Fork() Failed");
	}
	else if(ret == 0)
	{
		printf("We are in child\n");
		printf("Calling my_info from child process\n");
		char *args[] = {"my_info", NULL };
		execv("info.out", args);
	}
	else if(ret > 0)
	{
		printf("We are in Parent\n");
	}
	return 0;
}
