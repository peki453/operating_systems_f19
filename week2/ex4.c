#include <stdio.h>

void mySwap(int *a, int *b) 
{
	int tmp; 
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main() 
{
	int n, m;
	printf("Input numbers n and m: ");
	scanf("%d %d", &n, &m);
	
	mySwap(&n, &m);
	
  	printf("n = %d m = %d\n", n, m);

  	return 0;
}