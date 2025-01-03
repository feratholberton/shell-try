#include "shell.h"

char **get_tokens(char *string, char *delimeter, int *token_count)
{
	char *tokens_str;
	char **tokens = NULL;
	char *token;
	char *save_ptr;
	char **new_tokens;
	int count = 0;

	tokens_str = strdup(string);
	if (tokens_str == NULL)
	{
		perror("strdup() FAILED");
		return NULL;
	}

	token = strtok_r(tokens_str, delimeter, &save_ptr);
	while (token != NULL)
	{
		new_tokens = realloc(tokens, (count + 1) * sizeof(char *));
		if (new_tokens == NULL)
		{
			perror("realloc() FAILED");
			free(tokens_str);
			free_tokens(tokens, count);
			return NULL;
		}

		tokens = new_tokens;

		tokens[count] = strdup(token);
		if (tokens[count] == NULL)
		{
			perror("strdup() FAILED");
			free(tokens_str);
			free_tokens(tokens, count);
			return NULL;
		}

		count++;
		token = strtok_r(NULL, delimeter, &save_ptr);
	}

	free(tokens_str);

	if (token_count)
	{
		*token_count = count;
	}

	if (count == 0)
	{
		free(tokens);
		tokens = NULL;
	}

	return tokens;
}