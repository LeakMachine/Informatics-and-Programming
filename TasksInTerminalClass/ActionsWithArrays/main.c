// Copyright 2021 Иван Винокуров

/*
* Проект, в котором разбираются основные элементы работы с массивами.
* 
* Постановка задачи:
* 1. Научиться создавать массивы.
* 2. Научиться заполнять массивы.
* 3. Реализовать пару простых функций на массивах, а именно:
*		1) Найти сумму всех чётных элементов массива;
*		2) Сумму элементов с чётными индексами;
*		3) Сумму элеметов с чётными значениями;
*		4) Поменять заданный элемент массива;
*		5) Найти заданный элемент и заменить на противоположный по знаку;
*		6) Развернуть массив;
*/

#include <stdio.h>
#include <math.h>
#define ARRAY_SIZE 10										// макрос

int main()
{
	/*
	* 	// статические массивы
	*	int sum = 0, index = 0, new_value = 0;
	*
	*int array_0[100] = { 0 };								// массив на 100 элементов
	*int array_1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
	*int array_2[5];											// массив с мусором
	*
	*	// const int size = 10;									// работа зависит от компилятора
	*	// int array_3[size];
	*	int array_4[ARRAY_SIZE];								// то же, что и сверху, но через макрос
	*
	*	int size;
	*	printf("Topic: Arrays. \n");
	*	printf("Input size of dynamic array: ");
	*	scanf_s("%d", &size);
	*
	*	
	*	* // преобразование типа
	*	* char firstLetter = 'M';
	*	* int name = (int)firstLetter;
	*	
	*
	*
	*	float* mass;											// объявление динамического массива
	*	// malloc(size);
	*	// sizeof(float)	возвращает размер типа данных
	*	mass = (float*)malloc(size * sizeof(float));			// выделение памяти для динамического массива
	*
	*	// варианты объявления массивов
	*
	*	int m1[10];
	*	int m2[ARRAY_SIZE];
	*	int m3[] = { 1, 2, 3, 4, 5 };
	*	// * - указатель, int* - указатель на целое число
	*	int* m4;												// Указатель на начало целочисленного массива
	*
	*
	*	printf("%f", mass[0]);									// вывод первого числа в массиве
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



	free(mass);												// очищение памяти от динамического массива

	return 0;
}