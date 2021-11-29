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
#include <stdlib.h>

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

void priceInit(int arBarcodePr[], int arDiscount[], int arPrice[] , int* totalCostPr, int* barcodeValid , double* discount, int barcodeScan1, int barcodeScan2, int barcodeScan3, int barcodeScan4, int n) {
	(*barcodeValid) = arBarcodePr[0] == barcodeScan1 && arBarcodePr[1] == barcodeScan2 && arBarcodePr[2] == barcodeScan3 && arBarcodePr[3] == barcodeScan4;
	(*discount) = arDiscount[n] * 0.01;
	(*totalCostPr) = arPrice[n] - (arPrice[n] * (*discount));
}

void productPrint1(int arPrice[], int arDiscount[], int* countPr, int* sum, int* sumNoDisc, int totalCostPr, int n) {

	(*countPr) += 1;
	(*sum) += totalCostPr;
	(*sumNoDisc) += arPrice[n];

	printf(" - %d rubles for 1  - %d percent discount -  %d with discount\n", arPrice[n], arDiscount[n], totalCostPr);
}

int main() {

	srand(time(NULL));

	int exitProgram = 0, exitProductPick = 0;

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
	int barcodeValid1, barcodeValid2, barcodeValid3, barcodeValid4, barcodeValid5, barcodeValid6;
	double discount1, discount2, discount3, discount4, discount5, discount6;

	for (int i = 0; i < 6; i++) {
		arDiscount[i] = (rand() % 100) / 2;
	}

	do {
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

			priceInit(arBarcodePr1, arDiscount, arPrice, &totalCostPr1, &barcodeValid1, &discount1, barcodeScan1, barcodeScan2, barcodeScan3, barcodeScan4, 0);
			priceInit(arBarcodePr2, arDiscount, arPrice, &totalCostPr2, &barcodeValid2, &discount2, barcodeScan1, barcodeScan2, barcodeScan3, barcodeScan4, 1);
			priceInit(arBarcodePr3, arDiscount, arPrice, &totalCostPr3, &barcodeValid3, &discount3, barcodeScan1, barcodeScan2, barcodeScan3, barcodeScan4, 2);
			priceInit(arBarcodePr4, arDiscount, arPrice, &totalCostPr4, &barcodeValid4, &discount4, barcodeScan1, barcodeScan2, barcodeScan3, barcodeScan4, 3);
			priceInit(arBarcodePr5, arDiscount, arPrice, &totalCostPr5, &barcodeValid5, &discount5, barcodeScan1, barcodeScan2, barcodeScan3, barcodeScan4, 4);
			priceInit(arBarcodePr6, arDiscount, arPrice, &totalCostPr6, &barcodeValid6, &discount6, barcodeScan1, barcodeScan2, barcodeScan3, barcodeScan4, 5);

			if (barcodeValid1) {
				printf("Barcode is valid. Your product is: \n");
				for (int j = 0; j < NAME_LEN; j++) {
					printf("%c", arPrName[0][j]);
				}
				productPrint1(arPrice, arDiscount, &countPr1, &sum, &sumNoDisc, totalCostPr1, 0);

			}
			else if (barcodeValid2) {
				printf("Barcode is valid. Your product is: \n");
				for (int j = 0; j < NAME_LEN; j++) {
					printf("%c", arPrName[1][j]);
				}
				productPrint1(arPrice, arDiscount, &countPr2, &sum, &sumNoDisc, totalCostPr2, 1);

			}
			else if (barcodeValid3) {
				printf("Barcode is valid. Your product is: \n");
				for (int j = 0; j < NAME_LEN; j++) {
					printf("%c", arPrName[2][j]);
				}
				productPrint1(arPrice, arDiscount, &countPr3, &sum, &sumNoDisc, totalCostPr3, 2);

			}
			else if (barcodeValid4) {
				printf("Barcode is valid. Your product is: \n");
				for (int j = 0; j < NAME_LEN; j++) {
					printf("%c", arPrName[3][j]);
				}
				productPrint1(arPrice, arDiscount, &countPr4, &sum, &sumNoDisc, totalCostPr4, 3);

			}
			else if (barcodeValid5) {
				printf("Barcode is valid. Your product is: \n");
				for (int j = 0; j < NAME_LEN; j++) {
					printf("%c", arPrName[4][j]);
				}
				productPrint1(arPrice, arDiscount, &countPr5, &sum, &sumNoDisc, totalCostPr5, 4);

			}
			else if (barcodeValid6) {
				printf("Barcode is valid. Your product is: \n");
				for (int j = 0; j < NAME_LEN; j++) {
					printf("%c", arPrName[5][j]);
				}
				productPrint1(arPrice, arDiscount, &countPr6, &sum, &sumNoDisc, totalCostPr6, 5);

			}
			else {
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
					printf("\n%d unit(s) -  %d rubles for 1  - %d percent discount -  %d with discount\n\n", countPr1, arPrice[i], arDiscount[i], totalCostPr1);
				}
				break;
			case 1:
				if (countPr2 > 0) {
					for (int j = 0; j < NAME_LEN; j++) {
						printf("%c", arPrName[i][j]);
					}
					printf("\n%d unit(s) -  %d rubles for 1  - %d percent discount -  %d with discount\n\n", countPr2, arPrice[i], arDiscount[i], totalCostPr2);
				}
				break;
			case 2:
				if (countPr3 > 0) {
					for (int j = 0; j < NAME_LEN; j++) {
						printf("%c", arPrName[i][j]);
					}
					printf("\n%d unit(s) -  %d rubles for 1  - %d percent discount -  %d with discount\n\n", countPr3, arPrice[i], arDiscount[i], totalCostPr3);
				}
				break;
			case 3:
				if (countPr4 > 0) {
					for (int j = 0; j < NAME_LEN; j++) {
						printf("%c", arPrName[i][j]);
					}
					printf("\n%d unit(s) -  %d rubles for 1  - %d percent discount -  %d with discount\n\n", countPr4, arPrice[i], arDiscount[i], totalCostPr4);
				}
				break;
			case 4:
				if (countPr5 > 0) {
					for (int j = 0; j < NAME_LEN; j++) {
						printf("%c", arPrName[i][j]);
					}
					printf("\n%d unit(s)  -  %d rubles for 1  - %d percent discount -  %d with discount\n\n", countPr5, arPrice[i], arDiscount[i], totalCostPr5);
				}
				break;
			case 5:
				if (countPr6 > 0) {
					for (int j = 0; j < NAME_LEN; j++) {
						printf("%c", arPrName[i][j]);
					}
					printf("\n%d unit(s) -  %d rubles for 1  - %d percent discount -  %d with discount\n\n", countPr6, arPrice[i], arDiscount[i], totalCostPr6);
				}
				break;
			}
		}

		double temp2 = sum;
		double temp3 = sumNoDisc;
		double discountTotalTemp = temp2 / temp3;
		int discountTotal = 100 - (discountTotalTemp * 100);

		printf("%d - Total cost without discount\n\n", sumNoDisc);
		printf("%d percent - Total discount\n\n", discountTotal);
		printf("%d - Total cost\n\n", sum);

		printf("Do you want to exit the program? 0/1:");
		scanf_s("%d", &exitProgram);
		printf("--------------------------------------------------------------\n");
		printf("\n");
	} while (exitProgram != 1);

	return 0;
}