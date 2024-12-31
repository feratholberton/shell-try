#include "shell.h"

int main(void) {
	/** Print the prompt */
	printf("Type, hit Enter and I'll get the line: ");

	_getline();
	return (EXIT_SUCCESS);
}
