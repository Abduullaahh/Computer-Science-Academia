#include <stdio.h>

int main(int argc, int* argv[])
{
	int sum = 0;
	int i = 1;
	for(; i < argc; i++)
	{
		sum += atoi(argv[i]);
	}
	float per = sum / 3;
	printf("Sum : %d\n", sum);
	printf("Percentage : %f\n", per);
	return 0;
}
