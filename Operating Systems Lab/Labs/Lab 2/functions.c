#include<stdio.h>
#include<stdbool.h>

void sort(int array[], bool order, int size)
{
	int i;
	if(order == true)
	{
		for(i = 0; i < size; i++)
		{
			if(array[i] > array[i + 1])
			{
				int temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
		}
	}
	else
	{
		for(i = 0; i < size; i++)
		{
			if(array[i] < array[i + 1])
			{
				int temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
		}
	}
}

void findHighest(int array[], int position, int size)
{
	int a;
	if(array[0] < array[1])
	{
		a = array[size - (position - 1)];
		printf("%d", a);
	}
	else
	{
		a = array[position - 1];
		printf("%d", a);
	}
}

void print(int array[], int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		printf("%d", array[i] , " ");
	}
}
