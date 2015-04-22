#include "ListaAr.h"
#include <ctime>


using namespace std;

/*!
*\file
*\brief Plik main.cpp
*
*Zawiera definicje metod klasy Ltab
*/

int main()
{
  int roz,opcja;
  Ltab A;
  clock_t czas1,czas2;
  double t;
  /*
  for(int i=roz; i>0; --i)
    A.addx2(i);
  */

  cout << "Podaj rozmiar tablicy:   " << endl;
  cin >> roz;
  int l=0;
  int p=roz-1;
  cout << endl << "Wybierz uklad danych:  " << endl;
  cout << "1. Elementy losowe." << endl;
  cout << "2. Elementy posortowane odwrotnie." << endl;
  cout << "3. Elementy posortowane. " << endl;
  cout << "Opcja:    ";
  cin >> opcja;
  cout << endl;


  switch(opcja)
    {
    case 1:
      
      A.wypelnij_losowymi(roz);
      
      if(roz==100)
	A.wypisz();
      
      cout << endl;
      
      czas1=clock();
      A.sort_hybr(l,p);
      czas2=clock();
      
      t = (double)(czas2-czas1)/CLOCKS_PER_SEC;
      cout << "Czas:  " << endl;
      cout << t << endl << endl;
      
      if(roz==100)
	A.wypisz();
      
      break;
      


    case 2:
      
      A.wypelnij_odwrotnie(roz);
      
      if(roz==100)
	A.wypisz();
      
      cout << endl;
      
      czas1=clock();
      A.sort_hybr(l,p);
      czas2=clock();
      
      t = (double)(czas2-czas1)/CLOCKS_PER_SEC;
      cout << "Czas:  " << endl;
      cout << t << endl << endl;
      
      if(roz==100)
	A.wypisz();

      break;
      

    case 3:

      A.wypelnij_posortowane(roz);
      
      if(roz==100)
	A.wypisz();
      
      cout << endl;
      
      czas1=clock();
      A.sort_hybr(l,p);
      czas2=clock();
      
      t = (double)(czas2-czas1)/CLOCKS_PER_SEC;
      cout << "Czas:  " << endl;
      cout << t << endl << endl;
      
      if(roz==100)
	A.wypisz();

      break;

    }
}






  
