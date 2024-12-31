#include <stdio.h>
#include <stdlib.h>

int main()
{
	int maxChars = 12;

	/** Create space for a string of maxChars characters */
	char input[maxChars];

	/** Print the prompt */
	printf("Type something, I'll echo it: ");

	/** Get the user input and store it in input var */
	fgets(input, maxChars, stdin);

	/** Print the input var */
	printf("You typed: %s\n", input);

	return (EXIT_SUCCESS);
}