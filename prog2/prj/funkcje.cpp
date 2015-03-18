#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>


using namespace std;

/*!
 *\file
 *\brief Definicja funkcji programu
 *
 *Zawiera definicje funkcji
 */


/*!
 *\brief Wyswietla tablice
 *
 *Funkcja wyswitla tablice liczb calkowitych o zadanym rozmiarze 
*/

void wyswietl(clock_t t[], int roz)
{
    cout << "Tablica: ";
    for(int i=0; i<roz; i++)
      cout << t[i] << " ";
    cout << endl;
}

/*!
 *\brief Wczytuje tablice z pliku
 *
 *Funkcja wczytuje tablice liczb calkowitych o zadanym rozmiarze
*/

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

/*!
 *\brief Zapisuje tablice do pliku
 *
 *Funkcja zapisuje tablice liczb calkowitych o zadanym rozmiarze
*/


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

/*!
 *\brief Wypelnia tablice zliczbami
 *
 *Funkcja wypelnia tablice losowymi liczbami calkowitymi
*/


void wypelnij(int t[], int roz)
{
    for(int i=0; i<roz; i++)
        t[i] = rand();
}

/*!
 *\brief Mnozy kazdy element tablicy razy 2
 *
 *Funkcja mnozy kazdy element tablicy razy 2
*/


void pomnoz(int t[], int roz)
{
	for(int i=0; i<roz; i++)
	{
	t[i]= 2*t[i];
	}
}
	
