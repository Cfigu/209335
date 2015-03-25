#include "Lista.h"

using namespace std;

/*!
*\file
*\brief Plik Lista.cpp
*
*Zawiera definicje metod klasy Lista
*/

/*! 
   *\brief Konstruktor klasy Lista
   *
   *Tworzy pusta klase Lista
   */

Lista::Lista()
{
    poczatek = koniec = NULL;
    dlg = 0;
}

/*! 
   *\brief Destruktor klasy Lista
   *
   *Kasuje cala klase
   *
   */

Lista::~Lista()
{
    while(dlg)
        pop_front();
}

/*! 
   *\brief Metoda klasy Lista wyswietl_l
   *
   *Wyswietla cala zawartosc listy
   */

void Lista::wyswietl_l()
{
    if(poczatek!=NULL)
    {
        Elista *Temp;
        Temp = poczatek;

        while(Temp)
        {
            cout << Temp->wartosc << " ";
            Temp = Temp->next;
        }
    }
    else
        cout << "Lista jest pusta";
}

/*! 
   *\brief Metoda klasy Lista push_front
   *
   *Dodaje element na szczyt listy
   *
   *\param[in] v - taka bedzie wartosc dodanego elementu
   */

void Lista::push_front(int v)
{
    Elista *Temp;

    Temp = new Elista;
    Temp->wartosc = v;
    Temp->poprz = NULL;
    Temp->next = poczatek;
    poczatek = Temp;

    if(Temp->next)
        Temp->next->poprz = Temp;
    else
        koniec = Temp;
    dlg++;
}

/*! 
   *\brief Metoda klasy Lista push_back
   *
   *Dodaje element na koniec listy
   *
   *\param[in] v - taka bedzie wartosc dodanego elementu
   */

void Lista::push_back(int v)
{
    Elista *Temp;

    Temp = new Elista;
    Temp->wartosc = v;
    Temp->next = NULL;
    Temp->poprz = koniec;
    koniec = Temp;

    if(Temp->poprz)
        Temp->poprz->next = Temp;
    else
        poczatek = Temp;
    dlg++;
}

/*! 
   *\brief Metoda klasy Lista usun
   *
   *Usuwa wybrany element listy. Metoda jest wykorzystywana w metodach pop dla klasy Lista
   *
   *\param[in] *e - wskaznik na element listy ktory chcemy usunac 
   */

void Lista::usun(Elista *e)
{
    if(e->poprz)
        e->poprz->next = e->next;
    else
        poczatek = e->next;
    if(e->next)
        e->next->poprz = e->poprz;
    else
        koniec = e->poprz;
    delete e;
    dlg--;
}

/*! 
   *\brief Metoda klasy Lista pop_front
   *
   *Kasuje element ze szczytu listy
   *
   */

void Lista::pop_front()
{
    if(dlg)
        usun(poczatek);
    else
        cout << "Lista jest pusta" << endl;
}

/*! 
   *\brief Metoda klasy Lista pop_back
   *
   *Kasuje element z konca listy
   *
   */

void Lista::pop_back()
{
    if(dlg)
        usun(koniec);
    else
        cout << "Lista jest pusta" << endl;
}
