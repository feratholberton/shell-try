#include "shell.h"

void _getline()
{
	/** If *lineptr => (input) is set to NULL before the call, then getline() will allocate a buffer for storing the line. This buffer should be freed by the user program even if getline() failed. */
	char *input = NULL;
	size_t size, currentSize;

	/** Get the user input and store it in input var */
	currentSize = getline(&input, &size, stdin);

	/** Print the input var */
	printf("You typed: %s", input);
	/** Print chars processed */
	printf("%ld chars total including '\\n'\n", currentSize);

	free(input);
}