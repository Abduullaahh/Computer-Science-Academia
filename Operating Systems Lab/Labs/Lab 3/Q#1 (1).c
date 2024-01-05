#include<stdio.h>

void Sort(int array[], int size)
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

void Print(int array[], int size)
{
	int i;
	printf("Sorted data : ");
	for(i = 0; i < size; i++)
	{
		printf("%d", array[i], "\t");
	}
}

void main(int argc, char* argv[])
{
	int array[argc - 1], i, j;
	for(i = 1, j = 0; i < argc; i++, j++)
	{
		array[j] = atoi(argv[i]);
	}
	int ret = fork();
	if(ret < 0)
	{
		printf("Fork() Failed");
	}
	else if(ret == 0)
	{
		Sort(array, argc - 1);
		Print(array, argc - 1);
		int id = getpid();
		printf("\nChild ID : %d", id);
	}
} 