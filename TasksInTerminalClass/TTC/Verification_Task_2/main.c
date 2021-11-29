#include <stdio.h>
#define AR_LEN 4
#define AR_HGHT 5

void main() 
{
	int applicantCount;
	int i, j;




	printf("Enter the amount of applicants: ");
	scanf_s("%d", &applicantCount);

	int** applicantsScoreAr = (int**)malloc(AR_LEN * sizeof(int));
	for (i = 0; i < AR_LEN; i++) {
		applicantsScoreAr[i] = (int*)malloc(applicantCount * sizeof(int));
	}

	for (i = 0; i < AR_LEN; i++){
		for (j = 0; j < applicantCount; j++) {
			applicantsScoreAr[0][j] = j++;
		}
	}

	for (j = 0; j < applicantCount; j++) {
		for (i = 1; j < AR_LEN; i++) {
			printf("\nEnter the applicant %d score for exam %d: ", j, i);
			scanf_s("%d", &applicantsScoreAr[i]);
			if (i == AR_LEN) {
				break;
			}
		}
	}

	for (i = 0; i < AR_LEN; i++) 
		for (j = 0; j < applicantCount; j++) 
			printf("%d", applicantsScoreAr[i][j]);


	for (int i = 0; i < AR_LEN; i++) {
		free(applicantsScoreAr[i]);
	}
	free(applicantsScoreAr);
}