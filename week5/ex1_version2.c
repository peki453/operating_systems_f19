#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_message(void *t_id);

int main() 
{
	int n;

  	printf("Enter the number of threads: ");
  	scanf("%d", &n);

  	pthread_t A[n];
  	int flag;

  	for (int i = 0; i < n; i++)
  	{
   		printf("I am Thread %d.\n", i + 1);
    		
		flag = pthread_create(&A[i], NULL, print_message, (void*)i);
    		flag = 1;

    		while (flag == 1)
    		{
      			flag = pthread_join(A[i], NULL);
    		}
  	}

  	return 0;
}

void *print_message(void *t_id)
{
  	int id = ((int) t_id) + 1;
  	printf("Message from Thread %d (ID = %d).\n", id, (int)pthread_self());
  	pthread_exit(NULL);
}

/*

If we enter number 10 (number of threads), output will be:

I am Thread 1.
Message from Thread 1 (ID = -906217728).
I am Thread 2.
Message from Thread 2 (ID = -906217728).
I am Thread 3.
Message from Thread 3 (ID = -906217728).
I am Thread 4.
Message from Thread 4 (ID = -906217728).
I am Thread 5.
Message from Thread 5 (ID = -906217728).
I am Thread 6.
Message from Thread 6 (ID = -906217728).
I am Thread 7.
Message from Thread 7 (ID = -906217728).
I am Thread 8.
Message from Thread 8 (ID = -906217728).
I am Thread 9.
Message from Thread 9 (ID = -906217728).
I am Thread 10.
Message from Thread 10 (ID = -906217728).

*/
