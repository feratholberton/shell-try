#include "shell.h"

void _free_tokens(char **tokens, int count)
{
	int i;

	for (i = 0; i < count; i++)
	{
		free(tokens[i]);
	}

	free(tokens);
}