#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() 
{
        // Create pipe
        int P[2];

        pid_t child_1_pid;

        //creating the 1st child
        child_1_pid = fork();
	
	/* *** FIRST CHILD *** */
	
        if (child_1_pid == 0)
        {
		// Variable for storing second child pid
            	pid_t store_2_pid;
            	
		// Print message
		printf("First child is reading PID of the second child\n");
            	
		read(P[0], &store_2_pid, sizeof(store_2_pid));

            	printf("Waiting 3 seconds...\n");
	        for (int i = 0; i < 3; i++) sleep(1);

            	// Stop second process
            	kill(store_2_pid, SIGSTOP);

            	printf("Second child process is stopped\n");
		
            	exit(0);
        }
	
	/* *** SECOND CHILD *** */

        else
        {
		// Declare and create second child
                pid_t child_2_pid;
                child_2_pid = fork();

                if(child_2_pid == 0)
                {
                  	while(1) //infinite loop
                  	{
                   	 	printf("Message from the second child\n");
                    		sleep(1);
                  	}
                }
		
                else
                {
                        // Write second PID to a pipe
                        write(P[1], &child_2_pid, sizeof(child_2_pid));
                        
                        int tmp;
                        pid_t tmp_pid = waitpid(child_2_pid, &tmp, 0);

                        if (WIFEXITED(tmp))
			{
                                printf("Child number %d terminated (status: %d)\n", tmp_pid, WEXITSTATUS(tmp));
			}
                }
        }
	
        return 0;
}