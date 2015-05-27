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

int& koniec();
int& element(int e);
int ile();

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
   *\brief Metoda klasy Ltab wypisz
   *
   *Wyswietla cala zawartosc listy
   */

    void wypisz();





/*! 
   *\brief Metoda klasy Ltab wypelnij_posortowane
   *
   *Metoda wypelnia tablice elementami od 1 do roz
   *
*/

void wypelnij_posortowane(const int roz);

/*! 
   *\brief Metoda klasy Ltab wypelnij_odwrotnie
   *
   *Metoda wypelnia tablice elementami od roz do 1
   *
*/

void wypelnij_odwrotnie(const int roz);

/*! 
   *\brief Metoda klasy Ltab wypelnij_losowymi
   *
   *Metoda wypelnia tablice losowymi elementami z zakresu od 0 do 999
   *
*/

void wypelnij_losowymi(const int roz);

/*! 
   *\brief Metoda klasy Ltab sortuj_QS_wst
   *
   *Metoda wypelnia sortuje elementy tablicy od najmniejszego do najwiekszego.
   *Wykorzystuje do tego w pierwszej kolejnosci metode dziel ktora dzieli elementy 
   *tablicy na dwie czesci i wstepnie je sortuje. Nastepnie dla wstepnie posortowanych
   *elementow wywolywana jest metoda sort_wst ktora ma zlozonosc linniowa dla elementow
   *czesciowo posortowanych.	
   *
*/

};

#endif
