#include "shell.h"

void _execve(char *command, char **arguments)
{
	if (fork() == 0)
	{
		if (execve(command, arguments, NULL) == -1)
		{
			perror("execve() FAILED");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
