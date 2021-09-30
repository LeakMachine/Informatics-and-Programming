#include <math.h>
#include <stdio.h>
#define PI 3.14

void main()
{
	float r;
	float S;
	printf("Input circles's _radius_: ");
	scanf_s("%f", &r);
	S = (r * r * PI); // M_PI не работал почему-то
	printf("Circle's space: %f", S);
}