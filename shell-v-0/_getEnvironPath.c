#include "shell.h"

extern char **environ;
int i;

char *_getEnvironPath()
{
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			return environ[i] + 5;
		}
	}
	return NULL;
}