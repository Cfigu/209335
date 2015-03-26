#include<iostream>
#include<ctime>
#include<cstdio>
#include "metmain.h"

using namespace std;

/*!
*\file
*\brief Program oblicza sredni czas tworzenia wybranej struktury danych
*
*Uzytkownik wybiera jaka strukture chce wypelnic i jaka iloscia elementow.
*Program wykonuje polecenia 10 razy, oblicza czas kazdego z nich, a nastepnie oblicza czas sredni.
*/

int main() {

  int opcja=0;
  Lista A;
  Kolejka K;
  Stos S;



  cout << "Wybierz jaka strkture chcesz wypelnic:" << endl << endl;
  cout << "1.Lista" << endl;
  cout << "2.Kolejka" << endl;
  cout << "3.Stos" << endl;
  cout << "0.Zakoncz program" << endl;
  cin >> opcja;
 
  
  switch(opcja)
    {
   
    case 0:
      break;
      
    case 1:
     
      WypListe(A);

      break;
  
    case 2:

      WypKolejke(K);

      break;

    case 3:

      WypStos(S);

      break;

    }
}
    
  
      
