// ProceduralneProgramovanieProjekt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SUBOR "sifra.txt"
#define MAX 1000

void funkciaN(FILE* subor, char pole[], int* setLength);
void funkciaV(char pole[], int length);
void funkciaU(char poleP[], int lengthP, char poleU[], int* lengthU);
void funkciaS(char pole[], int length);
void funkciaD(char poleP[], int lengthP);
void funkciaH(char poleU[], int lengthU);
void funkciaC(char poleU[], int lengthU);

int main()
{

	char polePovodne[MAX] = {};
	char poleUpravene[MAX] = {};
	char rozhodnutie;
	FILE* subor1 = NULL;
	int lengthPovodne = 0;
	int lengthUpravene = 0;

	
	//bug,zrejme berie aj koniec znaku do dlzky

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
			case 'd':
				funkciaD(polePovodne, lengthPovodne);
				break;
			case 'h':
				funkciaH(poleUpravene, lengthUpravene);
				break;
			case 'c':
				funkciaC(poleUpravene, lengthUpravene);
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
void funkciaD(char poleP[], int lengthP) {
	if (lengthP == 0) printf("Sprava nie je nacitana.\n");
	else {
		int k;
		scanf("%d", &k);
		if (k >= 1 && k <= 100) {
			char rozdelovac[] = "\n  ";
			char* veta = strtok(poleP, rozdelovac);
			while (veta != NULL) {
				if ((unsigned)strlen(veta) == 3) printf("%s\n", veta);
				veta = strtok(NULL, rozdelovac);
			}
		}
		else printf("Nespravna dlzka.\n");
	}	
}
void funkciaH(char poleU[], int lengthU) {
	if (lengthU == 0) printf("Nie je k dispozicii upravena sprava.\n");
	else {
		int pocet[26] = { 0 };
		int percenta[26] = { 0 };
		int max;

		for (int i = 0;i < lengthU;i++) pocet[poleU[i] - 65]++;
		for (int i = 0;i < 26;i++) percenta[i] = ((pocet[i] * 100)/lengthU / 10);

		max = percenta[0];
		for (int i = 1;i < 26;i++) if (percenta[i] > max) max = percenta[i];

		for (int i = max;i >= 0;i--) {
			for (int y = 0;y < 26;y++) {
				if (percenta[y] > i) printf("*");
				else printf(" ");
			}
			printf("\n");
		}
		for (int i = 0;i < 26;i++) printf("%c", 65 + i);
	}	
}
void funkciaC(char poleU[], int lengthU){
	if (lengthU == 0) printf("Nie je k dispozicii upravena sprava.\n");
	else {
		int n;
		scanf("%d", &n);
		if (n >= 1 && n <= 25) {
			for (int i = 0;i < lengthU;i++) {
				poleU[i]=(poleU[i]+n-65)%26 + 65;
				printf("%c", poleU[i]);
			}
			printf("\n");
		}
		else printf("Nespravna dlzka.\n");
	}
}