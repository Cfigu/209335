#ifndef KOLEJKA_H
#define KOLEJKA_H

#include <iostream>
#include <string>

/*!
*\file
*\brief Plik naglowkowy Kolejka.h
*
*Zawiera definicje struktury Ekolejka oraz definicje klasy Kolejka
*/

/*!
 *\brief Modeluje pojecie struktury Ekolejka
 *
 *Struktura jest elementem klasy Kolejka. 
*Zawiera wskaznik na kolejny element oraz wartosc typu int.
*/

struct Ekolejka
{
  Ekolejka *next;
  int wartosc;
};

/*!
 *\brief Modeluje pojecie klasy Kolejka
 *
 *Klasa zawieraz prywanie wskazniki na poczatek i koniec kolejki
*Publiczne sa wszystki metody, konstruktor i destruktor.
*/

class Kolejka
{
  private:
    Ekolejka *poczatek;
    Ekolejka *koniec;

  public:
    Kolejka();      // konstruktor
    ~Kolejka();     // destruktor
    bool empty_k(void);
    void push_k(int v);
    void pop_k(void);
};

#endif // KOLEJKA_H
