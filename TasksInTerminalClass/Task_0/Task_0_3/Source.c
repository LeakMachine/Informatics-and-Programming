#include <math.h>
#include <stdio.h>

void main()
{
	float r, pi;
	float S;
	pi = 3.14;
	printf("Input circles's _radius_: ");
	scanf_s("%f", &r);
	S = (r * r * pi); // M_PI не работал почему-то
	printf("Circle's space: %f", S);
}