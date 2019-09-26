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

	// Write to pipe (take content from string A)
	write(P[1], A, 6);
	
	// Read from pipe (put content to string B)
	read(P[0], B, 6);
	
	// Print string B
	printf("String B: %s\n", B);
	
	return 0;
}

/*
String A is "ABCDEF", and we will move it to B in this program.
If we run this program, output will be:

String B: ABCDEF
*/