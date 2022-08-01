#include <stdio.h>

extern char **environ;

int main(int ac, char **av, char **env)
{
	printf("address of env: %p\n", &env);
	printf("address of environ: %p\n", &environ);

	return (0);
}
