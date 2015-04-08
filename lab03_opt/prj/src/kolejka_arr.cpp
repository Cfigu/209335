#include "../inc/kolejka_arr.h"

arr::Kolejka::Kolejka(const Kolejka &lewy)
{
	tablica = new int[lewy.rozmiar_kol];
	for(int i = 0; i < lewy.rozmiar_kol; ++i)
		tablica[i] = lewy.tablica[i];
}

arr::Kolejka::~Kolejka()
{
	delete [] tablica;
}

void arr::Kolejka::push(int val)
{
	if(this->tablica == NULL)
	{
		this->tablica = new int(val);
		++this->pojemnosc_kol;
	}
	else if(this->rozmiar_kol < this->pojemnosc_kol)
		this->tablica[rozmiar_kol] = val;
	else
	{
		this->rozszerz_x2();
		this->tablica[rozmiar_kol] = val;
	}
	++this->rozmiar_kol;
}

int arr::Kolejka::pop()
{
	int zwracana = this->tablica[0];
	
	// 'Opuszczanie' całej kolejki o 1 w dół
	for(int i = 0; i < rozmiar_kol - 1; ++i)
		this->tablica[i] = this->tablica[i+1];
	--this->rozmiar_kol;

	return(zwracana);	
}

bool arr::Kolejka::empty()
{
	return(this->rozmiar_kol == 0);
}

void arr::Kolejka::rozszerz_x2()
{
	// Rezerwacja nowego bloku pamięci
	int *temp = new int[this->rozmiar_kol*2];
	// Kopiowanie dotychczas przechowywanych elementów
	for(int i = 0; i < this->rozmiar_kol; ++i)
		temp[i] =this->tablica[i];
	// Zwalnianie dotychczas używanej pamięci
	delete [] this->tablica;
	// Teraz tablica wskazywać będzie na nowy obszar
	this->tablica = temp;
	// Aktualizowanie wartości pojemności stosu	
	this->pojemnosc_kol *= 2;	
}

void arr::Kolejka::rozszerz_1()
{
	// Rezerwacja nowego bloku pamięci
	int *temp = new int[this->rozmiar_kol + 1];
	// Kopiowanie dotychczas przechowywanych elementów
	for(int i = 0; i < this->rozmiar_kol; ++i)
		temp[i] =this->tablica[i];
	// Zwalnianie dotychczas używanej pamięci
	delete [] this->tablica;
	// Teraz tablica wskazywać będzie na nowy obszar
	this->tablica = temp;
	// Aktualizowanie wartości pojemności stosu	
	++this->pojemnosc_kol;
}
