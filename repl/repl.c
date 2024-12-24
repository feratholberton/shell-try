#include "repl.h"

int main()
{
	/* REPL */
	/* Read > Evaluate > Print > Loop */	
	char *line;
	
	printBanner();

	while ((line = readLine()))
	{		
		printf("🤖 You typed: %s", line);
	}

	return EXIT_SUCCESS;
}
