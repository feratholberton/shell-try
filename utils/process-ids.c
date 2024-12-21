#include <stdio.h>
#include <unistd.h>

int main()
{
	int number = 17;
	pid_t process_id, process_parent_id;

	process_id = getpid();
	process_parent_id = getppid();

	printf("👶 Process Id (Child - This \"Program\"): %u\n", process_id);
	printf("👩 Parent Process Id (This shell session): %u\n", process_parent_id);

	return 0;
}