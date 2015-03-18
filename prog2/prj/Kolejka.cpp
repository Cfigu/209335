#include "Kolejka.h"

using namespace std;

/*!
*\file
*\brief Plik Kolejka.cpp
*
*Zawiera definicje metod klasy Kolejka
*/

/*! 
   *\brief Konstruktor klasy Kolejka
   *
   *Tworzy pusta klase Kolejka
   */

Kolejka::Kolejka()
{
  poczatek = koniec = NULL;
}

/*! 
   *\brief Destruktor klasy Kolejka
   *
   *Kasuje klase Kolejka 
   */

Kolejka::~Kolejka()
{
  while(poczatek)
    {
    pop_k();
    }
}


/*! 
   *\brief Metoda klasy Kolejka empty_k
   *
   *Sprawdza czy kolejka jest pusta
   *
   *\return Zwraca true jesli kolejka jest pusta i false jesli nie
   */

bool Kolejka::empty_k(void)
{
  if(poczatek==NULL)
    {
      return true;
    }
  else
    {
  return false;
    }
}

/*! 
   *\brief Metoda klasy Kolejka push_k
   *
   *Dodaje element na koniec kolejki
   *
   *\param[in] v - taka bedzie wartosc dodanego elementu
   *
   */

void Kolejka::push_k(int v)
{
  Ekolejka * p = new Ekolejka;
  p->next = NULL;
  p->wartosc = v;
  if(koniec)
    {
      koniec->next = p;
    }
  else
    { 
      poczatek = p;
    }
  koniec = p;
}

/*! 
   *\brief Metoda klasy Kolejka pop_k
   *
   *Zabiera element z konca kolejki
   *
   */

void Kolejka::pop_k(void)
{
  if(poczatek)
  {
    Ekolejka * p = poczatek;
    poczatek = poczatek->next;
    if(!poczatek) koniec = NULL;
    delete p;
  }
}

