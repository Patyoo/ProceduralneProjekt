// ProceduralneProjekt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <ctype.h>

#define SUBOR "sifra.txt"
#define MAX 1000

void funkciaN(FILE *subor, char pole[],int *setLength);
void funkciaV(char pole[], int length);
void funkciaU(char poleP[], int lengthP, char poleU[],int *lengthU);
void funkciaS(char pole[], int length);

int main()
{

	char polePovodne[MAX] ={};
	char poleUpravene[MAX] = {};
	char rozhodnutie;
	FILE *subor1=NULL;
	int lengthPovodne=0;
	int lengthUpravene=0;


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
				funkciaU(polePovodne, lengthPovodne,poleUpravene,&lengthUpravene);
			case 's':
				funkciaV(poleUpravene, lengthUpravene);


			}

		}
		
	}
	
	

	return 0;
}

void funkciaN(FILE *subor,char pole[],int *setLength) {
	if ((subor = fopen(SUBOR, "r")) == NULL) printf("Spravu sa nepodarilo nacitat.\n");
	else {
		int c, length = 0;
		while ((c = getc(subor)) != EOF) {
			if (length == MAX+1) break;
			length++;
			pole[length-1] = c;
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
void funkciaU(char poleP[], int lengthP, char poleU[], int *lengthU) {
	
		if (lengthP == 0) printf("Sprava nie je nacitana.\n");

		int length = 0;
		
		for (int i = 0;i < lengthP;i++) {
			if (isalpha(poleP[i])) {
				length++;
				poleU[length - 1] = toupper(poleP[i]);
				printf("%c", poleU[length - 1]);
			}
			else printf("zle");
		}

		*lengthU = length;

}
void funkciaS(char pole[], int length) {
	if (length == 0) printf("Nie je k dispozicii upravena sprava.\n");
	else {
		for (int i = 0;i < length;i++) printf("%c", pole[i]);
		printf("\n");
	}
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
