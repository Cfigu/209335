#include "Benchmark.h"

using namespace std;

/*!
*\file
*\brief Plik Benchmark.cpp
*
*Zawiera definicje metod klas Obserwator, Obserwowany.
*/

Obserwator::Obserwator() 
{
  czas1=0;
  czas2=0;
  info="";
}
  

clock_t Obserwator::getczas1() 
{
  return czas1;
}
  
clock_t Obserwator::getczas2() 
{
  return czas2;
}

string Obserwator::getinfo()
{
  return info;
}

void Obserwator::ustaw(clock_t c1, clock_t c2, string i)
{
  czas1 = c1;
  czas2 = c2;
  info = i;
}


Ltab Obserwator::Benchmark(Ltab A, int l, int p)
{
  clock_t cz1,cz2;
  string i;

  cz1 =clock();
 
  A = operacja(A,l,p);

  cz2 = clock();
  i= "Dodano nowe dane";
  ustaw(cz1,cz2,i);
  przekaz();
  
  return A;
}




























/*
Obserwowany::Obserwowany()
{
  ile=0;
  lista = new Obserwator;
}

Obserwowany::~Obserwowany()
{
  if(lista)
    delete lista;
}

Ltab Obserwowany::Benchmark(Ltab A, int l, int p)
{
  clock_t czas1,czas2;
  double t;

  czas1 =clock();
 
  A = operacja(A,l,p);

  czas2 = clock();
  
  string info = "Dodano nowe dane";
  this->PrzekazDane(czas1,czas2,info);

  t = (double)(czas2-czas1)/CLOCKS_PER_SEC;
  cout << "Czas:  " << endl;
  cout << t << endl << endl;
  cout << czas1 << "   " << czas2 << endl;

  return A;
}

void Obserwowany::DodajObserwatora(Obserwator& O)
{
  ile=ile+1;
  Obserwator **pom;
  //pom=new Obserwator[ile];
  
  if(lista)
    {
      for(int i=0; i<ile-1; i++)
	pom[i]= lista[i];
    }
  pom[ile-1]=O;
  
  if(lista)
    delete lista;

  lista = pom;
}
void Obserwowany::UsunObserwatora(Obserwator O)
{
  ile=ile-1;
  Obserwator *pom;
  pom=new Obserwator[ile];
  
  if(lista)
    {
      for(int i=0; i<ile+1; i++)
	if(lista[i]==O)
	  ;
	else
	  pom[i]= lista[i];
    }

  if(lista)
    {
      for(int i=0; i<ile; i++)
	lista[i]= pom[i];
    }
}


void Obserwowany::PrzekazDane(clock_t czas1, clock_t czas2, string info)
{
  if(lista)
    {
      for(int i=0; i<ile; i++)
	{
	  lista[i]->ZapiszCzas1(czas1);
	  lista[i]->ZapiszCzas2(czas2);
	  lista[i]->ZapiszInfo(info);  

	}
    }
}

Obserwator* Obserwowany::operator[](unsigned int wart)
{
  return lista[wart];
}






void Obserwator::WypiszDane()
{
  double t;
  cout << info << endl;
  cout << czas1 << "    " << czas2 << endl;
  t = (double)(czas2-czas1)/CLOCKS_PER_SEC;
  cout << "Czas:  " << endl;
  cout << t << endl << endl;
}







Obserwator::Obserwator()
{
  czas1=0;
  czas2=0;
  info ="";
}

void Obserwator::ZapiszCzas1(const clock_t czas)
{
  czas1 = czas;
}

void Obserwator::ZapiszCzas2(const clock_t czas)
{
  czas2 = czas;
}

void Obserwator::ZapiszInfo(string informacja)
{
  info = informacja;
}


bool Obserwator::operator==(Obserwator O)
{
  if(info == O.info && czas1 == O.czas1 && czas2 == O.czas2)
    return true;
  else
    return false;
}

void Obserwator::operator=(Obserwator O)
{
  czas1 = O.czas1;
  czas2 = O.czas2;
  info = O.info;
}

*/
