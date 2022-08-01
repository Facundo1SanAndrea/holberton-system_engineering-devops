#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *buffer, *buff_cpy, *buff_token;
	size_t bufsize = 32;

        buffer = malloc(bufsize * sizeof(char));
        if (buffer == NULL)
        {
                perror("no buffer allocated");
                return (-1);
        }
        printf("$ ");
        getline(&buffer, &bufsize, stdin);
	/* buffer - first char position where the imput string will be stored */
	/* buf_size - adress of the variable that holds the size of the input */
	/* buffer */
	/* stdin - input file handle, as specified, standard input is read */
	buff_cpy = malloc(bufsize * sizeof(char));
	if (buff_cpy == NULL)
	{
		perror("can't be allocated");
		free(buffer);
		return (-1);
	}
	strcpy(buff_cpy, buffer);
	buff_token = strtok(buff_cpy, " ");
	while (buff_token != NULL)
	{
		printf("%s\n", buff_token);
		buff_token = strtok(NULL, " ");
	}
	free(buff_cpy);
        free(buffer);
        return (0);
}
