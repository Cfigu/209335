#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>


using namespace std;

/*!
 *\file
 *\brief Funkcje programu
 *
 *Zawiera funkcje
 */


/*!
 *\brief Wyswietla tablice
 *
 *Funkcja wyswitla tablice liczb calkowitych o zadanym rozmiarze 
*/

void wyswietl(clock_t t[], int roz);


/*!
 *\brief Wczytuje tablice z pliku
 *
 *Funkcja wczytuje tablice liczb calkowitych o zadanym rozmiarze
*/

void zpliku(string nazwa, int t[], int roz);


/*!
 *\brief Zapisuje tablice do pliku
 *
 *Funkcja zapisuje tablice liczb calkowitych o zadanym rozmiarze
*/


void dopliku(string nazwa, int t[], int roz);

/*!
 *\brief Wypelnia tablice zliczbami
 *
 *Funkcja wypelnia tablice losowymi liczbami calkowitymi
*/


void wypelnij(int t[], int roz);


/*!
 *\brief Mnozy kazdy element tablicy razy 2
 *
 *Funkcja mnozy kazdy element tablicy razy 2
*/


void pomnoz(int t[], int roz);

#endif

