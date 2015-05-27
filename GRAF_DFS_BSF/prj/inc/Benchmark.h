#ifndef BENCHMARK_H
#define BENCHMARK_H

#include "operacja.h"
#include "graff.h"
#include <list>
#include <ctime>
#include <cstdlib>
#include <unistd.h>


using namespace std;

/*!
*\file
*\brief Plik naglowkowy Benchmark.h
*
*Zawiera klasy Obserwowany,Obserwator,Dane oraz PobieraczDanych i ich metody
*/


/*! 
   *\brief Deklaracja klasy Obserwowany
   *
   */

class Obserwowany;

/*! 
   *\brief Deklaracja klasy Dane
   *
   *Jest to obserwator
   */

class Dane{
 public:
  virtual void update(Obserwowany*) = 0;
};


/*! 
   *\brief Definicja klasy Obserwowany
   *
   *Prywatnie zawiera liste wskaznikow na obserwatorow typu Dane
   */

class Obserwowany
{
 private:
  list <Dane*> lista;
  
 public:

/*! 
   *\brief Wirtualny destruktor klasy Obserwowany
   *
   */

  virtual ~Obserwowany(){}
  
/*! 
   *\brief Wirtualna funkcja dodajaca obserwatora
   *
   *\param[in] o - dodawany obserwator typu Dane*
   */

  virtual void dodaj(Dane *o)
  {
    lista.push_back (o);
  }
  
/*! 
   *\brief Wirtualna funkcja usuwajaca obserwatora
   *
   *\param[in] o - usuwany obserwator typu Dane*
   */

  virtual void usun(Dane *o)
  {
    lista.remove (o);
  }
  
/*! 
   *\brief Wirtualna funkcja przekazujaca dane do wszystkicj obserwatorow
   *
   */
  
  virtual void przekaz()
  {
    list<Dane*>::iterator it = lista.begin();
    for( ; it != lista.end(); it++){
      (*it)->update(this);
    }
  }
};

/*! 
   *\brief Definicja klasy Obserwator
   *
   *Prywatnie zawiera dwa czasy typu clock_t oraz inforamcje typu string
   */

class Obserwator : public Obserwowany {
 private:
  clock_t czas1;
  clock_t czas2;
  string info;
  
 public:

/*! 
   *\brief Konstruktor klasy Obserwator
   *
   */

  Obserwator();

/*! 
   *\brief Metoda getczas1()
   *
   *\return Zwraca czas1
   */

  clock_t getczas1();

/*! 
   *\brief Metoda getczas2()
   *
   *\return Zwraca czas2
   */

  clock_t getczas2();

/*! 
   *\brief Metoda getinfo()
   *
   *\return Zwraca info
   */

  string getinfo();

/*! 
   *\brief Metoda Benchamark
   *
   *Metoda przechodzi zadany graf algortymem DFS lub BSF w zaleznosci od parametru opcja
   *
   *\param[in] A - Garf na ktorym wykonwana jest zadana operacja z pliku operacja.cpp
   *\param[in] poczatek - poczatek grafu z ktorego znaczyamy przechodzenie
   *\param[in] opcja - =1 jesli chcemy algorytm DFS lub =2 jesli chcemy algorytm BSF	
   */


  void Benchmark(Graf A, int poczatek, int opcja);

/*! 
   *\brief Metoda ustaw
   *
   *Metoda ustawia w czas1, czas2 oraz info
   *
   *\param[in] c1,c2 - c1 odpowiada czas1, a c2 odpowiada czas2
   *\param[in] i - odpowiada info
   */


  void ustaw(clock_t c1, clock_t c2, string i);
};



/*! 
   *\brief Definicja klasy PobieraczDanych
   *
   *Zawiera jedna metode wirtualna ktora uaktualnia dane w Obserwatorach
   *oraz wypisuje noew dane. Kazdy obserwator wypisuje raz swoje dane.
   */

class PobieraczDanych: public Dane {
 public:
  virtual void update(Obserwowany* O) 
  {
    double t;
    Obserwator *d = dynamic_cast<Obserwator *>(O);
    if (d) {
      cout << "czas1:  " << d->getczas1() << endl;
      cout << "czas2:  " << d->getczas2() << endl;
      cout << "INFO:   " << d->getinfo() << endl;
      t = (double)(d->getczas2()-d->getczas1())/CLOCKS_PER_SEC;
      cout << "Czas:  " << endl;
      cout << t << endl << endl;	
    }
  }
};



 




#endif
