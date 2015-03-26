/*!
	\file kontener.h
	\brief Plik zawiera definicję klasy Kontener oraz deklaracje metod tej klasy.
*/

#ifndef KONTENER_H
#define KONTENER_H

#include <cstdlib> //NULL
#include <iostream>
#include "cegla.h"
namespace ls
{
class Kontener
{
protected:
	cegla *alfa; // wskaźnik na najmłodszy element

public:
/*!
	\brief Konstruktor klasy Kontener.

	Konstruktor klasy Kontener inicjalizuje wskaźnik 'alfa'
	wartością NULL.
*/
	~Kontener();
	Kontener():alfa(NULL){}
/*!
	\brief Wrzuca nową cegiełkę na początek kontenera.

*/

	void push(int);
/*!
	\brief Umieszcza cegłę z wartością 'wartosc' w miejscu
	oddalonym o 'indeks' miejsc od początku kontenera.

	UWAGA: Indeks liczony jest od zera, od najmłodszej cegły.
	
	Przykład 1:
	Wyrażenie obj.insert(5,0) jest równoważne wyrażeniu obj.push(5)
	- element zawierający wartość 5 jest teraz najmłodszym
	elementem.
	Przykład 2:
	Wyrażenie obj.insert(3,obj.size()) czyni element zawierający
	wartosć 3 najstarszym elementem. 
*/
	void insert(int wartosc, int indeks);
/*!
	\brief Liczy z ilu cegiełek składa się kontener.

	Zainicjalizowany zostaje wskaźnik na strukturę 'cegla' 
	wskazujący na najmłodszą cegiełkę. Zostaje on potem wysłany
	w epicką podróż na sam koniec kontenera (czyli do napotkania
	NULLa). Towarzyszy mu licznik, który zlicza mijane po drodze
	cegiełki, których ilosć funkcja zwraca.

	\return Zwraca wielkość kontenera.
*/
	int size();
/*!
	\brief Usuwa z listy element o wybranym indeksie.

	Zainicjalizowane są dwa wskaźniki na najmłodszą cegiełkę.
	Jeden jest ustawiany na element do usunięcia, drugi na element
	o jeden młodszy. Następuje roszada wskaźników: wskaźnik
	młodszej cegły wskazuje na cegłę starszą od usuwanej, zostaje
	zapisana wartość przechowywana przez usuwaną cegłę i wreszcie
	zwolniona zostaje pamięć zajmowana dotychczas przez cegłę.

	Przykład 1:
	Wyrażenie obj.erase(0) usuwa najmłodszy element kontenera.
	Przykład 2:
	Wyrażenie obj.erase(obj.size() - 1) usuwa najstarszy element.
	Przykład 3:	
	Wyrażenie obj.erase(obj.size()) nie zmienia kontenera.
		 
	\return Zwraca wartość przechowywaną w usuniętej cegiełce.
*/
	int erase(int);
/*!
	\brief Odnajduje w kontenerze przekazaną w argumencie wartość.
	
	Powołany do życia jest szpieg - wskaźnik na obiekt typu 
	'cegla', który przemierza kontener w poszukiwaniu
	najwcześniejszego wystąpienia poszukiwanej wartości. Operacji
	towarzyszy licznik, który śledzi ilość miniętych przez wskaźnik
	cegieł, którą metoda zwraca. Należy ją interpretować jako
	indeks cegły, gdzie najwcześniej wystąpiła poszukiwana wartość.
	
	\return Zwraca indeks (liczony od 0 od najmłodszej cegiełki)
	najbliższego wystąpienia poszukiwanej wartości.
*/
	int find(int);
/*! 
	\brief Wypisuje elementy listy od najmłodszego zaczynając.
*/
	void show();
};
}

#endif
