#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

#define SIZE 10
int COUNTER = 0

char** Tokenize(char* command)
{
    int i, j, k, size = 0;
    for(i = 0; command[i] != '\0'; i++)
    {
        if(command[i] == ' ')
            size++; // Total words calculation
    }
    size = size + 2;
	
    char** tokenized = malloc(size * sizeof(char*));
	
    j = 0;
    for(i = 0; i < size - 1; i++)
    {
        int len = 0;
        while (command[j] == ' ') j++;
        for(k = j; command[k] != ' ' && command[k] != '\0'; k++)
        {
            len++; // Calculating word length
        }
       
        tokenized[i] = malloc((len + 1) * sizeof(char)); // Coping command in token arr
       
        memcpy(tokenized[i], &command[j], len);
        tokenized[i][len] = '\0';
        j = k + 1;
    }
   
    tokenized[size - 1] = NULL; // Last argument of execvp
   
    return tokenized;
}

void CommandHistory(char** com_his, char command)
{
	if(COUNTER < 10)
	{
		com_his[COUNTER] = malloc((lenof(command) + 1) * sizeof(char*));
	}
	for(i = 0; command[i] != '\0'; i++)
    {
        com_his[COUNTER][i] = command[i];
    }
}

int main()
{
	char** com_his = malloc(10 * sizeof(char*));
    char command[100];
    while(1)
    {
        printf("> ");
        fgets(command, 100, stdin);
        command[strcspn(command, "\n")] = 0;

        if(strcmp(command, "exit") == 0)
        {
            break;
        }
		
		CommandHistory(com_his, command);

        char** token[10] = { NULL }; // Support for up to 10 commands in a pipeline
        int num_pipes = 0;
        char* token_ptr = strtok(command, "|");
        while (token_ptr != NULL)
        {
            token[num_pipes++] = Tokenize(token_ptr);
            if (token[num_pipes - 1] == NULL)
            {
                perror("malloc failed");
                exit(1);
            }
            token_ptr = strtok(NULL, "|");
        }

        int fds[2];
        int prev_read = 0;
        pid_t pid;

        for (int i = 0; i < num_pipes; i++)
        {
            if (i < num_pipes - 1)
            {
                if (pipe(fds) < 0)
                {
                    perror("Pipe creation error");
                    exit(1);
                }
            }

            pid = fork();
            if (pid < 0)
            {
                perror("Fork error");
                exit(1);
            }
            else if(pid == 0)
            {
                if (i > 0)
                {
                    dup2(prev_read, 0);
                    close(prev_read);
                }

                if (i < num_pipes - 1)
                {
                    dup2(fds[1], 1);
                    close(fds[1]);
                }

                execvp(token[i][0], token[i]);
                perror("execvp failed");
                exit(1);
            }
            else
            {
                wait(NULL);
                close(fds[1]);
                prev_read = fds[0];
            }
        }
    }
    return 0;
}