/*!	\file ustawienia.h
	\brief Plik zawiera stałe preprocesora związane z generowaniem, obróbką i pomiarem właściwości danych.

	Makra zawarte w tym pliku służą do sterowania pracą programu
	generującego dane oraz programu, który te dane przetwarza.
	Służy też synchronizacji pomiędzy tymi dwoma programami
	poprzez ujednolicenie nazwy pliku zawierającego dane. 
*/

#ifndef USTAWIENIA_H
#define USTAWIENIA_H

/*! Określa dłuość ciągu danych stworzonych przez program generuj. */
#define ILOSC 1e2
/*! Określa największą możliwą liczbę do wygenerowania. */
#define KRES_GORNY 100//INT_MAX/2 - 1
/*! Określa najmniejszą możliwą liczbę do wygenerowania. */
#define KRES_DOLNY 0 
/*! Określa jak nazywa się plik wygenerowany przez program 'generuj', jednocześnie pliku o tej nazwie poszukuje program 'program' w katalogu, w którym został uruchomiony. */
#define NAZWA_PLIKU_WE "dane.dat"
/*! Tak nazywać się będzie wygenerowany przez program 'program' plik z wynikami przeprowadzonych pomiarów.*/
#define NAZWA_PLIKU_WY "arr_lista_1.dat"
/*! Tyle razy zostanie powtórzoy pomiar dla jednego zestawu danych. */
#define ILOSC_POWTORZEN 10

#endif
