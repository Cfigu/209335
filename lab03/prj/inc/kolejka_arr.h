#ifndef KOLEJKA_ARR_H
#define KOLEJKA_ARR_H

#include <cstdlib> // NULL
namespace arr
{
	class Kolejka
	{
		// Przechowuje adres do pierwszego elementu kolejki
		int *tablica;
		int rozmiar_kol;
		int pojemnosc_kol;
	/*!
		\brief Metoda zwiększa dwukrotnie pojemnosć kolejki.
	*/
		void rozszerz_x2();
	/*!
		\brief Metoda zwiększa pojemnosć kolejki o 1.
	*/
		void rozszerz_1();

	public:
	/*! 
		\brief Konstruktor domyślny klasy arr::Kolejka. 
	*/
		Kolejka(): tablica(new int), rozmiar_kol(0), pojemnosc_kol(1){}
	/*!
		\brief Konstruktor kopiujący klasy arr::Kolejka.
	
		Bezużyteczny dla trzeciego zadania, ale na pewno kolega się ucieszy.
	*/
		Kolejka(const Kolejka &lewy);
	/*!
		\brief Destruktor klasy arr::Kolejka.
	*/
		~Kolejka();
	/*!
		\brief Wrzuca element na szczyt kolejki.
	*/
		void push(int val);
	/*!
		\brief Zdejmuje najstarszy element z kolejki.
		
		\return Zwraca wartość przechowywaną w zdejmowanej cegiełce
	*/
		int pop();
	/*!
		\brief Sprawdza, czy kolejka jest pusta.
		
		\return Zwraca prawdę, jeżeli kolejka jest pusta. W przeciwnym razie zwraca false.
	*/
		bool empty();
	/*!
		\brief Zwraca rozmiar kolejki.
	*/
		int size(){return rozmiar_kol;}
	};
}
#endif
