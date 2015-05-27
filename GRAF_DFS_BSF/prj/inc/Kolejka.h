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

/*! 
   *\brief Konstruktor klasy Kolejka
   *
   *Tworzy pusta klase Kolejka
   */

    Kolejka();  

/*! 
   *\brief Destruktor klasy Kolejka
   *
   *Kasuje klase Kolejka 
   */
    
    ~Kolejka();     

/*! 
   *\brief Metoda klasy Kolejka empty_k
   *
   *Sprawdza czy kolejka jest pusta
   *
   *\return Zwraca true jesli kolejka jest pusta i false jesli nie
   */


    bool empty_k(void);

/*! 
   *\brief Metoda klasy Kolejka push_k
   *
   *Dodaje element na koniec kolejki
   *
   *\param[in] v - taka bedzie wartosc dodanego elementu
   *
   */

    void push_k(int v);

/*! 
   *\brief Metoda klasy Kolejka pop_k
   *
   *Zabiera element z konca kolejki
   *
   */

    void pop_k(void);

/*! 
   *\brief Metoda klasy Kolejka front
   *
   *Zwraca pocztek kolejki
   *
   */

int front();

};

#endif 
