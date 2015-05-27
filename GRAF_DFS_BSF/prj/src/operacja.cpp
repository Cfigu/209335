#include "operacja.h"


/*!
*\file
*\brief Plik operacja.cpp
*
*Zawiera definicje funkcji operacja wykonywanej na liscie.
*/

void operacja(Graf A,int poczatek, int opcja)
{
  if(opcja==1)
      A.DFS(poczatek);
  else if(opcja==2)
    A.BSF(poczatek);

}
