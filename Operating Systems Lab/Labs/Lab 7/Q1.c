#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
	int file_desc1 = open("input.txt", O_RDONLY); 
	if (file_desc1 < 0)
	{
		printf("Error opening the input file\n");
	}
	
	char data[500];
	int status = read(file_desc1, data, 500);
	dup2(file_desc1, 0);
	
	int file_desc2 = open("output.txt", O_WRONLY); 
	if (file_desc2 < 0)
	{
		printf("Error opening the output file\n");
	}
	
	dup2(file_desc2, 1);
	printf("%s", data);
	
	return 0;
}
