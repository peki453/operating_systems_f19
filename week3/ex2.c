#include <stdio.h> 

// Swap function
void swap(int *a, int *b)  
{
	int tmp = *a;  
	*a = *b;  
	*b = tmp;  
}

// Bubble Sort function
void bubble_sort(int n, int arr[])  
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-i-1; j++)  
		{
			if (arr[j] > arr[j+1]) swap(&arr[j], &arr[j+1]);
		}
	}
}

// Main function
int main()  
{
	int n;
	printf("Input number of elements: ");
	scanf("%d", &n);
	
	int array[n];

	printf("Input array elements: ");
	for (int i = 0; i < n; i++)
		scanf("%d", &array[i]);

	bubble_sort(n, array);  
 	
	printf("Sorted array: ");
	for (int i = 0; i < n; i++)
		printf("%d ", array[i]);
	printf("\n");

	return 0;
}  