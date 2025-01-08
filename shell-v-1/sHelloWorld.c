#include "shelloworld.h"

int main (int argc, char *argv[])
{
	int i;
	char *environ_path;
	char *line;

	environ_path = get_environ_path();

	line = get_line();

	printf("You entered: %s\n", line);

	return 0;
}