#include "shelloworld.h"

extern char **environ;

char *get_environ_path()
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
			return environ[i] + 5;
	}

	return NULL;
}