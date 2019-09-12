#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() 
{
	printf("Type some commands (Type exit to exit shell): \n");
	
	char command[50];

	printf("Console> ");
	fgets(command, 50, stdin);

	while (strcmp(command, "exit\n")) 
	{
		printf("Console> ");
		
		// Check if fork() returns zero
		if (fork() == 0) 
		{
			system(command);
			return 0;
		}

		// Read another command
		fgets(command, 50, stdin);
	}
	
	return 0;
}