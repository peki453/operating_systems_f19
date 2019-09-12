#include <stdio.h>
#include <unistd.h>

int main() 
{
	int n = 453;
	int process = fork();
	
	// Case of child process
	if (process == 0) 
	{
		printf("Hello from child [%d - %d] \n", getpid(), n);
	}
	// Case of parent process
	else if (process != 0)
	{
		printf("Hello from parent [%d - %d] \n", getpid(), n);
	}

	return 0;
}