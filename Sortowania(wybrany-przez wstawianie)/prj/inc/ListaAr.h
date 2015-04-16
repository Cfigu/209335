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
    long int *tab;
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

    long int& operator[](unsigned int index);

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
   *\brief Metoda klasy Ltab sort_wst
   *
   *Sortuje elementy listy od najmniejszego do największego
   *Zlozonosc algorytmu to O(n^2) dla samego algorytmu sortowania,
   *gdzie n to ilosc elementow do posortowania, ale występuje
   *tam rownierz kopjowanie calej zawartosci tablicy. 
   *
   *  TABELA CZASOW
   *
   *   n      czas[s]
   *  100      0,000039
   *  1000     0,003291
   *  10000    0,016735
   *  100000  15,6825
   */
    void sort_wst();	


//QS przerobiony z tego robionego pod program kolegi na dzialajacy na moim
int dziel(int lewo, int prawo);
int dziel2(int lewo, int prawo);
void sortuj(int lewo,int prawo);
//sortuj_opt poki co nie dziala
void sortuj_opt(int lewo, int prawo);

};

#endif
