#include "shell.h"

void free_tokens(char **tokens, int count)
{
	int i;

	if (tokens == NULL || count < 0)
	{
		fprintf(stderr, "free_tokens: Invalid tokens or count\n");
		return;
	}

	for (i = 0; i < count; i++)
	{
		if (tokens[i] != NULL)
		{
			free(tokens[i]);
		}
	}

	free(tokens);
}