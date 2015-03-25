#include <iostream>
#include "ListaAr.cpp"
#include "ListaAr.h"
#include "Lista.cpp"
#include "Lista.h"
#include "funkcje.cpp"
#include <ctime>

using namespace std;

/*!
*\file
*\brief Plik zawiera funkcje wykonywane w pliku main.cpp
*
*/

/*!
 *\brief Funkcja ListaStruktura
 *
 *Funkcja oblicza 10 razy czas wypelnienia listy na strukturze (klasa Lista) dla zadanego rozmiaru
 *oraz zadanej listy. Nastepnie oblicza czas sredni oraz wyswietla wyniki na wyjsciu.
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

/*!
 *\brief Funkcja ListaZwieksz1
 *
 *Funkcja oblicza 10 razy czas wypelnienia listy na tablicy (klasa Ltab) dla zadanego rozmiaru.
 *Nastepnie oblicza czas sredni oraz wyswietla wyniki na wyjsciu.
 *Tablica jest tu powiekszana za kazym razem o jednen element.
 */


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

/*!
 *\brief Funkcja ListaZwiekszX2
 *
 *Funkcja oblicza 10 razy czas wypelnienia listy na tablicy (klasa Ltab) dla zadanego rozmiaru
 *Nastepnie oblicza czas sredni oraz wyswietla wyniki na wyjsciu.
 *Tablica jest tu powiekszanana dwukrotnie jesli jest taka potrzeba.
 *Jesli nie to dodawany element zostaje dodany na koniec tablicy.
 */

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
