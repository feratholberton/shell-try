#include <stdio.h>

int main()
{
	int maxChars = 256;

	/** Create space for a string of maxChars characters */
	char input[maxChars];

	while(1)
	{
		/** Print the prompt */
		printf("Enter: ");

		/** Get the user input and put it into the input var */
		fgets(input, maxChars, stdin);

		/** Print the input var */
		printf("String: %s\n", input);
	}
}