#include "shell.h"

char *search_path(const char *command)
{
	const char *path_env;
	char *path_copy;
	char *token;
	char *save_ptr;
	size_t length;
	char *full_path;

	if (command == NULL)
	{
		fprintf(stderr, "search_path: Null command provided\n");
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
			fprintf(stderr, "search_path: Command '%s' is not executable\n", command);
			return NULL;
		}
	}

	path_env = get_environ_path();
	if (path_env == NULL)
	{
		path_env = "/usr/bin:/bin";
	}

	path_copy = strdup(path_env);
	if (path_copy == NULL)
	{
		perror("strdup() FAILED");
		return NULL;
	}

	token = strtok_r(path_copy, ":", &save_ptr);
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

		snprintf(full_path, length, "%s/%s", token, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return full_path;
		}

		free(full_path);
		token = strtok_r(NULL, ":", &save_ptr);
	}

	free(path_copy);
	return NULL;
}