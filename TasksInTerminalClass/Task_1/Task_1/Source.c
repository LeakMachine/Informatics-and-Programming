#include <stdio.h>
#include <math.h>

int main()
{
	float a, b, c;
	float avrg;
	printf("Input _3_ numbers: ");
	scanf_s("%f %f %f", &a, &b, &c);
	avrg = ((a + b + c) / 3);
	printf("Average of numbers: %f", avrg);

	return 0;
}