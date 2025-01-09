#include <stdio.h>		/* For printf() */
#include <string.h>		/* For strlen() */
#include <stdlib.h>		/* For free() */

void reverseString(char str[])
{
	/* Index of the beginning of the string */
	int start = 0;
	/* Index of the end of the string */
	int end = strlen(str) - 1;
	/* Temp  for swapping */
	char temp;

	while (start < end)
	{
		/* Assing to temp the beginning index content */
		temp = str[start];
		/* Assing to beggining the end index content */
		str[start] = str[end];
		/* Assing to end the begginning index content initialy stored in temp */
		str[end] = temp;

		/* Increment the beggining index*/
		start++;
		/* Decrement the end index*/
		end--;
	}
}

int main(int argc, char *argv[])
{
	char *str = NULL;
	size_t len = 0;

	if (argc > 1)
	{
		str = strdup(argv[1]);
		if (!str)
		{
			perror("Error allocating memory");
			return 1;
		}
	}
	else
	{
		printf("Enter a string: ");

		/* Get a string from user input and dinamically allocate it */
		if (getline(&str, &len, stdin) == -1)
		{
			printf("Error reading input\n");
			free(str);
			return 1;
		}

		/* Replace New line character with Null terminator */
		str[strcspn(str, "\n")] = '\0';
	}

	printf("Initial string: %s\n", str);

	reverseString(str);

	printf("Reversed string: %s\n", str);

	/* Free allocated memory*/
	free(str);

	return 0;
}