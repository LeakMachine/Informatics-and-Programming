#include <stdio.h>
#include <math.h>

int main()
{
	float a, b, c;
	float avrg1, avrg2, avrg3, avrg4;
	printf("Input _3_ numbers: ");
	scanf_s("%f %f %f", &a, &b, &c);
	avrg1 = ((a + b + c) / 3);
	printf("Average of numbers: %f\n", avrg1);
	avrg2 = (sqrt((pow(a,2) + pow(b,2) + pow(c,2)) / 3));
	printf("Average of numbers (squared): %f\n", avrg2);
	avrg3 = ((abs(a) + abs(b) + abs(c)) / 3);
	printf("Average of numbers' modules: %f\n", avrg3);
	avrg4 = ((sqrt(a) + sqrt(b) + sqrt(c)) / 3);
	printf("Average of numbers' roots: %f\n", avrg4);

	return 0;
}