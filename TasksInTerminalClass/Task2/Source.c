#include <stdio.h>
#include <math.h>

int main()
{
	int price;
	int coin_ammount = 0;


	printf("Enter the price: ");
	scanf_s("%d", &price);

	while (price > 0)
	{
		if ((price - 25) >= 0)
		{
			price = price - 25;
			coin_ammount = coin_ammount + 1;
		}
		else if ((price - 10 >= 0) & (price - 25 < 0))
		{
			price = price - 10;
			coin_ammount = coin_ammount + 1;
		}
		else if ((price - 5 >= 0 ) & (price - 10 < 0) & (price - 25 < 0))
		{
			price = price - 5;
			coin_ammount = coin_ammount + 1;
		}
		else if ((price - 1 >= 0) & (price - 5 < 0) & (price - 10 < 0) & (price - 25 < 0))
		{
			price = price - 1;
			coin_ammount = coin_ammount + 1;
		}

	}

	printf("Amount of coins needed: %d \n", coin_ammount);


	return 0;
}