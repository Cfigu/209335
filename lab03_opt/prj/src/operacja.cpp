/*!
 * \file operacja.cpp
 *
 *  Created on: 11-03-2015
 *      Author: turbowarkocz
 */

#include "../inc/operacja.h"
#include <stack>
#include <queue>
#include <list>

clock_t operacja(std::vector<int> &wektor, unsigned int ilosc_operacji)
{
	clock_t czas;
	arr::Lista sztos;
	
	for(unsigned int i = 0; i < ilosc_operacji; ++i)
		sztos.insert(wektor[i], 0);
	// Zapisanie czasu wykonywania operacji
	czas = clock();
	// Zwalnianie pamięci, nie liczone przez zegar.
	//for(int i = sztos.size(); i > 0; --i)
	//	sztos.erase(0);

	return czas;
}


