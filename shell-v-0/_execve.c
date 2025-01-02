#include "shell.h"

void _execve(char *command, char **arguments)
{
	pid_t pid = fork();

	if (command == NULL || arguments == NULL)
	{
		fprintf(stderr, "Error: Invalid command or arguments.\n");
		return;
	}

	if (pid == -1)
	{
		perror("fork() FAILED");
		return;
	}


	if (pid == 0)
	{
		if (execve(command, arguments, NULL) == -1)
		{
			perror("execve() FAILED");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(pid, NULL, 0) == -1)
		{
			perror("waitpid() FAILED");
		}
	}
}
