#include "shell.h"

int execute(char *command, char **arguments)
{
	pid_t pid;
	char *full_path;

	if (command == NULL || arguments == NULL)
	{
		return -1;
	}

	full_path = search_path(command);
	if (full_path == NULL)
	{
		return -1;
	}

	pid = fork();
	if (pid == -1)
	{
		free(full_path);
		return -1;
	}

	if (pid == 0)
	{
		execve(full_path, arguments, NULL);
		free(full_path);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (waitpid(pid, NULL, 0) == -1)
		{
			free(full_path);
			return -1;
		}
	}

	free(full_path);
	return 0;
}
