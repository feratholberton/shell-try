#include "shellowWorld.h"

void print_string(const char *string)
{
	write(STDOUT_FILENO, string, strlen(string));
}