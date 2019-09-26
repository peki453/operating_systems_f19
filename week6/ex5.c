#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main()
{
        pid_t child_pid = fork();
	
	// Child process
        if (child_pid == 0)
        {
                while(1)
                {
                        printf("I'm alive!\n");

			// Sleep for one second
                        sleep(1);
                }
        }
	
	// Parent process
        else
        {
		// Sleep for 10 seconds
                sleep(10);

		// Send signal to child
                kill(child_pid, SIGTERM);
        }

        return 0;
}

/*
This program will print "I'm alive!" every 1 second (10 times).
*/