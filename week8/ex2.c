#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() 
{
    char *pointer;

    for (int i = 0; i < 10; i++)
    {
	// Allocate 10MB of memory
	// 10 * 1024 (for KBs) * 1024 (for MBs)
        pointer = (char*) malloc(10 * 1024 * 1024 * sizeof(char));
        
	// Fill 10MB of memory with zeros
	memset(pointer, '0', 10 * 1024 * 1024 * sizeof(char));
        
	// Sleep for one second
	sleep(1);
    }
    
    return 0;
}

/*
If you allocate 10MB of memory every second for 10 seconds it will not make si 
and so change drastically, but if you allocate 2-3GB every second for 10 seconds
it can be really bad for your laptop.
*/