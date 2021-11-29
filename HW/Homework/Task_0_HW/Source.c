#include <stdio.h>
#include <math.h>

int main()
{
	double x1, x2, y1, y2;
	double r1, r2;
	double d;

	printf("Enter coordinates of circles' centres: ");
	scanf_s("%lf %lf %lf %lf", &x1, &x2, &y1, &y2);
	printf("Enter circles' radiuses: ");
	scanf_s("%lf %lf", &r1, &r2);
	d = (sqrt(pow(x1 - x2, 2) + pow(y2 - y1, 2)));
	if (d == r1 + r2)
		printf("Circles touch each other.");
	else if (d < r1 + r2)
		if ((d == 0) & (r1 == r2))
			printf("Circles are identical.");
		else if (d + r1 < r2 || d + r2 < r1)
			printf("One circle is inside of another.");
		else
			printf("Circles cross each other.");
	else if (d > r1 + r2)
		printf("Circles don't interact with each other.");

	return 0;
}