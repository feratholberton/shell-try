#include "shell.h"

char *_getline()
{
	/** If *lineptr => (input) is set to NULL before the call, then getline() will allocate a buffer for storing the line. This buffer should be freed by the user program even if getline() failed. */
	char *input = NULL;
	size_t size = 0;
	ssize_t length;

	/** Get the user input and store it in input var */
	length = getline(&input, &size, stdin);
	if (length == -1)
	{
		free(input);
		return NULL;
	}

	if (input == NULL)
		return NULL;
	/* Replace new line with null terminator */
	input[strcspn(input, "\n")] = '\0';

	/** Print the input var
	printf("You typed: %s\n", input); */

	/** Print chars processed 
	printf("%ld total chars including '\\n'\n", currentSize);*/

	return input;
}