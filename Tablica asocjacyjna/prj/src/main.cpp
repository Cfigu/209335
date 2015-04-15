#include<cstdio>
#include<iostream>
#include <ctime>
#include "AsoTab.h"


using namespace std;

void wczytaj(string nazwa, string t[], int roz)
{
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
	  plik >> t[i];
	}
    }
    plik.close();
}

int main()
{
  double t;
  int roz=10000;
  Aso A;
  string T[10000];
  clock_t czas1, czas2;
  /* klucze.txt zawiera 30 000 slow(przy wiekszej ilosci slow edytor tekstu zaczyna "szalec").
     jest to 100 slow kote sie powtarzaja.
     plik stworzony do testow
  */
  wczytaj("klucze.txt",T,roz); 

  czas1=clock();
  for(int i=0; i<roz;++i)
    A.add(T[i]);
  czas2=clock();

  t =  (double)(czas2-czas1)/CLOCKS_PER_SEC;
  
  cout << t << endl;

  // A.wys();
}
