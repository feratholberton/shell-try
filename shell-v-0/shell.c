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

		tokens = _strtok(line, " ", &token_count);
		if (tokens == NULL || token_count == 0)
		{
			free(line);
			continue;
		}
		
		_execve(tokens[0], tokens);

		free(line);
		_free_tokens(tokens, token_count);
	}

	return (EXIT_SUCCESS);
}