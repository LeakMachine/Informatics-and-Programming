#include <stdio.h>
#include <string.h>

int main() {

	int number, flagInputError = 0, inputExit = 0, result = 0;

	while (inputExit == 0) {
		do {
			if (flagInputError) {
				printf("Input error. \n");
			}
			printf("Enter a number: ");
			scanf_s("%d", &number);
			flagInputError = (number <= 0);
		} while (flagInputError);

		while (number > 0) {
			result = result * 10 + number % 10;
			number /= 10;
		}
		printf("Result: %d \n", result);
		result = 0;
		
		printf("Exit? 0/1: ");
		scanf_s("%d", &inputExit);
	}


	return 0;
}