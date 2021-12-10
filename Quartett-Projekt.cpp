#include <stdio.h>
#include <stdlib.h>

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


int main() {
	
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
  struct Card Card;
  




  system("pause");
  return 0;
}