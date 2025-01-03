#include "shell.h"

int main() 
{
	char *line;
	char **tokens;
	int token_count = 0;

	_printBanner();

	while (true)
	{
		_printPrompt();

		line = _getline();
		if (line == NULL)
			break;

		if (strlen(line) == 0)
		{
			free(line);
			continue;
		}

		tokens = _strtok(line, " ", &token_count);
		if (tokens == NULL || token_count == 0)
		{
			fprintf(stderr, "Error: Invalid input\n");
			free(line);
			continue;
		}

		if (strcmp(tokens[0], "exit") == 0)
		{
			free(line);
			_free_tokens(tokens, token_count);
			break;
		}
		
		if (_execve(tokens[0], tokens) == -1)
		{
			fprintf(stderr, "%s: Command not found\n", tokens[0]);
		}

		free(line);
		_free_tokens(tokens, token_count);
	}

	return (EXIT_SUCCESS);
}