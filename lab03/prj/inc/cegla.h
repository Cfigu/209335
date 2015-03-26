/*!
	\file cegla.h
	\brief Plik zawiera definicję struktury pomocniczej cegla.
*/

#ifndef CEGLA_H
#define CEGLA_H

/*!
	\brief Struktura pomocnicza cegla

	Struktura reprezentuje elementarną cząstkę kontenera - zawiera
	daną oraz wskaźnik do kolejnego elementu w kontenerze.
*/
struct cegla
{
	int dana;
	cegla *nastepna;
	cegla():nastepna(NULL){}
};

#endif
