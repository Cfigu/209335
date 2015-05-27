#ifndef OPERACJA_H
#define OPERACJA_H

#include "graff.h"

/*!
*\file
*\brief Plik naglowkowy operacja.h
*
*Zawiera funkcje ktora wykonuje zadana operacje na Grafie
*/


/*! 
   *\brief Funkcja operacja
   *  
   *Wykonuje zadana operacje na grafie
   *
   *\param[in] A - Zadany graf o dowolnej ilosci wierzcholkow i krawedzi
   *\param[in] poczatek - wierzcholek z ktorego zaczynamy przechodzenie Grafu
   *\param[in] opcja - =1 gdy DFS =2 gdy BSF
   */

void operacja(Graf A, int poczatek, int opcja);
#endif
