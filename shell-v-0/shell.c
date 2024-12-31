#include "shell.h"

int main(void) {
	_printBanner();
	while (true)
	{
		printf("I'll get the line you type and tokenize it: ");
		_getline();
	}
	return (EXIT_SUCCESS);
}
