#include "../inc/stos_arr.h"

arr::Stos::Stos(const Stos &lewy)
{
	tablica = new int[lewy.rozmiar_stosu];
	for(int i = 0; i < lewy.rozmiar_stosu; ++i)
		tablica[i] = lewy.tablica[i];
}

arr::Stos::~Stos()
{
	delete [] tablica;
}

void arr::Stos::push(int val)
{
	if(this->tablica == NULL)
	{
		this->tablica = new int(val);
		++this->pojemnosc_stosu;
	}
	else if(this->rozmiar_stosu < this->pojemnosc_stosu)
		this->tablica[rozmiar_stosu] = val;
	else
	{
		this->rozszerz_x2();
		this->tablica[rozmiar_stosu] = val;
	}
	++this->rozmiar_stosu;
}

int arr::Stos::pop()
{
	// Zwraca najwyższy element i zmniejsza licznik rozmiaru o 1
	return(this->tablica[--this->rozmiar_stosu]);	
}

bool arr::Stos::empty()
{
	return(this->rozmiar_stosu == 0);
}

void arr::Stos::rozszerz_x2()
{
	// Rezerwacja nowego bloku pamięci
	int *temp = new int[this->rozmiar_stosu*2];
	// Kopiowanie dotychczas przechowywanych elementów
	for(int i = 0; i < this->rozmiar_stosu; ++i)
		temp[i] =this->tablica[i];
	// Zwalnianie dotychczas używanej pamięci
	delete [] this->tablica;
	// Teraz tablica wskazywać będzie na nowy obszar
	this->tablica = temp;
	// Aktualizowanie wartości pojemności stosu	
	this->pojemnosc_stosu *= 2;	
}

void arr::Stos::rozszerz_1()
{
	// Rezerwacja nowego bloku pamięci
	int *temp = new int[this->rozmiar_stosu + 1];
	// Kopiowanie dotychczas przechowywanych elementów
	for(int i = 0; i < this->rozmiar_stosu; ++i)
		temp[i] =this->tablica[i];
	// Zwalnianie dotychczas używanej pamięci
	delete [] this->tablica;
	// Teraz tablica wskazywać będzie na nowy obszar
	this->tablica = temp;
	// Aktualizowanie wartości pojemności stosu	
	++this->pojemnosc_stosu;
}
