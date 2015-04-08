/*!\file GeneratorDanych.cpp
 * \brief Generator liczb do przetwarzania.
 *
 * Tworzy plik z ciagiem losowych liczb oddzielonych bialymi znakami.
 * W pliku naglowkowym mozna ustawic przedzial, w jakim maja sie
 * znajdowac wylosowane liczby, ich ilosc, oraz nazwe tworzonego pliku.
 *
 * Autor: Mateusz Krawczuk
 */

#include <fstream> 		// ofstream()
#include <iostream>		// cerr, endl
#include <cstdlib>		// exit(), rand()
#include <climits>		// INT_MAX
#include <ctime>		// rand(), srand()

#include "../prj/inc/ustawienia.h"	//NAZWA_PLIKU, KRES_GORNY, KRES_DOLNY

using namespace std;

int main()
{
	// Wysyla plik z danymi do katalogu, gdzie powinien
	// znajdowac sie plik wykonywalny. 
	ofstream plikwy(NAZWA_PLIKU_WE);

	if(!plikwy)
	{
		cerr << "Blad tworzenia pliku!" << endl;
		exit(1);
	}
	// Uzaleznia losowane liczby od stanu zegara.
	srand( time( NULL ) ); 
	// 
	for(int i = 0; i < ILOSC; ++i)
		plikwy << (rand() % (KRES_GORNY - KRES_DOLNY)) + KRES_DOLNY << ' ';
}
