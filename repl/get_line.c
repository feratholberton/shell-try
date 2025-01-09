#include "repl.h"

char *_get_line(void)
{
	char *buffer;
	size_t bufferSize;

	buffer = NULL;

	printf("🤓 Type something, I'll tokenize it! => ");

	if (getline(&buffer, &bufferSize, stdin) == -1)
	{
		buffer = NULL;

		if (feof(stdin))
		{
			printf("[EndOfFile]\n");
			buffer = NULL;
		}
		else
		{
			printf("Getline failed");
		}
	}

	return EXIT_SUCCESS;
}
