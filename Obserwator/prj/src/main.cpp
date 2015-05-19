#include "Benchmark.h"


using namespace std;

/*!
*\file
*\brief Plik main.cpp
*
*Zawiera program glowny.
*Program pyta sie o rozmiar listy oraz jaki ma byc jej
*poczatkowy sposob wypelnienia. Nastepnie sortuje liste, 
*oraz przy pomocy obserwatorw pokazuje czas sortowania.
*/

int main()
{
  //Deklaracje
  int roz,opcja;
  Ltab A;
  Obserwator * pac = new Obserwator();
  Dane* d1 = new PobieraczDanych();
  Dane* d2 = new PobieraczDanych();
  pac->dodaj(d1);
  pac->dodaj(d2);
 
  //Menu wybierania opcji i rozmiaru listy
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

  //Switch w zaleznosci od opcji
  switch(opcja)
    {
    case 1:
      
      A.wypelnij_losowymi(roz);
      
      if(roz==100)
	A.wypisz();
      
      cout << endl;
      
       A = pac->Benchmark(A,l,p);
      
      
      if(roz==100)
	A.wypisz();
      
    
     

      break;
      


    case 2:
      
      A.wypelnij_odwrotnie(roz);
      
      if(roz==100)
	A.wypisz();
      
      cout << endl;
      
       A = pac->Benchmark(A,l,p);
      
      if(roz==100)
	A.wypisz();

      break;
      

    case 3:

      A.wypelnij_posortowane(roz);
      
      if(roz==100)
	A.wypisz();
      
      cout << endl;
      
      A= pac->Benchmark(A,l,p);
      
      if(roz==100)
	A.wypisz();

      break;

    }
}






  
