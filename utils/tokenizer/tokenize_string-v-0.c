#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void tokenize_string(char *string, char *delimeter) 
{
	char *tokens_str = strdup(string);
	char *token;
	int token_count = 0;

	token = strtok(tokens_str, delimeter);

	while (token != NULL)
	{
		printf("Token position [%d] => [%s]\n", token_count++, token);
		token = strtok(NULL, delimeter);
	}

	printf("Extracted tokens %d\n", token_count);
}
  
int main()
{
	tokenize_string("Some string text and some xaraxa", " ");
	return 0;
}