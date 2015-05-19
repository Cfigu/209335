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

/*! 
   *\brief Metoda klasy Ltab dziel
   *
   *Dzieli tablice na 2 czesci. Metoda wykorzystywana w metodzie sotrtuj
   *\return Zwraca punkt podzialu tablicy
   *QS przerobiony z tego robionego pod program kolegi na dzialajacy na moim
*/

int dziel(int lewo, int prawo);

/*! 
   *\brief Metoda klasy Ltab dziel2
   *
   *Dzieli tablice na 2 czesci. Metoda wykorzystywana w metodzie sotrtuj_opt
   *\return Zwraca punkt podzialu tablicy
   *QS przerobiony z tego robionego pod program kolegi na dzialajacy na moim
*/

int dziel2(int lewo, int prawo);

/*! 
   *\brief Metoda klasy Ltab sortuj
   *
   *Metoda sortuje elementy tablicy od najmniejsego do najwiekszego. Jest to algorytm QS
   *
   *QS przerobiony z tego robionego pod program kolegi na dzialajacy na moim
*/

void sortuj(int lewo,int prawo);

/*! 
   *\brief Metoda klasy Ltab sortuj_opt
   *
   *Metoda sortuje elementy tablicy od najmniejsego do najwiekszego.
   *Jest to algorytm QS z optymalizacja. Optymalizacja polega na doborze pivota.
   *Jest on wybierany jako mediana 3 elementow - pierwszego, srodkowego i ostatniego.
   *
   *QS przerobiony z tego robionego pod program kolegi na dzialajacy na moim
*/

void sortuj_opt(int lewo, int prawo);


/*! 
   *\brief Metoda klasy Ltab sort_scal
   *
   *Metoda scala dwie czesci tablicy w jedna
   *
*/


void sort_scal(int lewo, int prawo);

/*! 
   *\brief Metoda klasy Ltab scal
   *
   *Metoda sortuje elementy tablicy od najmniejsego do najwiekszego.
   *Wykorzystuje algorytm scalania(merge)
   *
*/

void scal(int lewo, int srodek, int prawo); 

/*! 
   *\brief Metoda klasy Ltab sort_hybr
   *
   *Metoda sortuje elementy tablicy od najmniejsego do najwiekszego.
   *
   *Metoda ta wykorzystuje metode dziel oraz metode sort_wst
   *
*/

void sort_hybr(int lewo,int prawo);

/*! 
   *\brief Metoda klasy Ltab wypelnij_posortowane
   *
   *Metoda wypelnia tablice elementami od 1 do roz
   *
*/

void wypelnij_posortowane(int roz);

/*! 
   *\brief Metoda klasy Ltab wypelnij_odwrotnie
   *
   *Metoda wypelnia tablice elementami od roz do 1
   *
*/

void wypelnij_odwrotnie(int roz);

/*! 
   *\brief Metoda klasy Ltab wypelnij_losowymi
   *
   *Metoda wypelnia tablice losowymi elementami z zakresu od 0 do 999
   *
*/

void wypelnij_losowymi(int roz);

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

void sortuj_QS_wst(int lewo, int prawo);
};

#endif
