#ifndef ASOTAB_H
#define ASOTAB_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Lista.h"

using namespace std;

/*!
*\file
*\brief Plik naglowkowy AsoTab.h
*
*Zawiera definicje klasy Aso oraz jej metody
*/



/*!
 *\brief Modeluje pojecie klasy Aso
 *
 *Klasa Aso zawiera Liste
*Publicznie zawieraz wszystkie metody, konstruktor i destruktor.
*/

class Aso{
  Lista L;

 public:

/*! 
   *\brief Konstruktor klasy Aso
   *
   *Tworzy pusta klase Aso
   */

  Aso();

/*! 
   *\brief Destruktor klasy Aso
   *
   *Nie robi w sumie nic
   *
   */

  ~Aso();

/*! 
   *\brief Metoda klasy Aso hash
   *
   *Przypisuje wartosc do klucza na podstawie operacji matematycznych i kodu ASCII
   *\param[in] e - haszowany klucz
   *\return Zwaraca wartosc odpowiadajaca kluczowi
   */

  int hash(string e);

/*! 
   *\brief Metoda klasy Aso add
   *
   *Dodaje element do klasy. Wewnatrz zawiera metode hash
   *
   *\param[in] e - dodawany klucz
   */

  void add(string e);

/*! 
   *\brief Metoda klasy Aso wys
   *
   *Wyswietla cala zawartosc klasy
   */

  void wys();

 /*! 
   *\brief Metoda klasy Aso find
   *
   *Szuka elementu na podstawie klucza key
   *\param[in] e - klucz
   *\return Zwraca wartosc odpowiadajaca kluczowi 
   */

  int find(string e);
/*! 
   *\brief Przeciazenie operatora []
   *
   *Pozwala na odwolywanie sie do elementow klasy poprzez wpisanie w [] klucza
   *Wykorzystuje metode find
   *\return Zwraca wartosc odpowiadajaca kluczowi
   */
  int operator[](string k);

void wczyt(string nazwa, int roz);
};


#endif
