#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// Function for signal handling
void signalHandler(int idSid)
{
        if (idSid == SIGSTOP)
	{
                printf("SIGINT\n");
	}

        else if (idSid == SIGKILL)
	{
                printf("SIGKILL\n");
	}

        else if (idSid == SIGUSR1)
	{
                printf("SIGUSR1\n");
	}
}

int main()
{
        signal(SIGSTOP, signalHandler);
        signal(SIGKILL, signalHandler);
        signal(SIGUSR1, signalHandler);

        // Run infinite loop
        while (1)
	{	
		// Do nothing (wait for user action)
	}

        return 0;
}