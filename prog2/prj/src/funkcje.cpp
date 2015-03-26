#include "funkcje.h"


using namespace std;

/*!
 *\file
 *\brief Definicja funkcji programu
 *
 *Zawiera definicje funkcji
 */


void wyswietl(clock_t t[], int roz)
{
    cout << "Tablica: ";
    for(int i=0; i<roz; i++)
      cout << t[i] << " ";
    cout << endl;
}


void zpliku(string nazwa, int t[], int roz)
{
    ifstream plik;
    plik.open(nazwa.c_str());
    if(!plik.good())
    {
        cout << "Nie udalo sie otworzyc pliku!" << endl;
    }
    else
    {
        cout << "Udalo sie wczytac tablice z pliku" << endl;
        for(int i=0; i<roz; i++)
            plik >> t[i];
    }
    plik.close();
}


void dopliku(string nazwa, int t[], int roz)
{
    ofstream plik;
    plik.open(nazwa.c_str(), ios::binary);
    if(!plik.good())
    {
        cout << "Nie udalo sie otworzyc pliku!" << endl;
    }
    else
    {
        cout << "Udalo sie zapisac tablice do pliku" << endl;
        for(int i=0; i<roz; i++)
            plik << t[i] << " ";
        cout << endl;
    }
    plik.close();
}


void wypelnij(int t[], int roz)
{
    for(int i=0; i<roz; i++)
        t[i] = rand();
}

void pomnoz(int t[], int roz)
{
	for(int i=0; i<roz; i++)
	{
	t[i]= 2*t[i];
	}
}
	
