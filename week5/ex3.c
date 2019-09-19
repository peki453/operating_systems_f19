#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int buffer = 0;
int isempty = 1;
int isfull = 0;

// Flag for checking for errors in thread creation
int flag;

// Functions prototypes
void *printCurrentState();
void *funcProduce();
void *funcConsume();

int main() 
{
    // Declare thread variables
    pthread_t producer, consumer, states;

    // Create PRODUCER thread
    flag = pthread_create(&producer, NULL, funcProduce, NULL);
    if (flag) exit(-1);

    // Create CUSTOMER thread
    flag = pthread_create(&consumer, NULL, funcConsume, NULL);
    if (flag) exit(-1);

    // Create thread to print states
    flag = pthread_create(&states, NULL, printCurrentState, NULL);
    if (flag) exit(-1);

    pthread_join(producer, NULL);
    pthread_join(consumer, NULL);
    pthread_join(states, NULL);

    return 0;
}

void *printCurrentState()
{
    while (1) 
    {
        // Current state
        printf("Current state: ");
        printf("isempty = %d; isfull = %d; buffer = %d\n", isempty, isfull, buffer);
        
        // Wait for one minute
        sleep(60);
    }
}

void *funcProduce()
{
    while (1)
    {
        // Check buffer state
        if (isfull == 1)
        {
            continue;
        }
        else if (isempty == 1)
        {
            // Increase buffer variable
            buffer++;
            
            // Make buffer empty
            isempty = 0;
        }
        else
        {
            // Increase buffer variable
            buffer++;
            
            // If buffer is full, set isfull to be 1
            if (buffer == 8) isfull = 1;
        }
    }
}

void *funcConsume()
{
    while(1)
    {
        if (isempty)
        {
            // Nothing to consume
            continue;
        }
        else if (isfull)
        {
            // Decrease buffer
            buffer--;
            
            // Set buffer to be full
            isfull = 0;
        }
        else
        {
            // Decrease buffer
            buffer--;
            
            // If buffer is empty, set isempty to be 1
            if (buffer == 0) isempty = 1; 
        }
    }
}

/*

Output after 3 minutes:

Current state: isempty = 1; isfull = 0; buffer = 0
Current state: isempty = 0; isfull = 1; buffer = 8
Current state: isempty = 0; isfull = 1; buffer = 8

*/