#include "ListaAr.h"

using namespace std;

/*!
*\file
*\brief Plik ListaAr.cpp
*
*Zawiera definicje metod klasy Ltab
*/


Ltab::Ltab()
{
  ilosc=0;
  max=0;
  tab=NULL;
}


Ltab::~Ltab()
{
  if(tab)
    delete [] tab;
}


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


Ltab::Ltab(const Ltab & w)
{
  tab = new int [w.ilosc];
  for(int i=0; i<w.ilosc; i++)
    tab[i]=w.tab[i];
  ilosc= w.ilosc;
  max=w.max;
}


void Ltab::wypisz()
{
  for(int i=0; i < ilosc; i++)
    cout << tab[i] << endl;
}


Ltab& Ltab::operator=(const Ltab & w)
{
  ilosc=w.ilosc;
  max=w.max;

  for(int i=0; i<w.ilosc; ++i)
    tab[i]=w.tab[i];
  return *this;
}


int& Ltab::operator[](unsigned int index)
{
  return tab[index];
}


