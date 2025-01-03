#include "shell.h"

int main() 
{
	char *line;
	char **tokens;
	int token_count = 0;

	print_banner();

	while (true)
	{
		print_prompt();

		line = get_line();
		if (line == NULL)
			break;

		if (strlen(line) == 0)
		{
			free(line);
			continue;
		}

		tokens = get_tokens(line, " ", &token_count);
		if (tokens == NULL || token_count == 0)
		{
			fprintf(stderr, "Error: Invalid input\n");
			free(line);
			continue;
		}

		if (strcmp(tokens[0], "exit") == 0)
		{
			free(line);
			free_tokens(tokens, token_count);
			break;
		}
		
		if (execute(tokens[0], tokens) == -1)
		{
			fprintf(stderr, "%s: Command not found\n", tokens[0]);
		}

		free(line);
		free_tokens(tokens, token_count);
	}

	return (EXIT_SUCCESS);
}