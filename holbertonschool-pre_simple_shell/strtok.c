#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char ** split(const char * str, const char * delim)
{
  /* count words */
  char * s = strdup(str);

  if ((s == NULL) /* out of memory */
      || (strtok(s, delim) == 0)) /* no word */
    return NULL;

  size_t nw = 1;

  while (strtok(NULL, delim) != 0)
    nw += 1;

  strcpy(s, str); /* restore initial string modified by strtok */

  /* split */
  char ** v = malloc((nw + 1) * sizeof(char *));

  if (v == NULL)
    /* out of memory */
    return NULL;

  if ((v[0] = strdup(strtok(s, delim))) == 0) {
    /* out of memory */
    free(v);
    return NULL;
  }

  size_t i;

  for (i = 1; i != nw; ++i) {
    if ((v[i] = strdup(strtok(NULL, delim))) == NULL) {
      /* out of memory, free previous allocs */
      while (i-- != 0)
        free(v[i]);
      free(v);
      return NULL;
    }
  }

  v[i] = NULL; /* end mark */

  free(s);

  return v;
}

int main()
{
  const char * s = "bob is still great";
  char ** v = split(s, " ");

  if (v == NULL)
    puts("no words of not enough memory");
  else {
    for (int i = 0; v[i] != NULL; ++i) {
      puts(v[i]);
      free(v[i]);
    }

    free(v);
  }
  return 0;
}
