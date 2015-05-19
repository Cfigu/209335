#include "BTree.h"

#include <iostream>

using namespace std;

int main()
{
  cout << "Podaj liczbe wezlow:  " << endl;
  int n;                   
  BTree * root;        
         

  cin >> n;
  
  root = czytaj(n);          
  // wypisz("","",root); 
  usun(root);   

  return 0;
} 
