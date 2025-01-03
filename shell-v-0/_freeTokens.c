#include "shell.h"

void free_tokens(char **tokens, int count)
{
	int i;

	for (i = 0; i < count; i++)
	{
		free(tokens[i]);
	}

	free(tokens);
}