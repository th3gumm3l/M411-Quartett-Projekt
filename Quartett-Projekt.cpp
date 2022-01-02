
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Card {
	int Nr;
	char Bez[100];
	int LeistungPS;
	double Gewicht;
	struct Card* pNext;
	
}struCard;

int Stapel_zählen(struCard* pStart);
int Random_zahl(int anz);

struCard* Karten_erstellen(int Nr, const char* pAuto, int LeistungPS, double Gewicht);
struCard* KartezuStapel(struCard* pStart, struCard* pNew);
struCard* Karten_zeiger(struCard* pStart);

struCard* Stapel_bearbeiten(struCard* pStart, struCard* pEinzKarte);
struCard* Karten_vergleichen();


void main() {
	
	printf("+++++++++++++\n");
	printf("QUARTETT\n");
	printf("+++++++++++++\n");

	struCard* pStart = NULL;
	struCard* pEinzKarte = NULL;
	struCard* pSpieler = NULL;
	struCard* pComputer = NULL;


	srand(time(NULL));

	pStart = KartezuStapel(pStart, Karten_erstellen(1,"Honda Civic Type R Competition Fn2 2007", 201, 1300));
	pStart = KartezuStapel(pStart, Karten_erstellen(2,"Mitsubishi Lancer EVO VI Tommi Makinen Edition 1999", 280, 1365));
	pStart = KartezuStapel(pStart, Karten_erstellen(3,"Nissan Skyline GT-R R34 1999", 280, 1560));
	pStart = KartezuStapel(pStart, Karten_erstellen(4,"Mazda RX-7 1992", 240, 1300));
	pStart = KartezuStapel(pStart, Karten_erstellen(5,"Mazda Miata mx 5 1990", 115, 995));
	pStart = KartezuStapel(pStart, Karten_erstellen(6,"Mazda 3 MPS 2011", 260, 1460));
	pStart = KartezuStapel(pStart, Karten_erstellen(7,"Toyota Supra Mk4 1997", 330, 1585));
	pStart = KartezuStapel(pStart, Karten_erstellen(8,"Toyota Gt86 2012", 200, 1305));
	pStart = KartezuStapel(pStart, Karten_erstellen(9,"Nissan GTR Nismo R35 2019", 600, 1725));
	pStart = KartezuStapel(pStart, Karten_erstellen(10,"Saab 9-5 2.3 Turbo Performance 2003", 305, 1610));

	for (int i = 1; i <= 5; i++) //Karten mischen, verteilen und entfernen aus dem Stapel
	{
		pEinzKarte = Karten_zeiger(pStart);
		pStart = Stapel_bearbeiten(pStart, pEinzKarte);
		pSpieler = KartezuStapel(pSpieler, pEinzKarte);
		pEinzKarte = Karten_zeiger(pStart);
		pStart = Stapel_bearbeiten(pStart, pEinzKarte);
		pComputer = KartezuStapel(pComputer, pEinzKarte);
	}


	system("pause");
}


struCard* Karten_erstellen(int Nr, const char* pBez, int LeistungPS, double Gewicht) {
	
	struCard* pTemporaerKarte = (struCard*)malloc(sizeof(struCard));
	
	pTemporaerKarte -> Nr = Nr;
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


int Stapel_zählen(struCard* pStart)
{
	int anz = 0;
	struCard* pTmp = pStart;
	for (pTmp; pTmp != NULL; pTmp = pTmp->pNext)
	{
		anz++;
	}
	
	return anz;
}


int Random_zahl(int anz)
{
	int random = rand() % anz;

	return random;
}


struCard* Karten_zeiger(struCard* pStart)
{
	int zähler = Stapel_zählen(pStart);
	int random_zahl = Random_zahl(zähler);
	struCard* pStapel = pStart;

	if (zähler > 0) 
	{
		for (int i = 0; pStapel != NULL && i != random_zahl; i++) 
		{
			pStapel = pStapel->pNext;
		}

	}

	return pStapel;
}


struCard* Stapel_bearbeiten(struCard* pStart, struCard* pEinzKarte)
{
	if (pEinzKarte == pStart)
	{
		pStart = pEinzKarte->pNext;
	}

	
	else
  {
    struCard* pVorherige = pStart;
  
		while (pVorherige->pNext != pEinzKarte)
    {
      pVorherige = pVorherige->pNext;
    }

    pVorherige->pNext = pEinzKarte->pNext;
  
	}
  
	pEinzKarte->pNext = NULL;

  return pStart;
}

struCard* Karten_vergleichen()
{
	   


	return 0;
}
