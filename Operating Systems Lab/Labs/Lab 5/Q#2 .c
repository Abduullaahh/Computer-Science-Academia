#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int Sum(int arr[], int size)
{
	int i, sum = 0;
	printf("Array :");
	for (i = 0; i < size; i++)
	{
		printf(" %d", arr[i]);
	}
	printf("\n");
	for (i = 0; i < size; i++)
	{
		sum = sum + arr[i];
	}
	return sum;
}

int main()
{
	int send_arr[] = {1, 5, 7, 2, 15};
	int size = 5, sum = 0, s = 0;
	int recv_arr[size];
	int fd[2];
	int fd2[2];
	pipe(fd);
	pipe(fd2);
	pid_t child_id = fork();
	if (child_id > 0)
	{
		close(fd[0]);
		printf("\nParent Process [ID: %d]\n", getpid());
		write(fd[1], send_arr, size * sizeof(int));
		close(fd[1]);
		wait(NULL);
		read(fd2[0], &sum, 1);
		printf("\nSum recieved from child: %d\n", sum);
		close(fd2[0]);
	}
	else
	{
		close(fd[1]);
		read (fd[0], recv_arr, size * sizeof(int));
		s = Sum(send_arr, size);
		close(fd[0]);
		printf("Child Process [ID: %d]", getpid());
		write (fd2[1], &s, 1);
		close (fd2[1]);
	}
	return 0;
}
