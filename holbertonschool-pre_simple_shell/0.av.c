#include <stdio.h>

int main(__attribute__((unused)) int ac, char **av)
{
	int i;

	for (i = 0; av[i] != NULL; i++)
	{
		printf("%s\t", av[i]);
	}
	printf("\n");
	return (0);
}
