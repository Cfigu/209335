#include <iostream>
#include "metmain.cpp"
#include <ctime>

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
  int roz;
  Lista A;

  cout << "Wybierz co chcesz wypelnic:" << endl << endl;
  cout << "1.Lista zbudowana na strukturze" << endl;
  cout << "2.Lista zbudowana na tablicy z powiekszaniem o 1 element" << endl;
  cout << "3.Lista zbudowana na tablicy z powiekszaniem razy 2" << endl;
  cout << "0.Zakoncz program" << endl;
  cin >> opcja;
 
  
  switch(opcja)
    {
   
    case 0:
      break;
      
    case 1:
      
      cout << "Podaj rozmiar: " << endl;
      
      cin >> roz;
      
      ListaStruktura(roz, A);
      
      break;
      


    case 2:
      
      cout << "Podaj rozmiar: " << endl;
      
      cin >> roz;
 
      ListaZwieksz1(roz);
      
      break;
      
    case 3:

       cout << "Podaj rozmiar: " << endl;
      
       cin >> roz;

       ListaZwiekszX2(roz);

      break;
   
    }
}
    
  
      
