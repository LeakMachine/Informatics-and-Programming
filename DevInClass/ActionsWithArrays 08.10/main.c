// Copyright 2021 Vladimir Fomin

/*Actions with arrays:
1. ����� ������������ �������� ��������� �������
2. ����� ����������� ��������� ������� � �������� �������� 
3. ����� ������������ ��������� ������� �������� � ��������
4. �������� ������� �������� � ��������� ���������
5. �������� ������ ������ � ����� �������� �������
      ����������� 2 ���������:
	    1. � �������������� ��� �������
		2. ��� ��� �������*/

#include <stdio.h>

int main() {
	int size, UserChoice, el;	

	printf("Privetstvie\n");
	printf("Input size of the array\n");
	scanf_s("%d", &size);
	int* in_array = (int*)malloc(size * sizeof(int)) ;

	printf("Input array\n");
	for (int i = 0; i < size; i++) {
		scanf_s("%d", &el);
		in_array[i] = el;
	}
	for (int i = 0; i < size; i++) {
		printf("%d ", in_array[i]);
	}

	
	free(in_array);
	return 0;
}