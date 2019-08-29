#include <stdio.h>
#include <string.h>

int main() 
{
	char str[1000]; 

	printf("Input string: ");
   	scanf("%[^\n]%*c", str); 
	
	int length = strlen(str);
	
	printf("Reverse string: ");
	
	for (int i = length - 1; i >= 0; i--)
	{
		printf("%c", str[i]);
	}

   	printf("\n");

   	return 0; 
}