#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/resource.h>

int main() 
{
    char *pointer;
    long int info;
    struct rusage usage;

    for (int i = 0; i < 10; i++)
    {
	// Allocate 10MB of memory
	// 10 * 1024 (for KBs) * 1024 (for MBs)
        pointer = (char*) malloc(10 * 1024 * 1024 * sizeof(char));
	
	// Fill 10MB of memory with zeros
        memset(pointer, '0', 10 * 1024 * 1024 * sizeof(char));

	// Get memory usage info
    	getrusage(RUSAGE_SELF, &usage);
    	info = usage.ru_maxrss;
	
    	printf("Memory usage: %ld\n", info);
    	
	// Sleep for one second
	sleep(1);
    }

    return 0;
}

/*
Output of this program on my computer:

Memory usage: 11096
Memory usage: 21632
Memory usage: 31928
Memory usage: 42224
Memory usage: 52520
Memory usage: 62816
Memory usage: 72848
Memory usage: 83144
Memory usage: 93440
Memory usage: 103736

*/