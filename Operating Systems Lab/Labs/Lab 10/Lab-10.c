#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int time_taken;

void Signal_Handler(int sig_no)
{
    printf("Sig-Child\n");
    printf("Total time (s): %d\n", time_taken);
}

int main(int argc, char* argv[]) 
{
    int lap_no, lap_time, fd[2];
    pid_t p;
	//--------------------------
    pipe(fd);
    signal(SIGCHLD, Signal_Handler);
    printf("Enter no of laps: ");
    scanf("%d", &lap_no);
    printf("Enter lap time: ");
    scanf("%d", &lap_time);
    p = fork();
	//--------------------------
    if (p < 0) 
	{
        perror("fork");
        exit(1);
    }
    else if (p == 0) 
	{
        for (int i = 1; i <= lap_no; i++) 
		{
            sleep(lap_time);
            printf("Lap: %d  Completed", i);
            printf("\n");
        }
        int t_time = lap_time * lap_no;
        close(fd[0]);
        write(fd[1], &t_time, sizeof(t_time));
        close(fd[1]);
        exit(0);
    }
    else 
	{
        close(fd[1]);
        read(fd[0], &time_taken, sizeof(int));
        close(fd[0]);
        wait(NULL);
    }
    return 0;
}
