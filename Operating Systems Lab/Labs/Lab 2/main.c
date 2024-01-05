#include<stdio.h>>
#include<stdbool.h>
#include"headers.h"

int main(int argc, char * argv[])
{
	int array[argc - 3], order, position, i;
	for(i = 0; i <= argc - 3; i++)
	{
		array[i] = atoi(argv[i]);
	}
	order = atoi(argv[argc -2]);
	position = atoi(argv[argc -1]);
	bool or;
	if(order == 1)
		or = true;
	else
		or = false;
		
	printf("Array Elements : ");
	print(array, argc-3);
	sort(array, or, argc-3);
	printf("Sorted Elements : ");
	print(array, argc-3);
	printf("The %d", position, " highest element in array is : ");
	findHighest(array, position, argc-3);
}
