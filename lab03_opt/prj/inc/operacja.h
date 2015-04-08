/*!	\file operacja.h
	\brief Plik zawiera deklarację funkcji operacja().
*/ 
#ifndef OPERACJA_H
#define OPERACJA_H

#include <vector>
#include <cassert>
#include <ctime>   	// clock(), clock_t, CLOCKS_PER_SEC

#include "stos.h"
#include "kolejka.h"
#include "stos_arr.h"
#include "kolejka_arr.h"
#include "lista_arr.h"

/*! \brief Wykonuje operację na wczytanym ciągu danych.
 *
 * Funkcja odpowiada za wykonanie porządanej operacji na ciągu danych.
 *
 * \param[in] wektor Referencja do wczytanego ciąg danych.
 * \param[in] ilosc_operacji Określa na ilu pierwszych elementach wektora wektor ma zostać wykonana operacja.
 */
clock_t operacja(std::vector<int> &wektor, unsigned int ilosc_operacji);


#endif
