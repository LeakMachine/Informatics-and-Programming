#include <math.h>
#include <stdio.h>

void main()
{
	float a, h;
	float S;
	printf("Input triangle's _basement_ and _height_: ");
	scanf_s("%f %f", &a, &h);
	S = (0.5 * a * h);
	printf("Triangle's space: %f", S);
}