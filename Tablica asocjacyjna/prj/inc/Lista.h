#ifndef LISTA_H
#define LISTA_H

#include <string>
#include <iostream>


/*!
*\file
*\brief Plik naglowkowy Lista.h
*
*Zawiera definicje struktury Elista oraz definicje klasy Lista i jej metody
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
  std::string key;                
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

/*! 
   *\brief Konstruktor klasy Lista
   *
   *Tworzy pusta klase Lista
   */

    Lista();  

/*! 
   *\brief Destruktor klasy Lista
   *
   *Kasuje cala klase
   *
   */
                  
    ~Lista();      

/*! 
   *\brief Metoda klasy Lista wyswietl_l
   *
   *Wyswietla cala zawartosc listy
   */

             
    void wyswietl_l();     

/*! 
   *\brief Metoda klasy Lista push_front
   *
   *Dodaje element na szczyt listy
   *
   *\param[in] v - taka bedzie wartosc dodanego elementu
   *\param[in] k - taki jest klucz
   */
      
    void push_front(int v, std::string k);    

/*! 
   *\brief Metoda klasy Lista push_back
   *
   *Dodaje element na koniec listy
   *
   *\param[in] v - taka bedzie wartosc dodanego elementu
   *\param[in] k - taki jest klucz
   */
 
    void push_back(int v, std::string k);   

/*! 
   *\brief Metoda klasy Lista usun
   *
   *Usuwa wybrany element listy. Metoda jest wykorzystywana w metodach pop dla klasy Lista
   *
   *\param[in] *e - wskaznik na element listy ktory chcemy usunac 
   */
   
    void usun(Elista *e);   

/*! 
   *\brief Metoda klasy Lista pop_front
   *
   *Kasuje element ze szczytu listy
   *
   */
 
    void pop_front();   

/*! 
   *\brief Metoda klasy Lista pop_back
   *
   *Kasuje element z konca listy
   *
   */
        
    void pop_back();
   /*! 
   *\brief Metoda klasy Lista szukaj
   *
   *Szuka elementu Listy na podstawie klucza key
   *\param[in] k - klucz
   *\return Zwraca wartosc odpowiadajaca kluczowi 
   */         
int szukaj(std::string k);
};

#endif // LISTA_H
