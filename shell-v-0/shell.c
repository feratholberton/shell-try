#include "shell.h"

int main() 
{
	char *line;
	char **tokens;
	int token_count = 0;
	int i;
	char *path_env;

	_printBanner();

	while (true)
	{
		_printPrompt();

		line = _getline();
		printf("You typed: %s\n", line);

		tokens = _strtok(line, " ", &token_count);
		for (i = 0; i < token_count ; i++)
		{
			printf("Token position [%d]: %s\n", i, tokens[i]);
		}
		
		path_env = _getEnvironmentPath();
		printf("Enviroment PATH: %s\n", path_env);
	}

	return (EXIT_SUCCESS);
}