#include "repl.h"

char **tokenize_string(char *str, char *delim, int *token_count) {

	char *copy = strdup(str);
	char **tokens = NULL;
	char *token;
	int count = 0;

	if (str == NULL || delim == NULL)
	{
		printf("Error: Null string or delimiter\n");
		return NULL;
	}
	
	if (copy == NULL)
	{
		printf("Error: Memory allocation failed\n");
		return NULL;
	}

	token = strtok(copy, delim);
	while (token != NULL)
	{
		char **new_tokens = realloc(tokens, (count + 1) * sizeof(char *));

		if (new_tokens == NULL)
		{
			printf("Error: Memory allocation failed\n");
			free(copy);
			free(tokens);
			return NULL;
		}

		tokens = new_tokens;
		tokens[count] = strdup(token);
		count++;
		token = strtok(NULL, delim);
	}

	free(copy);

	if (token_count != NULL)
	{
		*token_count = count;
	}

	return tokens;
}