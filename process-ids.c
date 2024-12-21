#include <stdio.h>
#include <unistd.h>

int main()
{
	int number = 17;
	pid_t process_id, process_parent_id;

	process_id = getpid();
	process_parent_id = getppid();

	printf("Process Id: %u\n", process_id);
	printf("Process Parent Id (This shell): %u\n", process_parent_id);

	return 0;
}