#include <stdio.h>
#include <time.h>

void main() {

	int arraySize;
	int generatedNumber, generatedNumberP, generatedNumberR;
	int shiftingF;
	int temp;
	int i, j;

	printf("Enter the size of array: ");
	scanf_s("%d", &arraySize);

	printf("Enter number generation range: ");
	scanf_s("%d", &generatedNumberR);

	int* rndArray;
	rndArray = (int*)malloc(arraySize * sizeof(int));

	srand(time(0));
	for (i = 0; i < arraySize; i++) {
		generatedNumber = rand() % generatedNumberR + 1;
		generatedNumberP = rand() % 2 + 1;
		if (generatedNumberP == 1) {
			generatedNumber = -generatedNumber;
		}
		rndArray[i] = generatedNumber;
	}

	for (i = 0; i < arraySize; i++) {
		printf(" %d", rndArray[i]);
	}

	printf("\n Enter the shifting factor: ");
	scanf_s("%d", &shiftingF);

	for (i = 0; i < shiftingF; i++) {
		temp = rndArray[arraySize - 1];
		for (j = arraySize - 1; j > -1; j--) {
			rndArray[j] = rndArray[j - 1];
		}
		rndArray[0] = temp;
	}

	// (i = 0; i < arraySize; i++) {
	//	printf(" %d", rndArray[i]);
	//}

	for (i = 0, j = arraySize - 1; i < j; i++, j--) {
		temp = rndArray[i];
		rndArray[i] = rndArray[j];
		rndArray[j] = temp;
	}

	printf("\nResult: ");

	for (i = 0; i < arraySize; i++) {
		printf(" %d", rndArray[i]);
	}
}
