/*!
	\file benchmark.h
	\brief Deklaracje funkcji związanych z analizą prędkości operacji.

	Plik zawiera deklaracje funkcji Benchmark() oraz licz_dekady().
	Funkcja Benchmark() jest główną funkcją programu
	benchmarkującego, natomiast funkcja licz_dekady() jest
	funkcją pomocniczą wywoływaną w funkcji Benchmark().
*/

#ifndef BENCHMARK_H
#define BENCHMARK_H

#include "operacja.h"
#include "ustawienia.h"
#include "kontener.h"
#include "stos.h"
#include "kolejka.h"
#include "stos_arr.h"

#include <fstream> 	// ifstream()
#include <iostream> 	// cout, cerr, endl
#include <vector> 	// vector<int>, vector::push_back(),vector::size()
#include <cstdlib>	// exit()
#include <cmath>	//pow()

/*!
	\brief Główna funkcja programu

	Funkcja wywoływana w funkcji main(). Nie przyjmuje argumentów 
	ani nie zwraca wartości. Funkcja otwiera plik, który powinien
	zawierać ciąg danych, na których przeprowadzona zostanie
	operacja. Otwiera także plik, do którego zapisane mają zostać 
	wyniki czasowe operacji. Nazwy plików określone są w nagłówku
	"ustawienia.h". Z pliku wejściowego wczytuje do obiektu klasy
	std::vector ciąg danych. Do zmiennej typu clock_t zostaje
	zapisany czas procesora od rozpoczęcia procesu. Do funkcji
	operacja() zostaje przekazana referencja do obiektu
	zawierającego ciąg danych. Po wyjściu z funkcji operacja()
	do zmiennej typu clock_t() zostaje tym razem zapisana różnica
	czasów procesora pomiędzy rozpoczęciem procesu a wartością
	typu clock_t zwróconą przez funkcję operacja(). Czas ten 	 przeliczany jest na sekundy i zapisany do pliku wyjściowego.  		W "ustawienia.h" określona jest ilość powtórzeń pomiaru.
	Pomiary zaczynają się od operacji na jednej wartości i kończą 
	na ciąu danych o długości największej potęgi dziesiątki.
	 Pomiary powtarzane są	co dekadę. Informację o największej 
	potędze dziesiątki dostarcza funkcja licz_dekady().
*/
void Benchmark();
/*!
	\brief Funkcja pomocnicza do określania ilości dekad

	Przyjmuje jako argument liczbę całkowitą reprezentującą
	długość ciągu danych i zaokrągla ją w dół do najbliższej
	potęgi liczby 10.

	\param[in] dlugosc_ciagu Długość ciągu danych.
	\return	Zwraca zaokrąglenie w dół do najbliższej potęgi dziesiątki wartości dlugosc_ciagu.
*/
int licz_dekady(int dlugosc_ciagu);
#endif
