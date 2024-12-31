#include <stdio.h>
#include <stdlib.h>

int main()
{
	/** If *lineptr (input) is set to NULL before the call, then getline() will allocate a buffer for storing the line. This buffer should be freed by the user program even if getline() failed. */
	char *input = NULL;
	size_t size, currentSize;

	/** Print the prompt */
	printf("Type, hit Enter and I'll get the line: ");

	/** Get the user input and store it in input var */
	currentSize = getline(&input, &size, stdin);

	/** Print the input var */
	printf("You typed: %s", input);
	printf("%ld chars in total\n", currentSize);

	free(input);
	return (EXIT_SUCCESS);
}