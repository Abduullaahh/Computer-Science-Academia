#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc, char* argv[])
{
	int n = atoi(argv[1]);
	if(n > 0 && n < 11)
	{
		pid_t ret = fork();
		if(ret < 0)
		{
			printf("Fork() Failed");
		}
		else if(ret == 0)
		{
			int i;
			for(i = 0; i < n; i++)
			{
				int ret1 = fork();
			if(ret1 < 0)
			{
				printf("Fork() Failed");
			}
			else if(ret1 == 0)
			{
				printf("I am Child (with ID =  %d", getpid());
				printf(" and Parent’s ID = %d", getppid());
				printf(")\n");
			}
			else if(ret1 > 0)
			{
				int cpid = wait(NULL);
				return 0;
			}
			}
		}
		else if(ret > 0)
		{
			int cpid = wait(NULL);
			return 0;
		}
	}
	return 0;
}