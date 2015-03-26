#include "metmain.h"

using namespace std;

/*!
*\file
*\brief Plik zawiera definicje funkcji wykonywanych w pliku main.cpp
*
*/

void ListaStruktura(int roz, Lista A)
{
  clock_t czas1, czas2;
  clock_t czas[10];

  for(int j=0; j<10; j++)
    {
      
      czas1=clock();
      
      for(int i=0; i<roz; i++)
	{
	  A.push_front(i);
	}
      
      czas2=clock();
      
      
      czas[j]=czas2-czas1;
      
      
      for(int i=0; i<roz; i++)
	{
	  A.pop_front();
	}
      
    }
  
  cout << "Tablica czasow" << endl;
  wyswietl(czas, 10);
  
  cout << "Sredni czas" <<endl;
  cout << (czas[0]+czas[1]+czas[2]+czas[3]+czas[4]+czas[5]+czas[6]+czas[7]+czas[8]+czas[9])/10 << endl;
}


void ListaZwieksz1(int roz)
{
  clock_t czas1, czas2;
  clock_t czas[10];

  for(int j=0; j<10; j++)
    {
      Ltab* B = new Ltab;
      czas1=clock();
      
      for(int i=0; i<roz; i++)
	{
	  B->add(i);
	}
      
      czas2=clock();
      
      czas[j]=czas2-czas1;
      delete B;
    }
  
  cout << "Tablica czasow" << endl;
  wyswietl(czas, 10);
  
  cout << "Sredni czas" <<endl;
  cout << (czas[0]+czas[1]+czas[2]+czas[3]+czas[4]+czas[5]+czas[6]+czas[7]+czas[8]+czas[9])/10 << endl;
}


void ListaZwiekszX2(int roz)
{
  clock_t czas1, czas2;
  clock_t czas[10];

  for(int j=0; j<10; j++)
    {
      Ltab* B = new Ltab;
      B->add(0);
      czas1=clock();
      
      for(int i=0; i<roz; i++)
	{
	  B->addx2(i);
	}
      czas2=clock();
      
      czas[j]=czas2-czas1;
      delete B;
    }
  
  cout << "Tablica czasow" << endl;
  wyswietl(czas, 10);
  
  cout << "Sredni czas" <<endl;
  cout << (czas[0]+czas[1]+czas[2]+czas[3]+czas[4]+czas[5]+czas[6]+czas[7]+czas[8]+czas[9])/10 << endl;
}

