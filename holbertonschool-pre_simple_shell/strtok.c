#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int main(void)
{
	size_t size = 10;
	char *string;
	ssize_t byte;
	char *split;

	printf("$ ");
	string = malloc(sizeof(string) * 10);

	if (string == NULL)
		return (-1);
	byte = getline(&string, &size, stdin);

	if (byte == -1)
		printf("Error");
	split = strtok(string, " ");

	for (; split;)
	{
		printf("%s\n", split);
		split = strtok(NULL, " ");
	}
	return (0);
}
