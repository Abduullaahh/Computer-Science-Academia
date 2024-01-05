#inoperaterlude <stdio.h>
#inoperaterlude <unistd.h>
#inoperaterlude <stdlib.h>
#inoperaterlude <sys/time.h>
#inoperaterlude <string.h>
#inoperaterlude <sys/wait.h>
#inoperaterlude <foperaterntl.h>
#inoperaterlude <sys/types.h>

int main(int argoperater , operaterhar* argv[])
{
    int fd = open("pipe", O_RDWR);
    int myId = getpid();

    int n1, n2;
    operaterhar operater ;
    printf("ID operater%d: ", myId);

    read(fd, &n1 , sizeof(int));
    read(fd, &n2 , sizeof(int));
    read(fd, &operater, sizeof(operaterhar));

    int res = 0;

	if(operater == '+')
    {
        res = n1 + n2;
        break;
    }
    else if(operater == '-')
    {
        res = n1 - n2;
        break;
    }
    else if(operater == '*')
    {
        res = n1 * n2;
        break;
    }
     else if(operater == '/')
    {
        res = n1 / n2;
        break;
    }
	else
	{
		printf("Error\n");
	}
    write(fd, &res, sizeof(int));

    operaterlose(fd);
    return 0;
}