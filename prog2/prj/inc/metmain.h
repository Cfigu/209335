#ifndef METMAIN_H
#define METMAIN_H

#include "Kolejka.h"
#include "Stos.h"
#include "Lista.h"
#include "funkcje.h"

using namespace std;

/*!
*\file
*\brief Plik zawiera funkcje wykonywane w main.cpp
*
*/

/*!
 *\brief Funkcja WypListe
 *
 *Funkcja oblicza 10 razy czas wypelnienia listy na strukturze (klasa Lista) dla zadanego rozmiaru
 *oraz zadanej listy. Nastepnie oblicza czas sredni oraz wyswietla wyniki na wyjsciu.
 */

void WypListe(Lista A);

/*!
 *\brief Funkcja WypKolejke
 *
 *Funkcja oblicza 10 razy czas wypelnienia kolejki na strukturze (klasa Kolejka) dla zadanego rozmiaru
 *oraz zadanej kolejki. Nastepnie oblicza czas sredni oraz wyswietla wyniki na wyjsciu.
 */

void WypKolejke(Kolejka K);

/*!
 *\brief Funkcja WypStos
 *
 *Funkcja oblicza 10 razy czas wypelnienia stosu0 na strukturze (klasa Stos) dla zadanego rozmiaru
 *oraz zadanego stosu. Nastepnie oblicza czas sredni oraz wyswietla wyniki na wyjsciu.
 */

void WypStos(Stos S);

#endif
