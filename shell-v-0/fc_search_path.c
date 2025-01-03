#include "shell.h"

char *search_path(const char *command)
{
	const char *path_env;
	char *path_copy;
	char *token;
	size_t length;
	char *full_path;

	if (command == NULL)
	{
		return NULL;
	}

	if (strchr(command, '/') != NULL)
	{
		if (access(command, X_OK) == 0)
		{
			return strdup(command);
		}
		else
		{
			return NULL;
		}
	}

	path_env = get_environ_path();
	if (path_env == NULL)
	{
		return NULL;
	}

	path_copy = strdup(path_env);
	if (path_copy == NULL)
	{
		return NULL;
	}

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		length = strlen(token) + strlen(command) + 2;
		full_path = malloc(length);
		if (full_path == NULL)
		{
			free(path_copy);
			return NULL;
		}

		snprintf(full_path, length, "%s/%s", token, command);

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