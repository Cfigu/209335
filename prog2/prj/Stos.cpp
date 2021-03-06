#include "Stos.h"

using namespace std;

/*!
*\file
*\brief Plik Stos.cpp
*
*Zawiera definicje metod klasy Stos
*/


/*! 
   *\brief Konstruktor Klasy Stos
   *
   *Tworzy pusta klase Stos
   *
   */

Stos::Stos()
{
    S = NULL;
}

/*! 
   *\brief Destruktor klasy Stos
   *
   *Kasuje klase Stos
   *
   */

Stos::~Stos()
{
    while(S)
        pop_s();
}

/*! 
   *\brief Metoda klasy Stos empty_s
   *
   *\return Zwraca true jesli klasa jest pusta. Zwraca false jesli klasa nie jest pusta
   */

bool Stos::empty_s()
{
    if(S==NULL)
        return true;
    else
        return false;
}

/*! 
   *\brief Metoda klasy Stos top
   *
   *
   *\return Zwraca element na szczycie stosu
   */

Element *Stos::top()
{
    return S;
}

/*! 
   *\brief Metoda klasy Stos push_s
   *
   *\param[in] v - to bedzie wartosc dodanego elementu
   *
   */

void Stos::push_s(int v)
{
    Element *e = new Element;
    e->wartosc = v;
    e->next = S;
    S = e;
}

/*! 
   *\brief Metoda klasy Stos pop_s
   *
   *Zdejmuje element ze stosu
   *
   */

void Stos::pop_s()
{
    if(S)
    {
        Element *e = S;
        S = S->next;
        delete e;
    }
    else
        cout << "Stos jest pusty" << endl;
}

/*! 
   *\brief Metoda klasy Stos wyswietl_s
   *
   *Wyswietla kazdy element stosu zaczynajac od wierzcholka
   *
   */

void Stos::wyswietl_s()
{
    Element *Temp = S;
    if(S==NULL)
        cout << "Stos jest pusty" << endl;
    else
    {
        while(Temp)
        {
            cout << Temp->wartosc <<  " ";
            Temp = Temp->next;
        }
        cout << endl;
    }
}
