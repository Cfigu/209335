#ifndef GRAF_H
#define GRAF_H
#include "ListaAr.h"
#include "Stos.h"
#include "Kolejka.h"
#include <iostream>
#include <cstdlib>

using namespace std;

/*!
*\file
*\brief Plik naglowkowy graff.h
*
*Zawiera klase Graf
*/


/*! 
   *\brief Deklaracja klasy Graf
   *
   *Prywatnie zawiera ilosc wierzcholkow v oraz tablice list typu Ltab
   */

class Graf {
private:

Ltab *A;
int v;

public:

/*! 
   *\brief Konstruktor klasy Garf
   *
   *Tworzy dynamicznie nowa tablice list oraz ustawia v na 0
   */

Graf();

/*! 
   *\brief Metoda stworz
   *
   *Wypelnia graf zadanymi warotsciami. Nalezy podac ilosc wierzcholkow i krawedzi jako parametry metody.
   *W zaleznosci od ilosci krawedzi tyle razy jest sie proszonym o podanie dwoch liczby w nastepujacy sposob
   * 3 7
   *Co oznacza krawedz od wierzcholka 3 do 7(7 3 oznacza to samo bo jest to graf nieskierowany)
   *\param[in] v - ilosc wierzcholkow
   *\param[in] e - ilosc krawedzi
   */

void stworz(int v, int e);

/*! 
   *\brief Metoda stworz_rand
   *
   *Wypelnia graf losowymi polaczeniami 
   *\param[in] v - ilosc wierzcholkow
   *\param[in] e - ilosc krawedzi
   */

void stworz_rand(int w, int e);

/*! 
   *\brief Metoda DFS
   *
   *Przechodzi graf w glab algorytmem DFS
   *\param[in] p - wierzcholek startowy
   */

void DFS(int p);

/*! 
   *\brief Metoda BSF
   *
   *Przechodzi graf w szerz algorytmem BSF
   *\param[in] p - wierzcholek startowy
   */

void BSF(int p);

};















#endif
