#include "metmain.h"

using namespace std;

/*!
*\file
*\brief Plik zawiera definicje funkcji wykonywanych w main.cpp
*
*/

void WypListe(Lista A)
{
  clock_t czas1, czas2;
  clock_t czas[10];
  int roz;
     
  cout << "Podaj rozmiar struktury: " << endl;
  cin >> roz;
  
  for(int j=0; j<10; j++)   
    {
      
      czas1=clock();             //czas poczatkowy
      
      for(int i=0; i<roz; i++)   //petla wypelniajaca strukture
	{
	  A.push_front(i);
	}
      
      czas2=clock();             //czas koncowy
      
      
      czas[j]=czas2-czas1;       //roznica czasu koncowego i poczatkowego, czyli czas obliczen
      
      
      for(int i=0; i<roz; i++)   //petla czyszczaca strkture
	{
	  A.pop_front();
	}
      
	}
  
  cout << "Tablica czasow" << endl;
  wyswietl(czas, 10);
  
  cout << "Sredni czas" <<endl;
  cout << (czas[0]+czas[1]+czas[2]+czas[3]+czas[4]+czas[5]+czas[6]+czas[7]+czas[8]+czas[9])/10 << endl;
}
 
void WypKolejke(Kolejka K)
{
  clock_t czas1, czas2;
  clock_t czas[10];
  int roz; 
  
  cout << "Podaj rozmiar struktury: " << endl;
  cin >> roz;
  
  for(int j=0; j<10; j++)
    {
      
      czas1=clock();             //czas poczatkowy
      
      for(int i=0; i<roz; i++)   //petla wypelniajaca strukture
	{
	  K.push_k(i);
	}
      
      czas2=clock();             //czas koncowy
      
      czas[j]=czas2-czas1;        //roznica czasu koncowego i poczatkowego, czyli czas obliczen

      for(int i=0; i<roz; i++)   //petla czyszczaca strkture
	{
	  K.pop_k();
	}
    }
  
  cout << "Tablica czasow" << endl;
  wyswietl(czas, 10);
  
  cout << "Sredni czas" <<endl;
  cout << (czas[0]+czas[1]+czas[2]+czas[3]+czas[4]+czas[5]+czas[6]+czas[7]+czas[8]+czas[9])/10 << endl;
}
 

void WypStos(Stos S)
{
  clock_t czas1, czas2;
  clock_t czas[10];
  int roz; 

  
  cout << "Podaj rozmiar struktury: " << endl;
  cin >> roz;
  
  for(int j=0; j<10; j++)
    {
      
      czas1=clock();             //czas poczatkowy
      
      for(int i=0; i<roz; i++)   //petla wypelniajaca strukture
	{
	  S.push_s(i);
	}
      
      czas2=clock();             //czas koncowy
      
      czas[j]=czas2-czas1;       //roznica czasu koncowego i poczatkowego, czyli czas obliczen
      
      for(int i=0; i<roz; i++)   //petla czyszczaca strkture
	{
	  S.pop_s();
	}
    }
  
  cout << "Tablica czasow" << endl;
  wyswietl(czas, 10);
  
  cout << "Sredni czas" <<endl;
  cout << (czas[0]+czas[1]+czas[2]+czas[3]+czas[4]+czas[5]+czas[6]+czas[7]+czas[8]+czas[9])/10 << endl;
}

    
  
      
