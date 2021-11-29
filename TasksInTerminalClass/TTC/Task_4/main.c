#include <stdio.h>


void numberReversedClassic(int number, int* res) {
	while (number > 0) {
		(*res) = (*res) * 10 + number % 10;
		number /= 10;
	}
};

int back(int number, int buff)
{
	if (number)
	{
		return back(number / 10, (buff * 10) + (number % 10));
	}

	return buff;
}

int numberReversedRecursion(int number)
{
	return back(number, 0);
}

int main() {
	int number = 12345, result = 0;


	numberReversedClassic(number, &result);
	printf("Result: %d \n", result);

	result = 0;

	printf("%d\n", numberReversedRecursion(42069));


	return 0;
}