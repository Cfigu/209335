#include<iostream>
#include<ctime>
#include<cstdio>
#include "Kolejka.cpp"
#include "Kolejka.h"
#include "Stos.cpp"
#include "Stos.h"
#include "Lista.cpp"
#include "Lista.h"
#include "funkcje.cpp"

using namespace std;

/*!
*\file
*\brief Program oblicza sredni czas tworzenia wybranej struktury danych
*
*Uzytkownik wybiera jaka strukture chce wypelnic i jaka iloscia elementow.
*Program wykonuje polecenia 10 razy, oblicza czas kazdego z nich, a nastepnie oblicza czas sredni.
*/

int main() {

  int opcja=0;
  int roz;
  clock_t czas[10];
  clock_t czas1;
  clock_t czas2;
  Lista A;
  Kolejka K;
  Stos S;



  cout << "Wybierz jaka strkture chcesz wypelnic:" << endl << endl;
  cout << "1.Lista" << endl;
  cout << "2.Kolejka" << endl;
  cout << "3.Stos" << endl;
  cout << "0.Zakoncz program" << endl;
  cin >> opcja;
 
  
  switch(opcja)
    {
   
    case 0:
      break;
      
    case 1:
     
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
      break;
       
    case 2:
      
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
      break;
  
    case 3:

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
      break;

    }
    }
    
  
      
