#include "shell.h"

void _execve(const char *command, char **arguments)
{
	if (fork() == 0)
	{
		if (execve(command, arguments, NULL) == -1) {
			perror("execve failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
