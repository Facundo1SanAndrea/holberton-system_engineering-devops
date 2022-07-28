#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(void)
{
        int status;
        pid_t pid;
        char *buffer;
        char **argv;
        size_t buff_size = 32;

        buffer = malloc(buff_size * sizeof(char));

        while (1)
        {
                printf("#cisfun$ ");

                getline(&buffer, &buff_size, stdin);
                
		argv = malloc(2 * sizeof(char*));
                
		argv[0] = malloc((strlen(buffer)) * sizeof(char));
                
		argv[0] = strtok(buffer, "\n");
                
		argv[1] = NULL;
                
		pid = fork();
                
		if (pid == 0)
                {
                        if (execve(argv[0], argv, NULL) == -1)
                        {
                                perror("Error");
                        }
                }
                else
                        wait(&status);
        }
        return (0);
}
