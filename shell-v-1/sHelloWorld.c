#include <stdio.h>

extern char **environ;

int main (int argc, char *argv[])
{
	int i;

	printf("Program name: %s\n", argv[0]);
	printf("Number of arguments: %d\n", argc);

	for (i = 1; i < argc; i++)
	{
		printf("Arguments %d: %s\n", i, argv[i]);
	}

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}

	return 0;
}