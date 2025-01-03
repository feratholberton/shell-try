#include "shell.h"

int _execve(char *command, char **arguments)
{
	pid_t pid = fork();
	char *full_path;

	if (command == NULL || arguments == NULL)
	{
		fprintf(stderr, "Error: Invalid command or arguments.\n");
		return -1;
	}

	full_path = _searchPath(command);
	if (full_path == NULL)
	{
		fprintf(stderr, "%s: Command not found\n", command);
		return -1;
	}

	if (pid == -1)
	{
		perror("fork() FAILED");
		free(full_path);
		return -1;
	}

	if (pid == 0)
	{
		if (execve(full_path, arguments, NULL) == -1)
		{
			perror("execve() FAILED");
			free(full_path);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(pid, NULL, 0) == -1)
		{
			perror("waitpid() FAILED");
			free(full_path);
			return -1;
		}
	}

	free(full_path);
	return 0;
}
