#include <stdio.h>

// Quicksort function
void quicksort(int array[], int first, int last)
{
    int pivot, tmp;
    
    if (first < last)
    {
        int i = first, j = last;
        pivot = first;
        
        while(i < j) 
        {
            while ((array[pivot] >= array[i]) && (i < last)) i++;
            while (array[pivot] < array[j]) j--;
            
            // Swap elements
            if (i < j)
            {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
        
        tmp = array[pivot];
        array[pivot] = array[j];
        array[j] = tmp;
        
        // Recursevely call two new quicksort functions
        quicksort(array, first, j - 1);
        quicksort(array, j + 1, last);
    }
}

int main()
{
    // Input data
    int n;
    printf("Input number of elements: ");
    scanf("%d", &n);
    
    int array[n];
    
    printf("Input elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    
    // Call quick sort function
    quicksort(array, 0, n - 1);
    
    // Print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
    
    return 0;
}