#ifndef LISTAAR_H
#define LISTAAR_H

#include <iostream>

/*!
*\file
*\brief Plik naglowkowy ListaAr.h
*
*Zawiera definicje klasy Ltab
*/

using namespace std;

/*!
 *\brief Modeluje pojecie klasy Ltab
 *
 *Klasa Ltab zawiera prywatnie ilosc elementow w tablicy, maksynalna ilosc elementow w tablicy oraz element
*Publicznie zawieraz wszystkie metody, przeciazenia operatorow oraz konstruktor i destruktor.	
*/

class Ltab
{
  private:
    int *tab;
    int ilosc, max; 
  public:
    Ltab();
    Ltab(const Ltab & w); 
    ~Ltab();

    Ltab& operator=(const Ltab &w);
    int& operator[](unsigned int index);

    void add(const int &wart);
    void addx2(const int& wart);
    void wypisz();
};

#endif
