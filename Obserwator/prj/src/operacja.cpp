#include "operacja.h"

/*!
*\file
*\brief Plik operacja.cpp
*
*Zawiera definicje funkcji operacja wykonywanej na liscie.
*/

Ltab operacja(Ltab A, int l, int p)
{
  A.sort_hybr(l,p);

  return A;
}
