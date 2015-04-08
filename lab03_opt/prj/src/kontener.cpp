 /*!
	\file kontener.cpp
	\brief Plik zawiera definicje metod klasy Kontener.
*/
#include "../inc/kontener.h"

ls::Kontener::~Kontener()
{
	const int rozmiar = this->size();
	for(int i = 0; i < rozmiar; ++i)
		this->erase(0);
}
void ls::Kontener::push(int wart)
{
	cegla *nowa = new cegla;
	nowa->dana = wart;
	nowa->nastepna = this->alfa;
	alfa = nowa;
}

void ls::Kontener::insert(int wart, int indeks)
{
	if(indeks == 0) this->push(wart);
	else
	{	
		int rozmiar = this->size();
		cegla *starsza = this->alfa;	
		cegla *mlodsza = this->alfa;
		// ... od nowo dodawanej
		cegla *nowa = new cegla;

		nowa->dana = wart;
		if(indeks > 0 && indeks <= rozmiar)
		{	// Pomiędzy 'starsza' a 'mlodsza' wejdzie
			// nowa cegiełka
			for(int i = 0; i < indeks; ++i)
			{	// Zapisanie adresu nowszej cegiełki
				if (i == indeks - 1)
					mlodsza = starsza;
				starsza = starsza->nastepna;
			}
		}
	// Nowa cegiełka wskazuje na starszą od siebie
	nowa->nastepna = starsza;
	// Młodsza cegiełka wskazuje na nowo utworzoną
	mlodsza->nastepna = nowa;
	}
}

int ls::Kontener::size()
{
	int wielkosc = 0;
	cegla *temp = this->alfa;

	if(this->alfa) // Warunek spelniony jezeli wskaznik niepusty 
		while(temp)
		{
			temp = temp->nastepna;
			++wielkosc;
		}

	return wielkosc;
}

int ls::Kontener::erase(int indeks)
{
	cegla *usuwany = this->alfa; // pomocniczy na usuwaną cegłę
	// pomocniczy na cegłę o 1 młodszą	
	cegla *przed_usuwanym = this->alfa;
		
	int usuneli_mnie = 0; // wartość przechowywana w usuwanej cegle

	if(indeks == 0)
	{
		usuneli_mnie = usuwany->dana;
		// Najmłodszy element to teraz o 1 starszy po usuwanym
		this->alfa = usuwany->nastepna; 
	}
	if(indeks > 0 && indeks <= this->size())
	{
		// Podróż wskaźnika w stronę usuwanej cegiełki
		for(int i = 0; i < indeks; ++i)
		{
			if (i == indeks - 1)
				// Zapisanie adresu nowszej cegiełki
				przed_usuwanym = usuwany;
			// Przesunięcie wskaźnika na starszą cegłę
			usuwany = usuwany->nastepna;
		}
		// Teraz wskaźnik 'usuwany' wskazuje odpowiednią cegłę
		// Przystępujemy do usuwania cegiełki
		usuneli_mnie = usuwany->dana;
		przed_usuwanym->nastepna = usuwany->nastepna;
	}
	delete usuwany;
	return usuneli_mnie;
}

int ls::Kontener::find(int wartosc)
{
	cegla *temp = this->alfa;
	int indeks = 0;
		
	if(temp) // jeżeli kontener niepusty
	{
		for(int i = 0; i < this->size(); ++i)
		{
			if(temp->dana == wartosc) break;
			temp = temp->nastepna;
			++indeks;
		}
	}
	return indeks;
}

void ls::Kontener::show()
{
	cegla *temp = this->alfa;

	if(this->alfa) // Warunek spelniony jezeli wskaznik niepusty 
		while(temp)
		{
			std::cout << temp->dana << std::endl;
			temp = temp->nastepna;
		}
}
