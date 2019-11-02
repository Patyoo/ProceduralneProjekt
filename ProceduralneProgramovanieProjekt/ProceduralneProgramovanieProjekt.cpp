// ProceduralneProgramovanieProjekt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <ctype.h>

#define SUBOR "sifra.txt"
#define MAX 1000

void funkciaN(FILE* subor, char pole[], int* setLength);
void funkciaV(char pole[], int length);
void funkciaU(char poleP[], int lengthP, char poleU[], int* lengthU);
void funkciaS(char pole[], int length);

int main()
{

	char polePovodne[MAX] = {};
	char poleUpravene[MAX] = {};
	char rozhodnutie;
	FILE* subor1 = NULL;
	int lengthPovodne = 0;
	int lengthUpravene = 0;


	while (1) {
		scanf("%c", &rozhodnutie);
		if (rozhodnutie == 'k') break;
		else {

			switch (rozhodnutie) {

			case 'n':
				funkciaN(subor1, polePovodne, &lengthPovodne);
				break;
			case 'v':
				funkciaV(polePovodne, lengthPovodne);
				break;
			case 'u':
				funkciaU(polePovodne, lengthPovodne, poleUpravene, &lengthUpravene);
				break;
			case 's':
				funkciaS(poleUpravene, lengthUpravene);
				break;


			}

		}

	}



	return 0;
}

void funkciaN(FILE* subor, char pole[], int* setLength) {
	if ((subor = fopen(SUBOR, "r")) == NULL) printf("Spravu sa nepodarilo nacitat.\n");
	else {
		int c, length = 0;
		while ((c = getc(subor)) != EOF) {
			if (length == MAX + 1) break;
			length++;
			pole[length - 1] = c;
		}
		*setLength = length;
		fclose(subor);
	}
}
void funkciaV(char pole[], int length) {
	if (length == 0) printf("Sprava nie je nacitana.\n");
	else {
		for (int i = 0;i < length;i++) printf("%c", pole[i]);
		printf("\n");
	}
}
void funkciaU(char poleP[], int lengthP, char poleU[], int* lengthU) {

	if (lengthP == 0) printf("Sprava nie je nacitana.\n");
	else {
		int length = 0;
		for (int i = 0;i < lengthP;i++) {
			if (isalpha(poleP[i])) {
				length++;
				poleU[length - 1] = toupper(poleP[i]);
			}
		}
		*lengthU = length;
	}

}
void funkciaS(char pole[], int length) {
	if (length == 0) printf("Nie je k dispozicii upravena sprava.\n");
	else {
		for (int i = 0;i < length;i++) printf("%c", pole[i]);
		printf("\n");
	}
}