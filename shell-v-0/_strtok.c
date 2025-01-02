#include "shell.h"

char **_strtok(char *string, char *delimeter, int *token_count) 
{
	char *tokens_str = strdup(string);
	char **tokens = NULL;
	char *token;
	char **new_tokens;
	int count = 0;

	token = strtok(tokens_str, delimeter);

	while (token != NULL)
	{
		new_tokens = realloc(tokens, (count + 1) * sizeof(char *));
		if (new_tokens == NULL)
		{
			perror("realloc() FAILED");
			free(tokens);
			free(tokens_str);
			return NULL;
		}

		tokens = new_tokens;
		tokens[count++] = strdup(token);

		token = strtok(NULL, delimeter);
	}

	if (token_count)
	{
		*token_count = count;
	}

	return tokens;
}