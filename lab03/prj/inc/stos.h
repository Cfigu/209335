/*!
	\file stos.h
	\brief Plik zawiera definicję klasy Stos jako pochodnej klasy Kontener oraz definicje jego metod.
*/
#ifndef STOS_H
#define STOS_H

#include "kontener.h"
/*!
	\brief Stos, abstrakcyjna struktura danych z buforem typu FIFO
*/
namespace ls
{
class Stos: public ls::Kontener{

public:
~Stos(){ 
	const int rozmiar = this->size();
	for(int i = 0; i < rozmiar; ++i)
		this->pop();
}
/*!
	\brief Pop stosu jaki jest, każdy widzi. Zdejmuje najmłdoszy element i zwraca wartość przez niego przechowywaną.
*/
	int pop(){ return this->erase(0);}
};
}
#endif
