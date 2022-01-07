
#include <stdio.h> //Befehle für die Standard Ein- und Ausgabe
#include <stdlib.h> //Funktionen zur Typumwandlung
#include <string.h> //Funktionen zur Verarbeitung von Zeichenketten
#include <time.h> 

typedef struct Card { //Definiton von struct Card
	int Nr;
	char Bez[100]; //Variable Definiert
	int LeistungPS; //Variable Definiert
	double Gewicht; //Variable Definiert
	struct Card* pNext; //Deklaration vom Pointer pNext
	
}struCard;

//Funktionen initialisieren
//int
int Stapel_zählen(struCard* pStart);
int Random_zahl(int anz);
//void
void Karten_ausgeben(struCard* pSpieler);
//struCard
struCard* KarteamEnde_hinzufuegen(struCard* pStart, struCard* entfernteKarte);
struCard* Karten_erstellen(int Nr, const char* pAuto, int LeistungPS, double Gewicht);
struCard* KartezuStapel(struCard* pStart, struCard* pNew);
struCard* Karten_zeiger(struCard* pStart);
struCard* Stapel_bearbeiten(struCard* pStart, struCard* pEinzKarte);
struCard* VordersteKarte_entfernen(struCard** pStart);
struCard* Karten_vergleichen(int eingabe, struCard** pSpieler, struCard** pComputer);



void main() { //main Funktion wird gestartet
	
	printf("+++++++++++++\n");
	printf("QUARTETT\n");
	printf("+++++++++++++\n");

	struCard* pStart = NULL;
	struCard* pEinzKarte = NULL;
	struCard* pSpieler = NULL;
	struCard* pComputer = NULL;
	srand(time(NULL));


	//Die einzelnen Karten werden erstellt über die Karten_erstellen funktion und werden über KartezuStapel verkettet
	pStart = KartezuStapel(pStart, Karten_erstellen(1,"Honda Civic Type R Competition Fn2 2007", 201, 1300));
	pStart = KartezuStapel(pStart, Karten_erstellen(2,"Mitsubishi Lancer EVO VI Tommi Makinen Edition 1999", 280, 1365));
	pStart = KartezuStapel(pStart, Karten_erstellen(3,"Nissan Skyline GT-R R34 1999", 290, 1560));
	pStart = KartezuStapel(pStart, Karten_erstellen(4,"Mazda RX-7 1992", 240, 1310));
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

	printf("Die Karten wurden gemischt und dir wurden 5 zuf\x84llige Karten zugeteilt...\n");
	Karten_ausgeben(pSpieler);


	while (pSpieler != NULL || pComputer != NULL)
	{
		int eingabe;
		
		printf("Welchen Wert willst du vergleichen?\tPS = 1 | Gewicht = 2 \n");
		scanf_s("%i", &eingabe);
		
		if (eingabe == 1)
		{
			Karten_vergleichen(eingabe, &pSpieler, &pComputer);
			Karten_ausgeben(pSpieler);
			printf("\n");
			Karten_ausgeben(pComputer);
		}

		else if (eingabe == 2)
		{

		}

		else
		{
			printf("Falsche Eingabe");
		}


	}


	system("pause"); //Programm wird pausiert
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

/// <summary>
/// Zählt wie viele Karten im Stapel vorhanden sind, welcher mitgegeben wird.
/// </summary>
/// <param name="pStart"></param>
/// <returns>Gibt die Anzahl zurück</returns>
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

/// <summary>
/// Gibt eine Random Zahl zurück
/// </summary>
/// <param name="anz"></param>
/// <returns></returns>
int Random_zahl(int anz)
{
	int random = rand() % anz;

	return random;
}

/// <summary>
/// Wählt über die Random_zahl funktion eine beliebige Karte vom Stapel auf und gibt die einzelne Karte zurück
/// </summary>
/// <param name="pStart"></param>
/// <returns></returns>
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

/// <summary>
///	
/// </summary>
/// <param name="pStart"></param>
/// <param name="pEinzKarte"></param>
/// <returns>pStart</returns>
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

/// <summary>
/// Gibt das mitgegebene Karten-Set aus
/// </summary>
/// <param name="pStapel"></param>
void Karten_ausgeben(struCard* pStapel)
{
	if (pStapel == NULL)
		return;

	do
	{
		printf("%s\t %i\t %0.1lf\t \n", pStapel->Bez, pStapel->LeistungPS, pStapel->Gewicht);
		pStapel = pStapel->pNext;

	} while (pStapel != NULL);
}

/// <summary>
/// entfernt die vorderste Karte des per parameter übergebenen Stapel
/// </summary>
/// <param name="pStart">Stapel aus dem eine Karte entfernt werden soll</param>
/// <returns>Die Adresse der entfernten Karte</returns>
struCard* VordersteKarte_entfernen(struCard** pStapel)
{
	struCard* pTemp = *pStapel;
	*pStapel = pTemp->pNext;
	pTemp->pNext = NULL;
	return pTemp;
}

/// <summary>
/// fügt die mitgegebene Karte am Ende des Stapels hinzu
/// </summary>
/// <param name="pStart"></param>
/// <param name="entfernteKarte"></param>
struCard* KarteamEnde_hinzufuegen(struCard* pStapel, struCard* neueKarte)
{
	neueKarte->pNext = NULL;
	if (pStapel != NULL) 
	{
		struCard* pLastCard = pStapel;
		while (pLastCard->pNext != NULL) pLastCard = pLastCard->pNext;
		pLastCard->pNext = neueKarte;
	}
	else pStapel = neueKarte;
	return pStapel;
}

/// <summary>
/// 
/// </summary>
/// <param name="eingabe"></param>
/// <param name="pSpieler"></param>
/// <param name="pComputer"></param>
/// <returns></returns>
struCard* Karten_vergleichen(int eingabe, struCard** pSpieler, struCard** pComputer) 
{

	struCard* pPlayer = *pSpieler;
	struCard* pCpu = *pComputer;

	if (eingabe == 1)
	{
		if (pPlayer->LeistungPS < pCpu->LeistungPS)
		{
			printf("Computer hat gewonnen\n");
			struCard* entfernteKarte = VordersteKarte_entfernen(&pPlayer);
			pCpu = KarteamEnde_hinzufuegen(pCpu, entfernteKarte);
		}

		else if (pPlayer->LeistungPS > pCpu->LeistungPS)
		{
			printf("Spieler hat gewonnen\n");
			struCard* entfernteKarte = VordersteKarte_entfernen(&pCpu);
			pPlayer = KarteamEnde_hinzufuegen(pPlayer, entfernteKarte);
		}

	}

	else if (eingabe == 2)
	{

	}


	return pPlayer, pCpu;

}

