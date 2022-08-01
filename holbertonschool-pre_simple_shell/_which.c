#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <string.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	unsigned int i;
	struct stat st;
	char *path = getenv("PATH");
	char *pathtok, *cpath; /* cpath = checkpath fully "built" */

	if (ac < 2)
	{
		return (1);
	}
	i = 1;
	while (av[i])
	{
		pathtok = strdup(path);

		pathtok = strtok(path, ":");

		while (pathtok)
		{
			cpath = malloc(strlen(pathtok) + strlen(av[i]) + 2);
			
			strcpy(cpath, pathtok);

			strcat(cpath, "/");

			strcat(cpath, av[i]);

			if (stat(cpath, &st) == 0)
			{
				printf("%s\n", cpath);
				return (0);
			}
			pathtok = strtok(NULL, ":");
		}
		i++;
	}
	return (1);
}
