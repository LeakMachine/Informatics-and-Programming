// Copyright 2021 Иван Винокуров

/*
* Проект, в котором выполняется домашняя работа №3.
*
* Постановка задачи:
* Необходимо разработать программу, реализующую игру "Быки и коровы", а именно:
*	1) Игрок выбирает длину загадываемого числа от 1 до 5.
*	2) Компьютер загадывает число заданной длины с неповторяющимися цифрами.
*	3) Игрок пытается отгадать число. 
*	4) Кол-во отгаданных цифр без совпадения по индексам равно числу коров, кол-во отгаданных с совпадением по индексу равно числу быков.
*	5) Игроку даётся неограниченное кол-во попыток.
*/


#include <stdio.h>
#include <math.h>
#include <time.h>

void main() 
{
	int digits[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int temp;
	int programExit = 0, cycleExit = 0;
	int playerNumber, computerNumberL;
	int cowNumber = 0, bullNumber = 0;
	int flagFalseNumber = 0;
	int i = 0, j = 0;

	do {
		do {
			printf("\nEnter generated number's length: ");
			scanf_s("%d", &computerNumberL);
		} while (computerNumberL < 1 || computerNumberL >= 5);

		int* computerNumberAr;
		computerNumberAr = (int*)malloc(computerNumberL * sizeof(int));

		srand(time(0));
		for (i = 0; i < computerNumberL; i++) {
			computerNumberAr[i] = digits[rand() % 10];
		}

		while (computerNumberAr[0] == computerNumberAr[1] || computerNumberAr[0] == computerNumberAr[2] || computerNumberAr[0] == computerNumberAr[3] || computerNumberAr[0] == 0)   {
			computerNumberAr[0] = digits[rand() % 10];
		}

		while (computerNumberAr[1] == computerNumberAr[0] || computerNumberAr[1] == computerNumberAr[2] || computerNumberAr[1] == computerNumberAr[3]) {
			computerNumberAr[1] = digits[rand() % 10];
		}

		while (computerNumberAr[2] == computerNumberAr[1] || computerNumberAr[2] == computerNumberAr[0] || computerNumberAr[2] == computerNumberAr[3]) {
			computerNumberAr[2] = digits[rand() % 10];
		}

		while (computerNumberAr[3] == computerNumberAr[1] || computerNumberAr[3] == computerNumberAr[2] || computerNumberAr[3] == computerNumberAr[0]) {
			computerNumberAr[3] = digits[rand() % 10];
		}

		//for (i = 0; i < computerNumberL; i++) {
		//	printf("%d", computerNumberAr[i]);
		//}

		do {
			printf("\nEnter your guess (must be of generated number's length and have no repeated digits): ");
			scanf_s("%d", &playerNumber);

			int* playerNumberAr;
			playerNumberAr = (int*)malloc(computerNumberL * sizeof(int));

			for (i = 0; i < computerNumberL; i++) {
				playerNumberAr[i] = playerNumber % 10;
				playerNumber /= 10;
			}
			
			for (i = 0, j = computerNumberL - 1; i < j; i++, j--) {
				temp = playerNumberAr[i];
				playerNumberAr[i] = playerNumberAr[j];
				playerNumberAr[j] = temp;
			}

			//for (i = 0; i < computerNumberL; i++) {
			//	printf("%d", playerNumberAr[i]);
			//}

			for (i = 0; i < computerNumberL; i++) {
				int test = 0;
				int test2 = 0;
				if (computerNumberAr[i] == playerNumberAr[i]) {
					bullNumber++;
				}
				for (j = 0; j < computerNumberL; j++) {
					if (computerNumberAr[i] == playerNumberAr[j] && i != j) {
						cowNumber++;
					}
				}
			}

			printf("\nAmount of cows: %d || Amount of bulls: %d", cowNumber, bullNumber);

			if (bullNumber == computerNumberL) {
				printf("\nYou've guessed the number! \n");
				cycleExit = 1;
			}
			else if (bullNumber != computerNumberL) {
				bullNumber = 0;
				cowNumber = 0;
			}
		} while (cycleExit != 1);
		bullNumber = 0;
		printf("\n(1 - quit, 0 - play again)\n");
		printf("Do you want to quit or play again? 1/0: ");
		scanf_s("%d", &programExit);
		


	} while (programExit != 1);
	
	free(computerNumberAr);
	free(playerNumberAr);

	
}