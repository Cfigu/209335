#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <ctime>

#include "funkcje.cpp"



using namespace std;

void wyswietl(int t[], int roz);
void zpliku(string nazwa, int t[], int roz);
void wypelnij(int t[], int roz);
void dopliku(string nazwa, int t[], int roz);


void pomnoz(int t[], int roz);

/*!
*\file
*\brief Program oblicza sredni czas wykonywnych obliczen
*
*Uzytkownik podaje wielkosc tablicy liczb typu int(max 1 000 000)
*Jezeli uzytkownik poda rozmiar tablicy wiekszy niz 1 000 000 program konczy dzialanie
*Jezeli rozmiar jest poprawny, program tworzy tablice losowych liczb o zadanym rozmiarze
*Nastepnie mnozy kazdy element w tablicy razy 2 i liczy czas jaki zajelo wykonanie obliczen. Ta operacje powtarza 10 razy
*Na koniec oblicza sredni czas wykonywania obliczen
*/


int main()
{
	
int rozmiar;
clock_t czas[10];
clock_t czas1;
clock_t czas2;
int rozmiargood=0;

cout << "Podaj rozmiar tablicy" << endl;
cin >> rozmiar;


if(rozmiar>1000000)
{
cout << "Zbyt duzy rozmiar. Maksymalny rozmiar tablicy to 1 000 000" << endl;
}
else
{
rozmiargood=1;
}

if(rozmiargood==1)
{

int tab[rozmiar];

//Te funkcje sa odkomentowane tylko do czasu az zapelnimy plik tablica.txt 1 000 000 liczb

//wypelnij(tab, rozmiar);

//dopliku("tablica.txt", tab, rozmiar);

zpliku("tablica.txt", tab, rozmiar);

for(int i=0; i<10; i++)
{

czas1 = clock();

pomnoz(tab, rozmiar);

czas2 = clock();

czas[i]=czas2-czas1;
}


cout << "Tablica czasow" << endl;
wyswietl(czas, 10);

cout << "Sredni czas" <<endl;
cout << (czas[0]+czas[1]+czas[2]+czas[3]+czas[4]+czas[5]+czas[6]+czas[7]+czas[8]+czas[9])/10 << endl;

}
}




