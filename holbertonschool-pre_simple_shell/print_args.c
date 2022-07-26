#include<stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
/**
 * main - prints arguments
 * @ac: arg count
 * @av: arg value
 * Return: 0
 */

int main(int ac, char **av)
{
	int i;

	if (av[1] == NULL)
		printf("Error: no arguments to print\n");

	for (i = 1; av[i]; i++)
	{
		if (av[i + 1] != NULL)
			printf("%s ", av[i]);
		else
			printf("%s\n", av[i]);
	}
	return (0);
}
