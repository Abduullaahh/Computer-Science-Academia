#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	pid_t one = fork();
	if(one < 0)
	{
		printf("Fork() Failed");
	}
	else if(one == 0)
	{
		printf("Making demo_Folder\n");
		execlp("mkdir", "mkdir", "demo_folder", NULL);
		
	}
	else if(one > 0)
	{
		printf("We are in Parent 1\n");
		wait(NULL);;
		pid_t two = fork();
		if(two == 0)
		{
			printf("Making file1.txt and file2.txt\n");
			char *args[] = {"touch", "demo_folder/file1.txt", "demo_folder/file2.txt"};
			execvp("touch", args);
			
		}
		else
		{
			printf("We are in Parent 2\n");
			wait(NULL);
			pid_t three = fork();
			if(three == 0)
			{
				printf("Listing files in Demo_folder\n");
				char *args[] = {"ls", "demo_folder/file1.txt", "demo_folder/file2.txt", NULL};
				execvp("ls", args);
			}
			else
			{
				printf("We are in Parent 3\n");
				wait(NULL);
				pid_t four = fork();
				if(four == 0)
				{
					printf("Removing files in Demo_folder\n");
					char *args[] = {"-rf", "demo_folder/file1.txt", "demo_folder/file2.txt", NULL};
					execvp("rm", args);
				}
				else
				{
					printf("We are in Parent 4\n");
					wait(NULL);
				}
			}
		}
	}
	return 0;
}
