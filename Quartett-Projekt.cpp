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

  struct Card Card;

  




  system("pause");
  return 0;
}