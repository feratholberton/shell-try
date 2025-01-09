#include "repl.h"

int main()
{
	int i;
	int token_count;

	char **tokens = tokenize_string("Hello, world! Welcome to C programming.", " ", &token_count);
	char **tokens2 = tokenize_string("HelloWelcome toC programming.", " ", &token_count);

	if (tokens != NULL) {
		token_count = 0;
		printf("Extracted %d tokens:\n", token_count);
		for (i = 0; i < token_count; i++) {
				printf("Token[%d]: %s\n", i, tokens[i]);
				free(tokens[i]);
		}
		free(tokens);
	}
	else
	{
		printf("No tokens found");
	}

	if (tokens2 != NULL) {
		printf("Extracted %d tokens:\n", token_count);
		for (i = 0; i < token_count; i++) {
				printf("Token[%d]: %s\n", i, tokens2[i]);
				free(tokens2[i]);
		}
		free(tokens2);
	}
	else
	{
		printf("No tokens found");
	}

	return EXIT_SUCCESS;
}
