#ifndef STOS_H
#define STOS_H

#include <iostream>
#include <string>

/*!
*\file
*\brief Plik naglowkowy Stos.h
*
*Zawiera definicje struktury Element oraz definicje klasy Stos i jej metody
*/

/*!
 *\brief Modeluje strukture Element
 *
 *Strukura Element zawiera wskaznik na kolejkny element stosu oraz wartosc typu int
*/	

struct Element          
{
    Element *next;     
    int wartosc;       
};

/*!
 *\brief Modeluje pojecie klasy Stos
 *
 *Klasa zawiera prywatnie wskaznik na poczatek stosu.
* Publlicze sa takie elementy jak: konstruktor, destruktor oraz wszystkie metody.
*/

class Stos
{
private:
    Element *S;         

public:

/*! 
   *\brief Konstruktor Klasy Stos
   *
   *Tworzy pusta klase Stos
   *
   */

    Stos();    

/*! 
   *\brief Destruktor klasy Stos
   *
   *Kasuje klase Stos
   *
   */
         
    ~Stos();     

/*! 
   *\brief Metoda klasy Stos empty_s
   *
   *\return Zwraca true jesli klasa jest pusta. Zwraca false jesli klasa nie jest pusta
   */
       
    bool empty_s();   

/*! 
   *\brief Metoda klasy Stos top
   *
   *
   *\return Zwraca element na szczycie stosu
   */
    
   // Element *top();     

int top();

/*! 
   *\brief Metoda klasy Stos push_s
   *
   *\param[in] v - to bedzie wartosc dodanego elementu
   *
   */

    void push_s(int v);   

/*! 
   *\brief Metoda klasy Stos pop_s
   *
   *Zdejmuje element ze stosu
   *
   */


    void pop_s();    

/*! 
   *\brief Metoda klasy Stos wyswietl_s
   *
   *Wyswietla kazdy element stosu zaczynajac od wierzcholka
   *
   */

     
    void wyswietl_s();    
};


#endif // STOS_H
