#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(void);

extern char **environ;

char *_getenv(const char *name)
{
	int elem, index;
	bool are_equal;

	for (elem = 0; environ[elem] != NULL; elem++)
	{
		are_equal = true; /* seteado a 1, valor TRUE en condiciones */
		for (index = 0; environ[elem][index] != '='; index++)
		{
			if (name[index] != environ[elem][index])
			{
				are_equal = false;
				break; /* sigue al proximo elemento */
			}
		}

		if (are_equal)
		{
			/* si el valor es verdadero(comparacion exitosa),
			 * devuelve los valores luego del '=' 
			 */
			return (&environ[elem][index + 1]);
		}
	}
	return (NULL); /* en caso que no se halla encontrado nombre de la
			* variable pasada como argumento
			*/
}
int main(void)
{
	char *path = _getenv("PATH");
	char *pathtok;

	pathtok = strtok(path, ":");
	while (pathtok != NULL)
	{
		printf("%s\n", pathtok);
		pathtok = strtok(NULL, ":");
	}

	return (0);
}
