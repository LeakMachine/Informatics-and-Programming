// Copyright 2021 ���� ���������

/*
* ������, � ������� ����������� �������� �������� ������ � ���������.
* 
* ���������� ������:
* 1. ��������� ��������� �������.
* 2. ��������� ��������� �������.
* 3. ����������� ���� ������� ������� �� ��������, � ������:
*		1) ����� ����� ���� ������ ��������� �������;
*		2) ����� ��������� � ������� ���������;
*		3) ����� �������� � ������� ����������;
*		4) �������� �������� ������� �������;
*		5) ����� �������� ������� � �������� �� ��������������� �� �����;
*		6) ���������� ������;
*/

#include <stdio.h>
#include <math.h>
#define ARRAY_SIZE 10										// ������

int main()
{
	/*
	* 	// ����������� �������
	*	int sum = 0, index = 0, new_value = 0;
	*
	*int array_0[100] = { 0 };								// ������ �� 100 ���������
	*int array_1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
	*int array_2[5];											// ������ � �������
	*
	*	// const int size = 10;									// ������ ������� �� �����������
	*	// int array_3[size];
	*	int array_4[ARRAY_SIZE];								// �� ��, ��� � ������, �� ����� ������
	*
	*	int size;
	*	printf("Topic: Arrays. \n");
	*	printf("Input size of dynamic array: ");
	*	scanf_s("%d", &size);
	*
	*	
	*	* // �������������� ����
	*	* char firstLetter = 'M';
	*	* int name = (int)firstLetter;
	*	
	*
	*
	*	float* mass;											// ���������� ������������� �������
	*	// malloc(size);
	*	// sizeof(float)	���������� ������ ���� ������
	*	mass = (float*)malloc(size * sizeof(float));			// ��������� ������ ��� ������������� �������
	*
	*	// �������� ���������� ��������
	*
	*	int m1[10];
	*	int m2[ARRAY_SIZE];
	*	int m3[] = { 1, 2, 3, 4, 5 };
	*	// * - ���������, int* - ��������� �� ����� �����
	*	int* m4;												// ��������� �� ������ �������������� �������
	*
	*
	*	printf("%f", mass[0]);									// ����� ������� ����� � �������
	*/


	int size;
	printf("Topic: Arrays. \n");
	printf("Input size of dynamic array: ");
	scanf_s("%d", &size);
	float* mass;											
	mass = (float*)malloc(size * sizeof(float));			

	int i;
	float sumEvenEl = 0.0, sumEvenInd = 0.0, sumEvenValues = 0.0;

	for (i = 0; i < size; i++) {
		mass[i] = i + 1;
		printf("%.1f ", mass[i]);
	}

	for (i = 0; i < size; i++) {
		if ((i + 1) % 2 == 0) {
			sumEvenEl = sumEvenEl + mass[i];
		} else {
			sumEvenInd = sumEvenInd + mass[i];
		}
		if ((int)mass[i] % 2 == 0) {
			sumEvenValues = sumEvenValues + mass[i];
		}
	}

	printf("Sum of even elements: %.1f \n", sumEvenEl);
	printf("Sum of elements with even indexes (sum of odd numbers): %.1f \n", sumEvenInd);
	printf("Sum of elements with even values: %.1f \n", sumEvenValues);

	int indx;

	printf("Input index for replacement: ");
	scanf_s("%d", &indx);

	float newValue;

	printf("Input new value: ");
	scanf_s("%f", &newValue);

	mass[indx] = newValue;

	printf("Your array now: \n");
	for (i = 0; i < size; i++) {
		printf("%.1f ", mass[i]);
	}

	float neededElement;

	printf("\n Input element of search and replacement: ");
	scanf_s("%f", &neededElement);

	for (i = 0; i < size; i++) {
		if (mass[i] == neededElement);
			mass[i] = -mass[i];

	}

	printf("Your array now: \n");
	for (i = 0; i < size; i++) {
		printf("%.1f ", mass[i]);
	}



	free(mass);												// �������� ������ �� ������������� �������

	return 0;
}