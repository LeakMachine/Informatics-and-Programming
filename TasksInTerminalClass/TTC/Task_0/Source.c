#include <math.h>
#include <stdio.h>
#define PI 3.14

void main()
{
	float at, ht, St, ar, hr, Sr, rc, Sc;
	int figure;
	printf("1 - triangle, 2 - rectangle, 3 - circle \n");
	printf("Pick your figure: \n");
	scanf_s("%d", &figure);
	switch (figure) {
		case 1:
			printf("Input triangle's _basement_ and _height_: ");
			scanf_s("%f %f", &at, &ht);
			St = (0.5 * at * ht);
			printf("Triangle's space: %f", St);
			break;
		case 2: 
			printf("Input rectangles's _length_ and _height_: ");
			scanf_s("%f %f", &ar, &hr);
			Sr = (ar * hr);
			printf("Rectangle's space: %f", Sr);
			break;
		case 3: 
			printf("Input circles's _radius_: ");
			scanf_s("%f", &rc);
			Sc = (rc * rc * PI); // M_PI не работал почему-то
			printf("Circle's space: %f", Sc);
			break;
	}
}