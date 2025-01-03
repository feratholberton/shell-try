#include "shell.h"

char *_searchPath(const char *command)
{
	const char *path_env;
	char *path_copy;
	char *token;
	size_t length;
	char *full_path;
	
	if (command == NULL)
		return NULL;

	path_env = _getEnvironPath();
	if (path_env == NULL)
	{
		fprintf(stderr, "Error: Path not found");
		return NULL;
	}

	path_copy = strdup(path_env);
	if (path_copy == NULL)
	{
		perror("strdup() FAILED");
		return NULL;
	}

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		length = strlen(token) + strlen(command) + 2;
		full_path = malloc(length);
		if (full_path == NULL)
		{
			perror("malloc() FAILED");
			free(path_copy);
			return NULL;
		}

		snprintf(full_path, length, "%s%s", token, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return full_path;
		}

		free(full_path);
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return NULL;
}