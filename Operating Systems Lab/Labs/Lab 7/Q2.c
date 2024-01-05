#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	char* a[] = {argv[0], NULL};
	int b = open(argv[1], O_RDONLY);
	int c = open(argv[2], O_WRONLY);
	dup2(b, 0);
	dup2(c, 1);
	execvp(a[0], a);
	return 0;
}
