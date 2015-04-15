#include "AsoTab.h"

/*!
*\file
*\brief Plik AsoTab.cpp
*
*Zawiera definicje metod klasy Aso
*/

Aso::Aso()
{
  Lista L;
}

Aso::~Aso()
{
  ;
}

int Aso::hash(string e)
{
    int n = e.size();
    long int sum =0;
    int val, index;

    val = (int)e[0];
    val = val*7;
    sum += val;

    val = (int)e[1];
    val=val*13;
    sum += val;

    for(int i=2;i<n;i++)
    {
        val = (int)e[i];
        sum += val<<4; // <<4 == *2^4
    }
    index = sum%317;  // 317 liczba pierwsza
    return index;
}


void Aso::add(string e)
{
  int k = hash(e);
  L.push_back(k,e);
}

void Aso::wys()
{
  L.wyswietl_l();
}

int Aso::find(string e)
{
  return L.szukaj(e);
}

int Aso::operator[](string k)
{
  return this->find(k);
}

void Aso::wczyt(string nazwa, int roz)
{
  string pom;
  ifstream plik;
  plik.open(nazwa.c_str());
  if(!plik.good())
    {
      cout << "Nie udalo sie otworzyc pliku!" << endl;
    }
  else
    {
      cout << "Udalo sie wczytac tablice z pliku" << endl;
      for(int i=0; i<roz; i++)
	{
	  plik >> pom;
	  this->add(pom);
	}
    }
    plik.close();
}
