#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
	int maxChars = 256;

	/** Create space for a string of 256 characters */
	char input[maxChars];

	/** Print the prompt */
	printf("Type: ");

	/** Get the user input and store it into the input var */
	fgets(input, maxChars, stdin);

	/** Print the input var */
	printf("You typed: %s\n", input);

	return (EXIT_SUCCESS);
}