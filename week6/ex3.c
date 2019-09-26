#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// Function to handle signal
void handleTheSignal(int idSig)
{
        printf("\n");
	printf("Notification about signal %d\n", idSig);
}

int main()
{
        signal(SIGINT, handleTheSignal);

        // Run infinite loop
        while (1)
	{	
		// Do nothing (wait for user action)
	}

        return 0;
}