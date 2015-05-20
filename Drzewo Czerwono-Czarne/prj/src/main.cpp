#include "RBTree.h"


using namespace std;

/*!
*\file
*\brief Plik main.cpp
*
*Zawiera program glowny.
*
*Program pokazuje 2 drzewa. MAX to liczba wezlow.
*Pierwsze drzewo ma MAX wezlow, a drugie ma o polowe mniej.
*Do zrobienia drugiego drzewa wykorzystywana jest metoda usunRBT
*/


int main()
{

  const int MAX = 30;   
  int T[MAX];          
  int i,x,i1,i2;
  RBTree * R;         

  R = new RBTree;     

  for(i = 0; i < MAX; i++) 
    T[i] = i + 1;

  for(i = 0; i < MAX; i++)
  {
    cout << T[i] << " ";
    R->wstawRBT(T[i]);
  }

  cout << endl << endl;

  R->pokaz();             

  cout << endl << endl;
 
  for(i = 0; i < MAX/2 ; i++) // Usuwamy połowę węzłów
  {
    cout << T[i] << " ";
    R->usunRBT(R->szukajRBT(T[i]));
  }

  cout << endl << endl;

  R->pokaz();            

  delete R;          

  return 0;
} 
