#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>


int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};
	int status;
	pid_t pid_of_child;

	for (int i = 0; i < 5; i++)
	{
		pid_of_child = fork();
		if (pid_of_child == -1)
		{
			perror("Error");
			return (1);
		}
		else if (pid_of_child == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{			
				perror("Error");
			}
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
