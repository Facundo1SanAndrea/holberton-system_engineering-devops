#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main(int argc, char **argv)
{

	if (argc < 2)
	{
		printf("%s\n",argv[0]);
		return (1);
	}
	char *fullpath = realpath(argv[1], NULL);
	printf("%s\n", fullpath);
	return (0);
}
