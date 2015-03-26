#include "../inc/benchmark.h"

using namespace std;
void Benchmark()
{
	clock_t zegar; 		// czas w tickach procesora
	double czas_w_s;	// czas w sekundach
	double srednia;		// pomocnicza do liczenia średniej
	int ilosc_dekad;	// ilość przedziałek na osi x wykresu
	int temp; 		// pomocnicza do wczytywania z pliku
	
	// Tutaj wczytywane są dane z pliku
	vector<int> dane(ILOSC + 100);

	ifstream plikwe(NAZWA_PLIKU_WE); // Otwieranie pliku z danymi
	ofstream plikwy(NAZWA_PLIKU_WY); // Tworzenie pliku na wyniki
	

	if(!plikwe)
	{
		cerr << "Blad otiwerania pliku z danymi!" << endl;
		exit(1);
	}

	if(!plikwy)
	{
		cerr << "Blad tworzenia pliku z wynikami!" << endl;
		exit(1);
	}

	// Wczytuj liczby z pliku do pojawienia się EOF
	for(int i = 0; plikwe >> temp; ++i)
		dane[i] = temp;
	// Tworzenie oznaczenia kolumn w pliku z wynikami
	plikwy << "#Operacji\tCzas trwania[s]" << endl; 

	// Obliczanie ilości dekad
	ilosc_dekad = licz_dekady(dane.size());
	
	// Wykonywanie pomiaru co dekadę
	for(int i = 0; i <= ilosc_dekad; ++i)
	{
		srednia = 0;
		// Wykonywanie kilku pomiarów i uśrednienie wyniku
		for(int j = 0; j < ILOSC_POWTORZEN; ++j)
		{
			zegar = clock();
			// 	operacja
			zegar = operacja(dane, (unsigned int)pow(10, i)) - zegar;

			czas_w_s = (double)zegar/CLOCKS_PER_SEC;
			srednia += czas_w_s;
		}// KONIEC PETLI
		srednia /= ILOSC_POWTORZEN;
		plikwy << "1e" << i << "\t\t" << srednia << endl;
	}// KONIEC PETLI	
}

int licz_dekady(int dlugosc_ciagu)
{
	int ilosc = 1;
	while(dlugosc_ciagu > 10)
	{
		++ilosc;
		dlugosc_ciagu /= 10;
	}
	return ilosc;
}
