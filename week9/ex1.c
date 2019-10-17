#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* fp = fopen("inputForEx1.txt", "r");
    	int p[10], a[10];

	
	for (int i = 0; i < 10; i++) p[i] = -1;

	int t = 0, missNumber = 0, j;

	while (fscanf(fp, "%d", &j) == 1) 
	{
		int Fault = 1;
		int eld = 0;

		for (int i = 0; i < 10; i++) 
		{
			if (p[i] == j) {
				a[i] = (1 << (31 - 1)) & (a[i] >> 1);
				Fault = 0;
			} 
			else {
				a[i] = a[i] >> 1;
			}
			if (a[i] < a[eld] || p[i] == -1) eld = i;
		}

		t++;
		if (Fault == 0) continue;
		missNumber++;
		a[eld] = 1 << (31 - 1);
		p[eld] = j;
	}

	// Print info
	printf("Hits: %d\n", t - missNumber);
	printf("Misses: %d\n", missNumber);
	printf("Hits/miss: %f\n", (double)(t-missNumber)/(missNumber));

	return 0;
}

/*

Output (total = 1000):

Hits: 10
Misses: 990
Hits/miss: 0.010101

*/