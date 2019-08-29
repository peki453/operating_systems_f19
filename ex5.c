#include <stdio.h>

int main(int argc, char *argv[])
{
	int n; 
    	sscanf(argv[1], "%d", &n); 
	
	int num_stars = 1;
	int num_spaces = n - 1;

	for (int i = 0; i < n; i++)
	{
		for (int i = 0; i < num_spaces; i++)
			printf(" ");

		for (int i = 0; i < num_stars; i++)
			printf("*");
		
		printf("\n");
		
		num_stars = num_stars + 2;
		num_spaces--;
	}
	printf("\n");

	num_stars = 1;

	for (int i = 0; i < n; i++)
	{
		for (int i = 0; i < num_stars; i++)
			printf("*");
		
		printf("\n");
		
		num_stars++;
	}
	printf("\n");

	for (int i = 0; i < n; i++)
	{
		for (int i = 0; i < n; i++)
			printf("*");
		
		printf("\n");
	}
	printf("\n");
	
	num_stars = 1;
	int flag = 0;

	for (int i = 0; i < 2 * n - 1; i++)
	{
		if (num_stars == n) flag = 1;

		for (int i = 0; i < num_stars; i++)
			printf("*");
		
		printf("\n");
		
		if (flag == 0) num_stars++;
		else num_stars--;
	}
	printf("\n");

	return 0;
}