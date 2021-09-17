#include <stdio.h>
#include <math.h>

int main()
{
	float a, b, c;
	float avrg;
	printf("Input _3_ numbers: ");
	scanf_s("%f %f %f", &a, &b, &c);
	avrg = (sqrt((a*a + b*b + c*c) / 3));
	printf("Average of numbers (squared): %f", avrg);

	return 0;
}