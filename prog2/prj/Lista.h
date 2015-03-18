#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <string>

/*!
*\file
*\brief Plik naglowkowy Lista.h
*
*Zawiera definicje struktury Elista oraz definicje klasy Lista
*/

/*!
 *\brief Modeluje pojecie struktury Elista
 *
 *Struktura Elista jest elementem klasy Lista.
*Zawiera wskazniki na element poprzedni i nastepny oraz wartosc typu int
*/

struct Elista                  
{
    Elista *next, *poprz;       
    int wartosc;                
};

/*!
 *\brief Modeluje pojecie klasy Lista
 *
 *Klasa Lista zawiera prywatnie wskazniki na poczatek i koniec listy oraz dlugosc listy typu unsigned
*Publicznie zawieraz wszystkie metody, konstruktor i destruktor.
*/

class Lista
{
private:
    Elista *poczatek, *koniec;      
    unsigned dlg;               

public:
    Lista();                    
    ~Lista();                   
    void wyswietl_l();           
    void push_front(int v);     
    void push_back(int v);      
    void usun(Elista *e);    
    void pop_front();           
    void pop_back();            

};

#endif // LISTA_H
