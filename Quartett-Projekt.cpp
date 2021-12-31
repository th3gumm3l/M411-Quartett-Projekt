
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Card {
	char Bez[100];
	int LeistungPS;
	double Gewicht;
	struct Card* pNext;
	
}struCard;


struCard* Karten_erstellen(const char* pAuto, int LeistungPS, double Gewicht, double KgproPS);
struCard* KartezuStapel(struCard* pStart, struCard* pNew);
struCard* Karten_mischen();
struCard* Karten_verteilen();
struCard* Karten_vergleichen();
struCard* Karten_neuverteilen();



void main() {
	
	printf("-----------------\n");
	printf("QUARTETT\n");
	printf("-----------------\n");

	struCard* pStart = NULL;

	pStart = KartezuStapel(pStart, Karten_erstellen("Honda Civic Type R Competition Fn2 2007", 201, 1300));
	pStart = KartezuStapel(pStart, Karten_erstellen("Mitsubishi Lancer EVO VI Tommi Makinen Edition 1999", 280, 1365));
	pStart = KartezuStapel(pStart, Karten_erstellen("Nissan Skyline GT-R R34 1999", 280, 1560));
	pStart = KartezuStapel(pStart, Karten_erstellen("Mazda RX-7 1992", 240, 1300));
	pStart = KartezuStapel(pStart, Karten_erstellen("Mazda Miata mx 5 1990", 115, 995));
	pStart = KartezuStapel(pStart, Karten_erstellen("Mazda 3 MPS 2011", 260, 1460));
	pStart = KartezuStapel(pStart, Karten_erstellen("Toyota Supra Mk4 1997", 330, 1585));
	pStart = KartezuStapel(pStart, Karten_erstellen("Toyota Gt86 2012", 200, 1305));
	pStart = KartezuStapel(pStart, Karten_erstellen("Nissan GTR Nismo R35 2019", 600, 1725));
	pStart = KartezuStapel(pStart, Karten_erstellen("Saab 9-5 2.3 Turbo Performance 2003", 305, 1610));
	

	system("pause");
}


struCard* Karten_erstellen(const char* pBez, int LeistungPS, double Gewicht) {
	
	struCard* pTemporaerKarte = (struCard*)malloc(sizeof(struCard));
	
	strcpy_s(pTemporaerKarte -> Bez, pBez);
	
	pTemporaerKarte -> LeistungPS = LeistungPS;
	pTemporaerKarte -> Gewicht = Gewicht;
	pTemporaerKarte -> pNext = NULL;
	
	return pTemporaerKarte;
}


struCard* KartezuStapel(struCard* pStart, struCard* pNew) {
	
	if (pStart == NULL) 
	{
		pStart = pNew;
	}

	else 
	{
		struCard* pLast = pStart;
		
		while (pLast->pNext != NULL) 
		{
			pLast = pLast->pNext;
		} 
		
		pLast->pNext = pNew;
	}
		
	return pStart;
}


struCard* Karten_mischen() 
{

}


struCard* Karten_verteilen()
{

}

struCard* Karten_vergleichen()
{

}

struCard* Karten_neuverteilen()
{

}
