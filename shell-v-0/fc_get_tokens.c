#include "shell.h"

char **get_tokens(char *string, char *delimeter, int *token_count)
{
	char *tokens_str = strdup(string);
	char **tokens = NULL;
	char *token;
	char **new_tokens;
	int count = 0;
	int i;

	if (tokens_str == NULL)
	{
		perror("strdup() FAILED");
		return NULL;
	}

	token = strtok(tokens_str, delimeter);

	while (token != NULL)
	{
		new_tokens = realloc(tokens, (count + 1) * sizeof(char *));
		if (new_tokens == NULL)
		{
			perror("realloc() FAILED");
			free(tokens_str);

			for (i = 0; i < count; i++)
			{
				free(tokens[i]);
			}
			free(tokens);

			return NULL;
		}

		tokens = new_tokens;
		tokens[count] = strdup(token);
		if (tokens[count] == NULL)
		{
			perror("strdup() FAILED");

			free(tokens_str);

			for (i = 0; i < count; i++)
			{
				free(tokens[i]);
			}
			free(tokens);

			return NULL;
		}

		count++;
		token = strtok(NULL, delimeter);
	}

	free(tokens_str);

	if (token_count)
	{
		*token_count = count;
	}

	return tokens;
}