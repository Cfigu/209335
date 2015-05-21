#include "ListaAr.h"
#include <cstdlib>

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
  max=1;
  tab=new int;
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
  if(max>ilosc)
    {
      tab[ilosc] = wart;
    }
  else
    {
      max = max*2;
      int* pom = new int[max];
      for(int i=0; i<ilosc; i++){
	pom[i] = tab[i];
      }

      delete [] tab;
  
      tab = pom;
 
      tab[ilosc] = wart;
    }
  ++ilosc;
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

int& Ltab::element(int e)
{
    return tab[e];
}

int& Ltab::koniec()
{
  return tab[ilosc-1];
}

int Ltab::ile()
{
  return ilosc;
}

void Ltab::wypelnij_losowymi(const int roz)
{
  int T[roz];

  for(int i=0;i<roz;++i)
    T[i]=rand()%1000;
  
  for(int i=0;i<roz;++i)
    this->addx2(T[i]);
}

void Ltab::wypelnij_odwrotnie(const int roz)
{
  int T[roz];

  for(int i=roz; i>0; --i)
    T[i]=i;
  
  for(int i=0;i<roz;++i)
    this->addx2(T[i]);

}

void Ltab::wypelnij_posortowane(const int roz)
{
  int T[roz];

  for(int i=0; i<roz; ++i)
    T[i]=i;
  
  for(int i=0;i<roz;++i)
    this->addx2(T[i]);
}
