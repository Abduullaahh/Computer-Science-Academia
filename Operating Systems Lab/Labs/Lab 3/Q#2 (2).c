#include<stdio.h>

void Sort_Ascending(int array[], int size)
{
	int i, j;
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			if(array[j] > array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

void Sort_Decending(int array[], int size)
{
	int i, j;
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			if(array[j] < array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

void Print(int array[], int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		printf("\t");
	}
}

void main(int argc, char* argv[])
{
	int array[argc - 1], i;
	for(i = 1; i < argc; i++)
	{
		array[i - 1] = atoi(argv[i]);
	}
	int ret = fork();
	if(ret < 0)
	{
		printf("Fork() Failed");
	}
	else if(ret == 0)
	{
		int id = getpid();
		printf("I am Child 1 (with ID =  %d", getpid());
		printf(" and Parent’s ID = %d", getppid());
		printf(") ");
		Sort_Ascending(array, argc - 1);
		Print(array, argc - 1);
		printf("\n");
		int ret1 = fork();
		if(ret1 < 0)
		{
			printf("Fork() Failed");
		}
		else if(ret1 == 0)
		{
			int id = getpid();
			printf("I am Child 2 (with ID =  %d", getpid());
			printf(" and Parent’s ID = %d", getppid());
			printf(") ");
			Sort_Decending(array, argc - 1);
			Print(array, argc - 1);
			printf("\n");
		}
		else if(ret1 > 0)
		{
			int cpid = wait(NULL);
			printf("Parent Process terminating and my ID = %d", getpid());
			printf(" and Parent’s ID = %d", getppid());
			printf("\n");
		}
	}
	else if(ret > 0)
	{
		int cpid = wait(NULL);
		printf("Parent Process terminating and my ID = %d", getpid());
		printf(" and Parent’s ID = %d", getppid());
		printf("\n")