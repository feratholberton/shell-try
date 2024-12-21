#include "shellowWorld.h"

void read_command(char *command, size_t size) {
	if (fgets(command, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			print_string("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			print_string("Error while reading input.\n");
			exit(EXIT_FAILURE);
		}
	}
	command[strcspn(command, "\n")] = '\0';
}
