#include "repl.h"

char *get_line(void)
{
	char *buffer;
	size_t bufferSize;

	buffer = NULL;

	printf("💻 Type something, I'll repeat! => ");

	if (getline(&buffer, &bufferSize, stdin) == -1)
	{
		buffer = NULL;

		if (feof(stdin))
			printf("[EndOfFile]\n");
		else
			printf("Getline failed");
	}

	return buffer;
}
