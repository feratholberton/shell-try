#include "shell.h"

int main(void) {
	int token_count = 0;
	char *line;
	char **tokens;
	_printBanner();

	while (true)
	{
		printf("I'll get the line you type and tokenize it: ");
		line = _getline();
		tokens = _strtok(line, " ", &token_count);
		_execve(tokens[0], tokens);
	}

	return (EXIT_SUCCESS);
}