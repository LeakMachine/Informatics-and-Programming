#include <stdio.h>
#include <math.h>

int main()
{
	int letter1, letter2, number1, number2;
	int ChessUnit;
	int isKingCan, isQueenCan, isBishopCan, isRookCan, isKnightCan;
	int coordinatesEqual;
	int programLive = 1;

	do {
		printf("1 - King \n2 - Queen \n3 - Bishop \n4 - Rook \n5 - Knight \nPick your unit: "); // Король, Ферзь, Слон, Ладья, Конь
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

		coordinatesEqual = ((letter1 == letter2) && (number1 == number2));
		isKingCan = ((abs(letter1 - letter2) == 1) && (abs(number1 - number2) == 1));
		isQueenCan = ((((((letter2 + number2) % (letter1 + number1)) == 0) || ((letter1 + number1) % (letter2 + number2)) == 0)) || (((letter1 != letter2) && (number1 == number2)) || ((letter1 == letter2) && (number1 != number2))));
		isBishopCan = (((((letter2 + number2) % (letter1 + number1)) == 0) || ((letter1 + number1) % (letter2 + number2)) == 0));
		isRookCan = (((letter1 != letter2) && (number1 == number2)) || ((letter1 == letter2) && (number1 != number2)));
		isKnightCan = (((abs(letter1 - letter2) == 2) || (abs(letter1 - letter2) == 1)) & ((abs(number1 - number2) == 2) || (abs(number1 - number2) == 1)));

		if ((letter1 > 8 || letter1 == 0) || (letter2 > 8 || letter2 == 0) || (number1 > 8 || number1 == 0) || (number2 > 8 || number2 == 0))
			printf("Wrong coordinates. Shutting down...\n");
		else
			switch (ChessUnit)
			{
			case 1: // Король
				if (coordinatesEqual)
					printf("King is already here.\n");
				else if (isKingCan)
					printf("King can move here.\n");
				else
					printf("King can't move here.\n");
				break;
			case 2: // Ферзь
				if (coordinatesEqual)
					printf("Queen is already here.\n");
				else if (isQueenCan)
					printf("Queen can move here.\n");
				else
					printf("Queen can't move here.\n");
				break;
			case 3: // Слон
				if (coordinatesEqual)
					printf("Bishop is already here.\n");
				else if (isBishopCan)
					printf("Bishop can move here.\n");
				else
					printf("Bishop can't move here.\n");
				break;
			case 4: // Ладья
				if (coordinatesEqual)
					printf("Rook is already here.\n");
				else if (isRookCan)
					printf("Rook can move here.\n");
				else
					printf("Rook can't move here.\n");
				break;
			case 5: // Конь
				if (coordinatesEqual)
					printf("Knight is already here.\n");
				else if (isKnightCan)
					printf("Knight can move here.\n");
				else
					printf("Knight can't move here.\n");
				break;
			}
		printf("AND\n");
		if (isKingCan)
			printf("King can move here. \n");
		if (isQueenCan)
			printf("Queen can move here. \n");
		if (isBishopCan)
			printf("Bishop can move here. \n");
		if (isRookCan)
			printf("Rook can move here. \n");
		if (isKnightCan)
			printf("Knight can move here. \n\n\n");

		printf("Do you want to repeat the program? 1/0: ");
		scanf_s("%d", &programLive);

	} while (programLive != 0);

	return 0;
}