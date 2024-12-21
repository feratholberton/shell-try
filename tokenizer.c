#include <stdio.h>
#include <string.h>

int main()
{
	char string[] = "Dale Bo!   						 Tokenizate el			 testo";

	char *token;
	char *delimeter = " ";

	token = strtok(string, delimeter);

	while (token != NULL)
	{
		printf("Token: %s\n", token);
		token = strtok(NULL, delimeter);
	}

	return 0;
}