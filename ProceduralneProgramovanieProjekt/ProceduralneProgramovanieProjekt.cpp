#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SUBOR "sifra.txt"
#define MAX 1000
#define rozsahPismen 26
#define startASCII 65


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
	char choice;
	FILE* subor1 = NULL;
	int lengthPovodne = 0;
	int lengthUpravene = 0;

	while (1) {
		scanf(" %c", &choice);
		if (choice == 'k') break;
		else {
			switch (choice) {
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
			default: printf("Toto pismeno nie je k dispozicii.\n");
			}
		}
	}
	return 0;
}

void funkciaN(FILE* subor, char pole[], int* length) {
	if ((subor = fopen(SUBOR, "r")) == NULL) printf("Spravu sa nepodarilo nacitat.\n");
	else {
		int c, counter = 0;
		while ((c = getc(subor)) != EOF) {
			if (counter == MAX + 1) break;
			counter++;
			pole[counter - 1] = c;
		}
		*length = counter;
		if ((fclose(subor)) != 0) printf("Subor sa nepodarilo zatvorit");
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
		int counter = 0;
		for (int i = 0;i < lengthP;i++) {
			if (isalpha(poleP[i])) {
				counter++;
				poleU[counter - 1] = toupper(poleP[i]);
			}
		}
		*lengthU = counter;
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
			char gap[] = "\n  ";
			char* sentence = strtok(poleP, gap);
			while (sentence != NULL) {
				if ((unsigned)strlen(sentence) == k) printf("%s\n", sentence);
				sentence = strtok(NULL, gap);
			}
		}
		else printf("Nespravna dlzka.\n");
	}	
}
void funkciaH(char poleU[], int lengthU) {
	if (lengthU == 0) printf("Nie je k dispozicii upravena sprava.\n");
	else {

		int pocet[rozsahPismen] = {0};
		int percenta[rozsahPismen] = {0};
		int max;

		for (int i = 0;i < lengthU;i++) pocet[poleU[i] - startASCII]++;
		for (int i = 0;i < rozsahPismen;i++) percenta[i] = ((pocet[i] * 100)/lengthU/10);

		max = percenta[0];
		for (int i = 1;i < rozsahPismen;i++) if (percenta[i] > max) max = percenta[i];
		for (int i = max;i >= 0;i--) {
			for (int y = 0;y < rozsahPismen;y++) {
				if (percenta[y] > i) printf("*");
				else printf(" ");
			}
			printf("\n");
		}
		for (int i = 0;i < rozsahPismen;i++) printf("%c", startASCII + i);
		printf("\n");
	}	
}
void funkciaC(char poleU[], int lengthU){
	if (lengthU == 0) printf("Nie je k dispozicii upravena sprava.\n");
	else {
		int n;
		scanf("%d", &n);
		if (n >= 1 && n <= 25) {
			for (int i = 0;i < lengthU;i++) {
				poleU[i]=((poleU[i]-n- startASCII) % rozsahPismen) + startASCII;
				printf("%c", poleU[i]);
			}
			printf("\n");
		}
		else printf("Nespravna dlzka.\n");
	}
}