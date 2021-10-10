// Copyright 2021 Vladimir Fomin

/*Actions with arrays:
�������� ������� ������ � ����� �������� �������
	  ����������� 2 ���������:
		1. � �������������� ��� �������
		2. ��� ��� �������*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	int size, el, tmp, tmp2;

	printf("This program swaps the right and left parts of the array\n");
	printf("Input size of the array\n");
	scanf_s("%d", &size);
	int* array;
	array = (int*)malloc(size * sizeof(int));
	if (!array) {
		printf("Error. Required memory is not allocated\n");
		exit(1);
	}
	for (int i = 0; i < size; i++) {
		array[i] = 0;
	}
	printf("Input array\n");
	for (int i = 0; i < size; i++) {
		scanf_s("%d", &el);
		array[i] = el;
	}
	if (size%2==0) {
		for (int i = 0, j = size/2; j < size; i++, j++) {
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
	}
	else {
		for (int i = 0, j = size /2; j < size ; i++, j++) {
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			}
			array[size-1]=tmp;
			for (int i = size - 1; i >= size/2+1; i--)
			{
				array[i] = array[i - 1];
			}
			array[size / 2 + 1] = tmp;
	}
	printf("The resulting array: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	free(array);
	return 0;
}