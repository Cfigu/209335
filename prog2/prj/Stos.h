#ifndef STOS_H
#define STOS_H

#include <iostream>
#include <string>

/*!
*\file
*\brief Plik naglowkowy Stos.h
*
*Zawiera definicje struktury Element oraz definicje klasy Stos
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
    Stos();             
    ~Stos();            
    bool empty_s();       
    Element *top();     
    void push_s(int v);   
    void pop_s();         
    void wyswietl_s();    
};


#endif // STOS_H
