#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
	printf("Type some commands (Type exit to exit shell): \n");

	char command[50];

	printf("Console> ");
	fgets(command, 50, stdin);

	while (strcmp(command, "exit\n")) 
	{
		printf("Console> ");
		// Execute command in real console
		system(command);
		
		// Read another command
		fgets(command, 50, stdin);
	}
	
	return 0;
}