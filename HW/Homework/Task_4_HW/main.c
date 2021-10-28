// Copyright 2021 Иван Винокуров

/*
* Проект, в котором выполняется домашняя работа №3.
* Постановка задачи (как написано в гитхабе):
* Разработать программу «Электронная касса». 
* Программа должна имитировать работу кассового аппарата по сканированию товаров и формированию чека за покупку. 
* Каждый товар идентифицируется штрих-кодом. 
* Штрих-код хранится в виде массива из четырех символов. 
* Каждый символ принимает значение от ‘0’ до ‘9’. 
* Один и тот же товар может сканироваться несколько раз, но в чек информация о каждом товаре входит в виде:
*	1) наименование  
*	2) стоимость за единицу  
*	3) количество  
*	4) общая стоимость за товар
* Чек состоит не менее чем из одной записи указанного вида. 
* Чек дополнительно включает общую стоимость товаров в покупке, суммарную скидку и итоговую сумму к оплате (все в рублях). 
* Каждый товар описывается штрих-кодом, наименованием, стоимостью за единицу товара, скидкой в процентах от стоимости. 
* Скидки устанавливаются на каждый товар независимо (в диапазоне от 1 до 50%). 
* Программа должна предоставлять следующие операции: 
*	1) «сканировать» очередной товар
*	2) вывести описание отсканированного товара
*	3) добавить данные о товаре в чек
*	4) сформировать чек за покупку
*	5) рассчитать итоговую сумму к оплате
*/


#include <stdio.h>
#include <time.h>

#define BARCODE_LEN 4
#define NAME_LEN 40

/// <summary>
/// Заполняет массив штрихкода цифрами
/// </summary>
/// <param name="arBarcodePr"> Штрихкод. </param>
/// <returns> Штрихкод. </returns>
int barcodeGenFillV(int arBarcodePr[]) {
	for (int i = 0; i < BARCODE_LEN; i++) {
		arBarcodePr[i] = rand() % 10;
	}
	return arBarcodePr;
}

/// <summary>
/// Выводит штрихкод на экран.
/// </summary>
/// <param name="arBarcodePr"> Штрихкод.</param>
void barcodePrint(int arBarcodePr[]) {
	for (int i = 0; i < BARCODE_LEN; i++) {
		printf("%d ", arBarcodePr[i]);
	}
}



int main() {

	srand(time(NULL));

	int exitProgram = 1, exitProductPick = 0;

	int arBarcodePr1[BARCODE_LEN], arBarcodePr2[BARCODE_LEN], arBarcodePr3[BARCODE_LEN], arBarcodePr4[BARCODE_LEN], arBarcodePr5[BARCODE_LEN], arBarcodePr6[BARCODE_LEN];
	barcodeGenFillV(arBarcodePr1); barcodeGenFillV(arBarcodePr2); barcodeGenFillV(arBarcodePr3); barcodeGenFillV(arBarcodePr4); barcodeGenFillV(arBarcodePr5); barcodeGenFillV(arBarcodePr6);

	char arPrName[6][NAME_LEN] = { { "Lenovo IdeaPad 1 14" }, { "Acer Aspire 5 A515 - 46 - R14K Slim" }, { "Acer Predator Helios" },{"Acer Nitro 5 AN515 - 55 - 53E5"},{"HP 15 Laptop"},{"Lenovo Chromebook Flex 5"} };
	int arPrice[6] = { 24977, 32359, 115425, 72274, 47457, 29580 };
	int arDiscount[6];

	int countPr1 = 0, countPr2 = 0, countPr3 = 0, countPr4 = 0, countPr5 = 0, countPr6 = 0;
	int productID = 0;
	int totalCostPr1 = 0, totalCostPr2 = 0, totalCostPr3 = 0, totalCostPr4 = 0, totalCostPr5 = 0, totalCostPr6 = 0;
	int sum = 0, sumNoDisc = 0;
	int barcodeScan1, barcodeScan2, barcodeScan3, barcodeScan4;

	for (int i = 0; i < 6; i++) {
		arDiscount[i] = (rand() % 100) / 2;
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < NAME_LEN; j++) {
			printf("%c", arPrName[i][j]);
		}
		switch (i) {
		case 0:
			printf(" - ");
			barcodePrint(arBarcodePr1);
			printf("\n");
			break;
		case 1:
			printf(" - ");
			barcodePrint(arBarcodePr2);
			printf("\n");
			break;
		case 2:
			printf(" - ");
			barcodePrint(arBarcodePr3);
			printf("\n");
			break;
		case 3:
			printf(" - ");
			barcodePrint(arBarcodePr4);
			printf("\n");
			break;
		case 4:
			printf(" - ");
			barcodePrint(arBarcodePr5);
			printf("\n");
			break;
		case 5:
			printf(" - ");
			barcodePrint(arBarcodePr6);
			printf("\n");
			break;
		}
	}
	printf("--------------------------------------------------------------\n");
		do {
			printf("Enter (scan) barcode of product you would like to buy: \n");
			scanf_s("%d %d %d %d", &barcodeScan1, &barcodeScan2, &barcodeScan3, &barcodeScan4);


			int barcodeValid1 = arBarcodePr1[0] == barcodeScan1 && arBarcodePr1[1] == barcodeScan2 && arBarcodePr1[2] == barcodeScan3 && arBarcodePr1[3] == barcodeScan4;
			int barcodeValid2 = arBarcodePr2[0] == barcodeScan1 && arBarcodePr2[1] == barcodeScan2 && arBarcodePr2[2] == barcodeScan3 && arBarcodePr2[3] == barcodeScan4;
			int barcodeValid3 = arBarcodePr3[0] == barcodeScan1 && arBarcodePr3[1] == barcodeScan2 && arBarcodePr3[2] == barcodeScan3 && arBarcodePr3[3] == barcodeScan4;
			int barcodeValid4 = arBarcodePr4[0] == barcodeScan1 && arBarcodePr4[1] == barcodeScan2 && arBarcodePr4[2] == barcodeScan3 && arBarcodePr4[3] == barcodeScan4;
			int barcodeValid5 = arBarcodePr5[0] == barcodeScan1 && arBarcodePr5[1] == barcodeScan2 && arBarcodePr5[2] == barcodeScan3 && arBarcodePr5[3] == barcodeScan4;
			int barcodeValid6 = arBarcodePr6[0] == barcodeScan1 && arBarcodePr6[1] == barcodeScan2 && arBarcodePr6[2] == barcodeScan3 && arBarcodePr6[3] == barcodeScan4;

			double discount1 = arDiscount[0] * 0.01;
			double discount2 = arDiscount[1] * 0.01;
			double discount3 = arDiscount[2] * 0.01;
			double discount4 = arDiscount[3] * 0.01;
			double discount5 = arDiscount[4] * 0.01;
			double discount6 = arDiscount[5] * 0.01;

			totalCostPr1 = arPrice[0] - (arPrice[0] * discount1);
			totalCostPr2 = arPrice[1] - (arPrice[1] * discount2);
			totalCostPr3 = arPrice[2] - (arPrice[2] * discount3);
			totalCostPr4 = arPrice[3] - (arPrice[3] * discount4);
			totalCostPr5 = arPrice[4] - (arPrice[4] * discount5);
			totalCostPr6 = arPrice[5] - (arPrice[5] * discount6);

			if (barcodeValid1) {
				printf("Barcode is valid. Your product is: \n");
				countPr1++;
				sum = sum + totalCostPr1;
				sumNoDisc = sumNoDisc + arPrice[0];

				for (int j = 0; j < NAME_LEN; j++) {
					printf("%c", arPrName[0][j]);
				}

				printf(" - ");
				printf("%d rubles for 1  - %d percent discount -  %d with discount", arPrice[0], arDiscount[0], totalCostPr1);

			}else if (barcodeValid2) {
				printf("Barcode is valid. Your product is: \n");
				countPr2++;
				sum = sum + totalCostPr2;
				sumNoDisc = sumNoDisc + arPrice[1];

				for (int j = 0; j < NAME_LEN; j++) {
					printf("%c", arPrName[1][j]);
				}

				printf(" - ");
				printf("%d rubles for 1  - %d percent discount -  %d with discount\n", arPrice[1], arDiscount[1], totalCostPr2);

			}else if (barcodeValid3) {
				printf("Barcode is valid. Your product is: \n");
				countPr3++;
				sum = sum + totalCostPr3;
				sumNoDisc = sumNoDisc + arPrice[2];

				for (int j = 0; j < NAME_LEN; j++) {
					printf("%c", arPrName[2][j]);
				}

				printf(" - ");
				printf("%d rubles for 1  - %d percent discount -  %d with discount\n", arPrice[2], arDiscount[2], totalCostPr3);

			}else if (barcodeValid4) {
				printf("Barcode is valid. Your product is: \n");
				countPr4++;
				sum = sum + totalCostPr4;
				sumNoDisc = sumNoDisc + arPrice[3];

				for (int j = 0; j < NAME_LEN; j++) {
					printf("%c", arPrName[3][j]);
				}

				printf(" - ");
				printf("%d rubles for 1  - %d percent discount -  %d with discount\n", arPrice[3], arDiscount[3], totalCostPr4);

			}else if (barcodeValid5) {
				printf("Barcode is valid. Your product is: \n");
				countPr5++;
				sum = sum + totalCostPr5;
				sumNoDisc = sumNoDisc + arPrice[4];

				for (int j = 0; j < NAME_LEN; j++) {
					printf("%c", arPrName[4][j]);
				}

				printf(" - ");
				printf("%d rubles for 1  - %d percent discount -  %d with discount\n", arPrice[4], arDiscount[4], totalCostPr5);

			}else if (barcodeValid6) {
				printf("Barcode is valid. Your product is: \n");
				countPr6++;
				sum = sum + totalCostPr6;
				sumNoDisc = sumNoDisc + arPrice[5];

				for (int j = 0; j < NAME_LEN; j++) {
					printf("%c", arPrName[5][j]);
				}

				printf(" - ");
				printf("%d rubles for 1  - %d percent discount -  %d with discount\n", arPrice[5], arDiscount[5], totalCostPr6);

			}else {
				printf("Barcode is invalid.\n");
			}
			printf("\nExit product picking sequence? 0/1: ");
			scanf_s("%d", &exitProductPick);
		} while (exitProductPick != 1);

		printf("--------------------------------------------------------------\n");
		printf("Creating check...\n\n");

		for (int i = 0; i < 6; i++) {
			switch (i) {
			case 0:
				if (countPr1 > 0) {
					for (int j = 0; j < NAME_LEN; j++) {
						printf("%c", arPrName[i][j]);
					}
					printf(" - %d  -  %d rubles for 1  - %d percent discount -  %d with discount\n", countPr1, arPrice[i], arDiscount[i], totalCostPr1);
				}
				break;
			case 1:
				if (countPr2 > 0) {
					for (int j = 0; j < NAME_LEN; j++) {
						printf("%c", arPrName[i][j]);
					}
					printf(" - %d  -  %d rubles for 1  - %d percent discount -  %d with discount\n", countPr2, arPrice[i], arDiscount[i], totalCostPr2);
				}
				break;
			case 2:
				if (countPr3 > 0) {
					for (int j = 0; j < NAME_LEN; j++) {
						printf("%c", arPrName[i][j]);
					}
					printf(" - %d  -  %d rubles for 1  - %d percent discount -  %d with discount\n", countPr3, arPrice[i], arDiscount[i], totalCostPr3);
				}
				break;
			case 3:
				if (countPr4 > 0) {
					for (int j = 0; j < NAME_LEN; j++) {
						printf("%c", arPrName[i][j]);
					}
					printf(" - %d  -  %d rubles for 1  - %d percent discount -  %d with discount\n", countPr4, arPrice[i], arDiscount[i], totalCostPr4);
				}
				break;
			case 4:
				if (countPr5 > 0) {
					for (int j = 0; j < NAME_LEN; j++) {
						printf("%c", arPrName[i][j]);
					}
					printf(" - %d  -  %d rubles for 1  - %d percent discount -  %d with discount\n", countPr5, arPrice[i], arDiscount[i], totalCostPr5);
				}
				break;
			case 5:
				if (countPr6 > 0) {
					for (int j = 0; j < NAME_LEN; j++) {
						printf("%c", arPrName[i][j]);
					}
					printf(" - %d  -  %d rubles for 1  - %d percent discount -  %d with discount\n", countPr6, arPrice[i], arDiscount[i], totalCostPr6);
				}
				break;
			}
		}

		double temp2 = sum;
		double temp3 = sumNoDisc;
		double discountTotalTemp = temp2 / temp3;
		int discountTotal = 100 - (discountTotalTemp * 100);

		printf("%d - Total cost without discount\n", sumNoDisc);
		printf("%d percent - Total discount\n", discountTotal);
		printf("%d - Total cost\n", sum);


	return 0;
}