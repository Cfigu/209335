#include "ListaAr.h"

using namespace std;

/*!
*\file
*\brief Plik ListaAr.cpp
*
*Zawiera definicje metod klasy Ltab
*/

/*! 
   *\brief Konstruktor klasy Ltab
   *
   *Tworzy pusta klase Ltab
   */

Ltab::Ltab()
{
  ilosc=0;
  max=0;
  tab=NULL;
}

/*! 
   *\brief Destruktor klasy Ltab
   *
   *Kasuje cala klase
   *
   */

Ltab::~Ltab()
{
  if(tab)
    delete [] tab;
}

/*! 
   *\brief Metoda klasy Ltab add
   *
   *Dodaje element do listy zwiekszajac jej rozmiar o 1
   *
   *\param[in] wart - taka bedzie wartosc dodanego elementu
   */

void Ltab::add(const int& wart)
{
  int* pom;
  ilosc=ilosc+1;
  pom=new int[ilosc];

  if(tab)
  {
    for(int i=0; i<ilosc-1; i++)
      pom[i]= tab[i];
  }

  pom[ilosc-1]=wart;
  max=ilosc-1;
  if(tab)
    delete tab;

  tab=pom;
}

/*! 
   *\brief Metoda klasy Ltab addx2
   *
   *Dodaje element na szczyt listy jesli jest jeszcze miejsce w tablicy.
   * Jesli nie to zwieksza rozmiar tablicy razy 2 a potem dodaje element
   *
   *\param[in] wart - taka bedzie wartosc dodanego elementu
   */

void Ltab::addx2(const int& wart)
{
  if(max<ilosc)
    {
      tab[max] = wart;
    }
  else
    {
      ilosc = ilosc*2;
      int* pom = new int[ilosc];
      for(int i=0; i<max; i++){
	pom[i] = tab[i];
      }

      delete [] tab;
  
      tab = pom;
 
      tab[max] = wart;
    }
  max++;
}

/*! 
   *\brief Konstruktor kopjujacy klasy Ltab
   *
   *Kopjuje cala list
   *
   *\return Zwraca klase Ltab
   */

Ltab::Ltab(const Ltab & w)
{
  tab = new int [w.ilosc];
  for(int i=0; i<w.ilosc; i++)
    tab[i]=w.tab[i];
  ilosc= w.ilosc;
  max=w.max;
}

/*! 
   *\brief Metoda klasy Lista wypisz
   *
   *Wyswietla cala zawartosc listy
   */

void Ltab::wypisz()
{
  for(int i=0; i < ilosc; i++)
    cout << tab[i] << endl;
}

/*! 
   *\brief Przeciazenie operatora = dla klasy Ltab
   *
   *Przypisuje wartosci jednej listy do drugiej
   */

Ltab& Ltab::operator=(const Ltab & w)
{
  ilosc=w.ilosc;
  max=w.max;

  for(int i=0; i<w.ilosc; ++i)
    tab[i]=w.tab[i];
  return *this;
}

/*! 
   *\brief Przeciazenie operatora [] dla klasy Ltab
   *
   *Pozwala na odwolanie sie do elementu tablicy
   */

int& Ltab::operator[](unsigned int index)
{
  return tab[index];
}
