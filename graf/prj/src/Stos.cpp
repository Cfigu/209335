#include "Stos.h"

using namespace std;

/*!
*\file
*\brief Plik Stos.cpp
*
*Zawiera definicje metod klasy Stos
*/


Stos::Stos()
{
    S = NULL;
}



Stos::~Stos()
{
    while(S)
        pop_s();
}


bool Stos::empty_s()
{
    if(S==NULL)
        return true;
    else
        return false;
}



int Stos::top()
{
    return S->wartosc;
}


void Stos::push_s(int v)
{
    Element *e = new Element;
    e->wartosc = v;
    e->next = S;
    S = e;
}


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
