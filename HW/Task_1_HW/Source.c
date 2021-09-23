#include <stdio.h>
#include <math.h>

int main()
{
	int letter1, letter2, number1, number2;
	int ChessUnit;

	printf("1 - King \n2 - Queen \n3 - Bishop \n4 - Rook \n5 - Knight \nPick your unit: "); // ������, �����, ����, �����, ����
	scanf_s("%d", &ChessUnit);
	switch (ChessUnit)
	{
		case 1:
			printf("You've chosen King\n");
			break;
		case 2:
			printf("You've chosen Queen!\n");
			break;
		case 3:
			printf("You've chosen Bishop!\n");
			break;
		case 4:
			printf("You've chosen Rook!\n");
			break;
		case 5:
			printf("You've chosen Knight!\n");
			break;
		default:
			printf("Wrong number. Shutting down...\n");
			return 0;
	}
	printf("Enter the coordinates \n(x1 y1 x2 y2, from 1 to 8): ");
	scanf_s("%d %d %d %d", &letter1, &number1, &letter2, &number2);

	if ((letter1 > 8 || letter1 == 0) || (letter2 > 8 || letter2 == 0)|| (number1 > 8 || number1 == 0)|| (number2 > 8 || number2 == 0))
		printf("Wrong coordinates. Shutting down...\n");
	else
		switch (ChessUnit)
		{
		case 1: // ������
			if ((letter1 == letter2) & (number1 == number2))
				printf("King is already here.");
			else if ((abs(letter1 - letter2) == 1) & (abs(number1 - number2) == 1))
				printf("King can move here.");
			else
				printf("King can't move here.");
			break;
		case 2: // �����
			if ((letter1 == letter2) & (number1 == number2))
				printf("Queen is already here.");
			else if ((((((letter2 + number2) % (letter1 + number1)) == 0) || ((letter1 + number1) % (letter2 + number2)) == 0)) || (((letter1 != letter2) & (number1 == number2)) || ((letter1 == letter2) & (number1 != number2))))
				printf("Queen can move here.");
			else
				printf("Queen can't move here.");
			break;
		case 3: // ����
			if ((letter1 == letter2) & (number1 == number2))
				printf("Bishop is already here.");
			else if (((((letter2 + number2) % (letter1 + number1)) == 0) || ((letter1 + number1) % (letter2 + number2)) == 0))
				printf("Bishop can move here.");
			else
				printf("Bishop can't move here.");
			break;
		case 4: // �����
			if ((letter1 == letter2) & (number1 == number2))
				printf("Rook is already here.");
			else if (((letter1 != letter2) & (number1 == number2)) || ((letter1 == letter2) & (number1 != number2)))
				printf("Rook can move here.");
			else
				printf("Rook can't move here.");
			break;
		case 5: // ����
			if ((letter1 == letter2) & (number1 == number2))
				printf("Knight is already here.");
			else if (((abs(letter1 - letter2) == 2) || (abs(letter1 - letter2) == 1)) & ((abs(number1 - number2) == 2) || (abs(number1 - number2) == 1)))
				printf("Knight can move here.");
			else
				printf("Knight can't move here.");
			break;
		}

	return 0;
}