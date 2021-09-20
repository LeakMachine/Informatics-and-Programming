#include <math.h>
#include <stdio.h>

void main()
{
	float a, h;
	float S;
	printf("Input rectangles's _length_ and _height_: ");
	scanf_s("%f %f", &a, &h);
	S = (a * h);
	printf("Rectangle's space: %f", S);
}