#include <stdio.h>
#include <math.h>

int main()
{
	float a, b, c;
	float avrg;
	printf("Input _3_ numbers: ");
	scanf_s("%f %f %f", &a, &b, &c);
	avrg = ((sqrt(a) + sqrt(b) + sqrt(c)) / 3);
	printf("Average of numbers' roots: %f", avrg);

	return 0;
}