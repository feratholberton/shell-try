#include "shell.h"

extern char **environ;
int i;

char *get_environ_path()
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