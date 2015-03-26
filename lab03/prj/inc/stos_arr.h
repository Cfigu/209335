#ifndef STOS_ARR_H
#define STOS_ARR_H

#include <cstdlib> // NULL
namespace arr
{
class Stos
{
	// Przechowuje adres do pierwszego elementu stosu
	int *tablica;
	int rozmiar_stosu;
	int pojemnosc_stosu;
/*!
	\brief Metoda zwiększa dwukrotnie pojemnosć stosu.
*/
	void rozszerz_x2();
/*!
	\brief Metoda zwiększa pojemnosć stosu o 1.
*/
	void rozszerz_1();

public:
/*! 
	\brief Konstruktor domyślny klasy Stos. 
*/
	Stos(): tablica(new int), rozmiar_stosu(0), pojemnosc_stosu(1){}
/*!
	\brief Konstruktor kopiujący klasy Stos.
	
	Bezużyteczny dla trzeciego zadania, ale na pewno kolega się ucieszy.
*/
	Stos(const Stos &lewy);
/*!
	\brief Destruktor klasy Stos.
*/
	~Stos();
/*!
	\brief Wrzuca element na szczyt stosu.
*/
	void push(int val);
/*!
	\brief Zdejmuje najmłodszy element ze stosu.
*/
	int pop();
/*!
	\brief Sprawdza, czy stos jest pusty.

	\return Zwraca prawdę, jeżeli kolejka jest pusta. W przeciwnym razie zwraca false.
*/
	bool empty();
/*!
	\brief Zwraca rozmiar stosu.
*/
	int size(){return rozmiar_stosu;}
};
}
#endif
