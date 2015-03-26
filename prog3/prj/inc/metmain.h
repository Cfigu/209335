#ifndef METMAIN_H
#define METMAIN_H

#include "ListaAr.h"
#include "Lista.h"
#include "funkcje.h"
#include <ctime>

using namespace std;

/*!
*\file
*\brief Plik zawiera funkcje wykonywane w pliku main.cpp
*
*/

/*!
 *\brief Funkcja ListaStruktura
 *
 *Funkcja oblicza 10 razy czas wypelnienia listy na strukturze (klasa Lista) dla zadanego rozmiaru
 *oraz zadanej listy. Nastepnie oblicza czas sredni oraz wyswietla wyniki na wyjsciu.
 */

void ListaStruktura(int roz, Lista A);


/*!
 *\brief Funkcja ListaZwieksz1
 *
 *Funkcja oblicza 10 razy czas wypelnienia listy na tablicy (klasa Ltab) dla zadanego rozmiaru.
 *Nastepnie oblicza czas sredni oraz wyswietla wyniki na wyjsciu.
 *Tablica jest tu powiekszana za kazym razem o jednen element.
 */


void ListaZwieksz1(int roz);


/*!
 *\brief Funkcja ListaZwiekszX2
 *
 *Funkcja oblicza 10 razy czas wypelnienia listy na tablicy (klasa Ltab) dla zadanego rozmiaru
 *Nastepnie oblicza czas sredni oraz wyswietla wyniki na wyjsciu.
 *Tablica jest tu powiekszanana dwukrotnie jesli jest taka potrzeba.
 *Jesli nie to dodawany element zostaje dodany na koniec tablicy.
 */

void ListaZwiekszX2(int roz);

#endif

