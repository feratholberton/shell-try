#include "shelloworld.h"

char **get_tokens(char *line)
{
	char **tokens = NULL;
	char *token;
	char *line_copy;
	int index = 0;

	line_copy = strdup(line);

	token = strtok(line_copy, " ");
	while (token != NULL)
	{
		tokens = realloc(tokens, (index + 1) * sizeof(char *));
		tokens[index] = token;
		index ++;
		token = strtok(NULL, " ");
	}

	tokens = realloc(tokens, (index + 1) * sizeof(char *));
	tokens[index] = NULL;

	return tokens;
}

int main (int argc, char *argv[])
{
	char *environ_path;
	char *line;
	char **tokens;
	int i;

	environ_path = get_environ_path();

	line = get_line();

	tokens = get_tokens(line);

	printf("You entered: %s\n", line);

	for (i = 0; tokens[i] != NULL; i++)
	{
		printf("Token [%d]: %s\n", i, tokens[i]);
	}

	return 0;
}