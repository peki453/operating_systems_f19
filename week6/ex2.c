#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
        // Create two strings (size of string is 6)
	char A[6] = "ABCDEF", B[6];

        // Create pipe
	int P[2];
	
	// Check if pipe is negative
	if (pipe(P) < 0) exit(1);

	// Child process
        if (fork() == 0)
        {
                read(P[0], B, 6);
                printf("Message from child process: %s\n", B);
        }

	// Parent process
        else
	{
		printf("Message from parent process.\n");
                write(P[1], A, 6);
        }

	return 0;
}

/*

Output of this program is:

Message from parent process.
Message from child process: ABCDEF

*/