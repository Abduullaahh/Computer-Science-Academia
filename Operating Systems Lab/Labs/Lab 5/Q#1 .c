#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void Reverse_Case(char *recv_buffer, int SIZE)
{
	int i;
	for(i = 0; i <= SIZE; i++)
	{
		if(recv_buffer[i] >= 'A' && recv_buffer[i] <= 'Z')
		{
			recv_buffer[i] = recv_buffer[i] + 32;
		}
		else if(recv_buffer[i] >= 'a' && recv_buffer[i] <= 'z')
		{
			recv_buffer[i] = recv_buffer[i] - 32;
		}
	}
}

int main()
{
	char *send_buffer = "wINTER IS COMING.";
	int SIZE = strlen(send_buffer);
	char recv_buffer[SIZE];
	int fd[2];
	pipe(fd);
	pid_t child_id = fork();
	if (child_id > 0)
	{
		printf("Parent Process [ID: %d]\n", getpid());
		write(fd[1], send_buffer, SIZE);
		close(fd[0]);
	}
	else
	{
		close(fd[1]);
		read (fd[0], recv_buffer, SIZE);
		printf("Child Process [ID: %d] \nOriginal String: %s\n", getpid(), recv_buffer);
		Reverse_Case(recv_buffer, SIZE);
		printf("Modified String: %s\n", recv_buffer);
	}
	return 0;
}
