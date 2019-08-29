#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	int max_integer = INT_MAX;
	float max_float = FLT_MAX;
	double max_double = DBL_MAX;

	printf("Int value: %d\n", max_integer);
	printf("Int size: %lu\n", sizeof(max_integer));

	printf("Float value: %f\n", max_float);
	printf("Float size: %lu\n", sizeof(max_float));

	printf("Double value: %lf\n", max_double);
	printf("Double size: %lu\n", sizeof(max_double));

	return 0;
}