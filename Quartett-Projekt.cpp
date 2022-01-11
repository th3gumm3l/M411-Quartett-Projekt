//Code written by: Tim Bernhard (Git: th3gummel)
//Commentarys written by: Simon Gerhard (Git: Simondj9)
//(Commits and pushs)Bearbeitungen und Uploads der einzeln Mitglieder können über Github hier verfolgt werden: https://github.com/th3gumm3l/M411-Quartett-Projekt


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
void Karten_ausgeben(const char* pTitel, struCard* pSpieler);
void Karten_vergleichen(int eingabe, struCard** pSpieler, struCard** pComputer);

//struCard
struCard* Karten_erstellen(int Nr, const char* pAuto, int LeistungPS, double Gewicht);
struCard* KartezuStapel(struCard* pStart, struCard* pNew);
struCard* Karten_zeiger(struCard* pStart);
struCard* KarteamEnde_hinzufuegen(struCard* pStart, struCard* entfernteKarte);
struCard* Stapel_bearbeiten(struCard* pStart, struCard* pEinzKarte);
struCard* VordersteKarte_entfernen(struCard** pStart);



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
	
	//Karten mischen, verteilen und entfernen aus dem Stapel
	for (int i = 1; i <= 5; i++) 
	{
		pEinzKarte = Karten_zeiger(pStart);
		pStart = Stapel_bearbeiten(pStart, pEinzKarte);
		pSpieler = KartezuStapel(pSpieler, pEinzKarte);

		pEinzKarte = Karten_zeiger(pStart);
		pStart = Stapel_bearbeiten(pStart, pEinzKarte);
		pComputer = KartezuStapel(pComputer, pEinzKarte);
	}

	printf("Die Karten wurden gemischt und dir wurden 5 zuf\x84llige Karten zugeteilt...\n\n\n");
	Karten_ausgeben("Deine Karten:", pSpieler);

	system("pause"); //Pausiert die Applikation


	//Spiel wird hier hauptsächlich durchgeführt
	while (pSpieler != NULL && pComputer != NULL)// Solange das Kartenset beider Spieler nicht NULL ist, wird die Schleife ausgeführt
	{
		int eingabe;
		
		system("cls"); //cls --> Clear Screen, löscht den inhalt oberhalb dieser Zeile im Terminal

		printf("Aktuelle Karte:\n\n%-60s\t %i\t %9.1lf\t \n\n", pSpieler->Bez, pSpieler->LeistungPS, pSpieler->Gewicht);
		
		int SpielerAnz = Stapel_zählen(pSpieler); //Liest jedesmal die Anzahl des Stapels des Spielers aus
		int CompAnz = Stapel_zählen(pComputer); //Liest jedesmal die Anzahl des Stapels des Computers aus
		
		printf("Du hast %i Karten\n", SpielerAnz);
		printf("Der Computer hat noch %i Karten\n\n", CompAnz);

		printf("Welchen Wert willst du vergleichen?\tPS = 1 | Gewicht = 2 \n");
		scanf_s("%i", &eingabe);
		
		//Leitet zum Vergleich weiter
		if (eingabe == 1)
		{
			Karten_vergleichen(eingabe, &pSpieler, &pComputer);
			printf("\n");
		}

		else if (eingabe == 2)
		{
			Karten_vergleichen(eingabe, &pSpieler, &pComputer);
			printf("\n");
		}

		else //ungültige Eingabe
		{
			printf("Falsche Eingabe");
		}

		system("pause");
	}

	system("cls");


	//Entscheidet wer gewonnen hat
	if (pSpieler == NULL)
	{
		printf("Der Computer hat dich besiegt\n\n\n");
	}

	else if (pComputer == NULL)
	{
		printf("Der Spieler hat den Computer besiegt\n\n\n");
	}

	else
	{
		printf("Das Spiel wurde gehackt\n");
	}



	//Programm wird hier beendet
	system("pause");

}

/// <summary>
/// Zählt wie viele Karten im Stapel vorhanden sind von denjenigem der mitgegeben wird.
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
/// Definiert eine zufällige Zahl aus der Anzahl
/// </summary>
/// <param name="anz">Anzahl gezählte Karten</param>
/// <returns>Gibt eine Random Zahl zurück</returns>
int Random_zahl(int anz)
{
	int random = rand() % anz;

	return random;
}

/// <summary>
/// Die Karten werden hier miteinander je nach Benutzereingabe verglichen. Die benutzte Karte wird hier dann auch nach unten verschoben
/// </summary>
/// <param name="eingabe">Benutzereingabe für den Entscheid des Vergleichs</param>
/// <param name="pSpieler">aktueller Stapel des Spielers</param>
/// <param name="pComputer">aktueller Stapel des Computers</param>
/// <returns>Gibt keine Werte zurück</returns>
void Karten_vergleichen(int eingabe, struCard** pSpieler, struCard** pComputer) 
{

	struCard* pPlayer = *pSpieler;
	struCard* pCpu = *pComputer;

	if (eingabe == 1)
	{
		if (pPlayer->LeistungPS < pCpu->LeistungPS)
		{
			system("cls");
			printf("\nComputer hat gewonnen\n\n");
			
			struCard* entfernteKarteP = VordersteKarte_entfernen(&pPlayer); //Dem Player wird die vorderste Karte entfernt
			pCpu = KarteamEnde_hinzufuegen(pCpu, entfernteKarteP); //Die entfernte Karte wird dem Stapel vom Computer hinzugefügt

			struCard* entfernteKarteC = VordersteKarte_entfernen(&pCpu);	//Dem Computer wird die vorderste Karte entfernt, weil sonst immer die gleiche zu oberst ist
			pCpu = KarteamEnde_hinzufuegen(pCpu, entfernteKarteC); //Die Karte wird beim Computer nach hinten geschoben
		}

		else if (pPlayer->LeistungPS > pCpu->LeistungPS)
		{
			system("cls");
			printf("\nDu hast gewonnen\n\n");

			struCard* entfernteKarteC = VordersteKarte_entfernen(&pCpu); //Dem Computer wird die vorderste Karte entfernt
			pPlayer = KarteamEnde_hinzufuegen(pPlayer, entfernteKarteC); //Die entfernte Karte wird dem Stapel vom Player hinzugefügt

			struCard* entfernteKarteP = VordersteKarte_entfernen(&pPlayer); //Dem Spieler wird die vorderste Karte entfernt, weil sonst immer die gleiche zu oberst ist
			pPlayer = KarteamEnde_hinzufuegen(pPlayer, entfernteKarteP); //Die Karte wird beim Spieler nach hinten geschoben
		}

	}

	//Hier passiert das gleiche wie oben, einfach ist die Eingabe hier 2 und nicht 1
	else if (eingabe == 2)
	{
		if (pPlayer->Gewicht > pCpu->Gewicht)
		{
			system("cls");
			printf("\nComputer hat gewonnen\n\n");
			struCard* entfernteKarteP = VordersteKarte_entfernen(&pPlayer);
			pCpu = KarteamEnde_hinzufuegen(pCpu, entfernteKarteP);

			struCard* entfernteKarteC = VordersteKarte_entfernen(&pCpu);
			pCpu = KarteamEnde_hinzufuegen(pCpu, entfernteKarteC);
		}

		else if (pPlayer->Gewicht < pCpu->Gewicht)
		{
			system("cls");
			printf("\nDu hast gewonnen\n\n");
			struCard* entfernteKarteC = VordersteKarte_entfernen(&pCpu);
			pPlayer = KarteamEnde_hinzufuegen(pPlayer, entfernteKarteC);

			struCard* entfernteKarteP = VordersteKarte_entfernen(&pPlayer);
			pPlayer = KarteamEnde_hinzufuegen(pPlayer, entfernteKarteP);
		}

	}


	*pSpieler = pPlayer;
	*pComputer = pCpu;

}

/// <summary>
/// Gibt das mitgegebene Stapel-Set aus, solange der pNext im Stapel nicht auf NULL zeigt
/// </summary>
/// <param name="pTitel">Definiert noch einen beliebigen Text</param>
/// <param name="pStapel">Der mitgegebene Stapel</param>
void Karten_ausgeben(const char* pTitel, struCard* pStapel)
{
	printf(pTitel); printf("\n");
	if (pStapel == NULL)
		return;
	do
	{
		printf("%-60s\t %i\t %9.1lf\t \n", pStapel->Bez, pStapel->LeistungPS, pStapel->Gewicht);
		pStapel = pStapel->pNext;

	} while (pStapel != NULL);
}

/// <summary>
/// Hier werden die einzelnen Karten erstellt und ihre Werte beschrieben
/// </summary>
/// <param name="Nr">Dient zur identifizierung bei der Fehleranalyse</param>
/// <param name="pBez">Ist die Bezeichnung der einzelnen Karte</param>
/// <param name="LeistungPS">Ist die Leistung des Autos auf der Karte</param>
/// <param name="Gewicht">Ist das Gewicht des Autos auf der Karte</param>
/// <returns>Gibt jeweils die einzelne Karte zurück</returns>
struCard* Karten_erstellen(int Nr, const char* pBez, int LeistungPS, double Gewicht) {
	
	struCard* pTemporaerKarte = (struCard*)malloc(sizeof(struCard)); //Reserviert jeweils den Speicher für die Karte nach der exakten Grösse einer solchen Karte
	
	pTemporaerKarte -> Nr = Nr;
	strcpy_s(pTemporaerKarte -> Bez, pBez); //Kopiert das Char-Array
	pTemporaerKarte -> LeistungPS = LeistungPS;
	pTemporaerKarte -> Gewicht = Gewicht;
	pTemporaerKarte -> pNext = NULL; //Definiert einen zeiger und setzt ihn auf NULL
	
	return pTemporaerKarte;
}

/// <summary>
/// Der mitgegebene Stapel wird hier verkettet und danach zurückgegeben
/// </summary>
/// <param name="pStart"></param>
/// <param name="pNew">Ist die einzelne Karte</param>
/// <returns>Gibt den verketteten Stapel zurück</returns>
struCard* KartezuStapel(struCard* pStart, struCard* pNew) {
	
	if (pStart == NULL) 
	{
		pStart = pNew; //Erste Karte wird hier als erste definiert
	}

	else 
	{
		struCard* pLast = pStart;
		
		while (pLast->pNext != NULL)  //wird solange ausgeführt bis pNext auf NULL zeigt und die letzte Karte erreicht wurde
		{
			pLast = pLast->pNext;
		} 
		
		pLast->pNext = pNew; //setzt die letzte Karte
	}
		
	return pStart;
}

/// <summary>
/// Wählt über die Random_zahl funktion eine beliebige Karte vom Stapel auf und gibt die einzelne Karte zurück
/// </summary>
/// <param name="pStart">Ist der mitgegebene Stapel</param>
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
///	Hier werden die Karten im Stapel neuverbunden
/// </summary>
/// <param name="pStart">mitgegebener Stapel</param>
/// <param name="pEinzKarte">einzelne aus der Karten_zeiger funktion ausgewählte Karte</param>
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
/// fügt die mitgegebene Karte am Ende des mitgegebenen Stapels hinzu
/// </summary>
/// <param name="pStapel">mitgegebener Stapel</param>
/// <param name="neueKarte">Ist die Karte welche am Ende hinzugefügt werden soll</param>
/// <returns>pStapel</returns>
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

