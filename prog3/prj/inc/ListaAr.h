#ifndef LISTAAR_H
#define LISTAAR_H

#include <iostream>

/*!
*\file
*\brief Plik naglowkowy ListaAr.h
*
*Zawiera klase Ltab i jej metody
*/

using namespace std;

/*!
 *\brief Modeluje pojecie klasy Ltab
 *
 *Klasa Ltab zawiera prywatnie ilosc elementow w tablicy, maksynalna ilosc elementow w tablicy oraz element
*Publicznie zawieraz wszystkie metody, przeciazenia operatorow oraz konstruktor i destruktor.	
*/

class Ltab
{
  private:
    int *tab;
    int ilosc, max; 
  public:

/*! 
   *\brief Konstruktor klasy Ltab
   *
   *Tworzy pusta klase Ltab
   */

    Ltab();

/*! 
   *\brief Konstruktor kopjujacy klasy Ltab
   *
   *Kopjuje cala list
   *
   *\return Zwraca klase Ltab
   */

    Ltab(const Ltab & w); 

/*! 
   *\brief Destruktor klasy Ltab
   *
   *Kasuje cala klase
   *
   */

    ~Ltab();

/*! 
   *\brief Przeciazenie operatora = dla klasy Ltab
   *
   *Przypisuje wartosci jednej listy do drugiej
   */

    Ltab& operator=(const Ltab &w);

/*! 
   *\brief Przeciazenie operatora [] dla klasy Ltab
   *
   *Pozwala na odwolanie sie do elementu tablicy
   */

    int& operator[](unsigned int index);

/*! 
   *\brief Metoda klasy Ltab add
   *
   *Dodaje element do listy zwiekszajac jej rozmiar o 1
   *
   *\param[in] wart - taka bedzie wartosc dodanego elementu
   */

    void add(const int &wart);

/*! 
   *\brief Metoda klasy Ltab addx2
   *
   *Dodaje element na szczyt listy jesli jest jeszcze miejsce w tablicy.
   * Jesli nie to zwieksza rozmiar tablicy razy 2 a potem dodaje element
   *
   *\param[in] wart - taka bedzie wartosc dodanego elementu
   */

    void addx2(const int& wart);

/*! 
   *\brief Metoda klasy Lista wypisz
   *
   *Wyswietla cala zawartosc listy
   */

    void wypisz();
};

#endif
