#include "exec_as_file.h"

/**
 * main - executes a file with arguments
 * @argumentsCount: it is not used in this code but is need as we pass commands as file arguments
 * @argumentsVector: array or arguments
 */

int main(int argumentsCount, char **argumentsVector)
{
	int status;

	(void)argumentsCount;

	if (fork() == 0)
		execvp(argumentsVector[1], argumentsVector + 1);

	wait(&status);

	return EXIT_SUCCESS;
}