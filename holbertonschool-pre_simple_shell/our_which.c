#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(char argc, char **argv)
{
	unsigned int i;
	struct stat s;
	char *pathdup, *cpath;
	char *path = getenv("PATH");

	if (ac < 2)
	{
		return(1)
	}

	i = 1;
	while (av[i])
	{
		pathdup = strdup(path);
		pathdup = strtok(path, ":");
		while (pathdup)
		{
			cpath = malloc(strlen(pathdup) * strlen(av[i] + 2);
			strcpy(cpath, pathdup);
			strcat(cpath, "/");
			strcat(cpath, av[i]);
	
