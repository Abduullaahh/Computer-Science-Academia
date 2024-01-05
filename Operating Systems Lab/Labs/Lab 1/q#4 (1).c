#include <stdio.h>
#include <string.h>

int main(int argc, int* argv[])
{
	FILE * input = fopen(argv[1], "r");
	FILE * output = fopen(argv[2], "w");
	if (input == NULL)
	{
		printf("INPUT File error\n");
	}
	else if (output == NULL)
	{
		printf("OUTPUT File error\n");
	}
	else
    {
        char ch;
	    while(ch = fgetc(input) != EOF)
	    {
	    	if(isdigit(ch))
	    	{
	    		fputc(ch, output);
	    	}
	    }
    }
	fclose(input);
  	fclose(output);
  	return 0;
}