#include "Lista.h"

using namespace std;

/*!
*\file
*\brief Plik Lista.cpp
*
*Zawiera definicje metod klasy Lista
*/


Lista::Lista()
{
    poczatek = koniec = NULL;
    dlg = 0;
}


Lista::~Lista()
{
    while(dlg)
        pop_front();
}


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


void Lista::pop_front()
{
    if(dlg)
        usun(poczatek);
    else
        cout << "Lista jest pusta" << endl;
}


void Lista::pop_back()
{
    if(dlg)
        usun(koniec);
    else
        cout << "Lista jest pusta" << endl;
}

