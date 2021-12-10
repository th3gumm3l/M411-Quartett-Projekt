#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Card {
	char Bez[50];
	int LeistungPS;
	double Gewicht;
	double KgproPS;
	struct Card* pNext;
	
}struCard;
struCard* CreateCard(const char* pAuto, int LeistungPS, double Gewicht, double KgproPS);
struCard* AddCard(struCard* pStart, struCard* pNew);
void Karten_print(struCard* pStart);


void main() {
	
	Card* pStart = NULL;
	pStart = AddCard(pStart, CreateCard("Honda Civic Type R CS Fn2 2007", 201, 1300, 0.15));
	pStart = AddCard(pStart, CreateCard("Mitsubishi Lancer EVO VI Tommi Makinen Edition 1999", 280, 1365, 0.20));
	pStart = AddCard(pStart, CreateCard("Nissan Skyline GT-R R34 1999", 280, 1560, 0.17));
	pStart = AddCard(pStart, CreateCard("Mazda RX-7 1992", 240, 1300, 0.18));
	pStart = AddCard(pStart, CreateCard("Mazda Miata mx 5 1990", 115, 995, 0.11));
	pStart = AddCard(pStart, CreateCard("Mazda 3 MPS 2011", 260, 1460, 0.17));
	pStart = AddCard(pStart, CreateCard("Toyota Supra Mk4 1997", 330, 1585, 0.20));
	pStart = AddCard(pStart, CreateCard("Toyota Gt86 2012", 200, 1305, 0.15));
	pStart = AddCard(pStart, CreateCard("Nissan GTR Nismo R35 2019", 600, 1725, 0.34));
	pStart = AddCard(pStart, CreateCard("Saab 9-5 2.3 Turbo Performance 2003", 305, 1610, 0.18));
	Karten_print(pStart);
	system("pause");
}
struCard* CreateCard(const char* pAuto, int LeistungPS, double Gewicht, double KgproPS) {
	struCard* pTmp = (struCard*)malloc(sizeof(struCard));
	strcpy_s(pTmp->Bez, pAuto);
	pTmp->LeistungPS = LeistungPS;
	pTmp->Gewicht = Gewicht;
	pTmp->KgproPS = KgproPS;
	pTmp->pNext = NULL;
	return pTmp;
}
struCard* AddCard(struCard* pStart, struCard* pNew) {
	if (pStart == NULL) {
		pStart = pNew;
		pNew->pNext = NULL;
	}
	else {
		struCard* pLast = pStart;
		while (pLast->pNext != NULL) pLast = pLast->pNext;
		pLast->pNext = pNew;
	}
	return pStart;
}
void Karten_print(struCard* pStart) {
	for (struCard* pOutCard = pStart; pOutCard != NULL; pOutCard = pOutCard->pNext)
		printf("Auto: %-50s, LeistungPS = %i, Gewicht = %f, KgproPS = %f\n", pOutCard->Bez, pOutCard->LeistungPS, pOutCard->Gewicht, pOutCard->KgproPS);
}

int Karten_mischen() {



	return 0;
}



int Karten_vergleichen() {
	return 0;
}
struct Card Card;
