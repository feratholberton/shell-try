#include "shell.h"

void _getline()
{
	/** If *lineptr => (input) is set to NULL before the call, then getline() will allocate a buffer for storing the line. This buffer should be freed by the user program even if getline() failed. */
	char *input = NULL;
	size_t size, currentSize;

	/** Get the user input and store it in input var */
	currentSize = getline(&input, &size, stdin);

	/* Remove newline */
	input[strcspn(input, "\n")] = '\0';

	/** Print the input var */
	printf("You typed: %s\n", input);

	/** Print chars processed */
	printf("%ld total chars including '\\n'\n", currentSize);

	_strtok(input, " ");

	free(input);
}