#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>


int main(){
	int number, mode, guess, guessCount, exit, d1 = 1, d2 = 1000;
	char c;

	guess = 0;
	guessCount = 0;
	exit = 0;

	printf("Enter program's mode: ");
	scanf_s("%d", &mode);
	switch (mode) {
		case 1: // пользователь отгадывает
			srand(time(NULL));
			number = rand() % 1000 + 1;
			while (number != guess) {
				printf("Your guess?... ");
				scanf_s("%d", &guess);
				if (guess > number)
				{
					printf("Your guess is larger than number! \n");
					guessCount++;
				}
				else if (guess < number)
				{
					printf("Your guess is less than number! \n");
					guessCount++;
				}
			}
			guessCount++;
			printf("You won! \n");
			printf("Number of guesses: %d", guessCount);

			break;
		case 2: // пользователь загадывает
			printf("Enter a number: ");
			scanf_s("%d", &number);
			while (exit != 1) {
				srand(time(NULL));
				guess = rand() % d2 + 1 ;
				printf("The guess is %d. Is it equal, larger, or less? ", guess);
				scanf_s("%c", &c, 1);
				if (c == '>')
				{
					d2 = guess;
					d1 = 1;
					guessCount++;
				}
				else if (c == '<')
				{
					d1 == guess;
					guessCount++;
				}
				else if (c == '=')
				{
					printf("I won!!! \n");
					guessCount++;
					exit = 1;
				}

			}
			printf("Number of guesses: %d", guessCount);
			break;
	}

	return 0;
}
