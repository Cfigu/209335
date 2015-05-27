#include "Kolejka.h"

using namespace std;

/*!
*\file
*\brief Plik Kolejka.cpp
*
*Zawiera definicje metod klasy Kolejka
*/



Kolejka::Kolejka()
{
  poczatek = koniec = NULL;
}



Kolejka::~Kolejka()
{
  while(poczatek)
    {
    pop_k();
    }
}



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

int Kolejka::front()
{
  return poczatek->wartosc;
}

