#include "ListaAr.h"

using namespace std;

/*!
*\file
*\brief Plik ListaAr.cpp
*
*Zawiera definicje metod klasy Ltab
*/


Ltab::Ltab()
{
  ilosc=0;
  max=1;
  tab=new long int;
}


Ltab::~Ltab()
{
  if(tab)
    delete [] tab;
}


void Ltab::add(const int& wart)
{
  long int* pom;
  ilosc=ilosc+1;
  pom=new long int[ilosc];

  if(tab)
  {
    for(int i=0; i<ilosc-1; i++)
      pom[i]= tab[i];
  }

  pom[ilosc-1]=wart;
  max=ilosc-1;
  if(tab)
    delete tab;

  tab=pom;
}


void Ltab::addx2(const int& wart)
{
  if(max>ilosc)
    {
      tab[ilosc] = wart;
    }
  else
    {
      max = max*2;
      long int* pom = new long int[max];
      for(int i=0; i<ilosc; i++){
	pom[i] = tab[i];
      }

      delete [] tab;
  
      tab = pom;
 
      tab[ilosc] = wart;
    }
  ++ilosc;
}


Ltab::Ltab(const Ltab & w)
{
  tab = new long int [w.ilosc];
  for(int i=0; i<w.ilosc; i++)
    tab[i]=w.tab[i];
  ilosc= w.ilosc;
  max=w.max;
}


void Ltab::wypisz()
{
  for(int i=0; i < ilosc; i++)
    cout << tab[i] << endl;
}


Ltab& Ltab::operator=(const Ltab & w)
{
  ilosc=w.ilosc;
  max=w.max;

  for(int i=0; i<w.ilosc; ++i)
    tab[i]=w.tab[i];
  return *this;
}


long int& Ltab::operator[](unsigned int index)
{
  return tab[index];
}


int Ltab::dziel(int lewo, int prawo)
{
  int v,pom,i,j;
  long int* temp = new long int[ilosc];

  if(tab)
    {
      for(int k=0; k<ilosc; k++)
	temp[k]= tab[k];
    }

  delete [] tab;

  v=temp[lewo];
  i=lewo;
  j=prawo+1;

  while(i<j)
    {
      while(temp[++i]<v);
      while(v<temp[--j]);
      if(i<j)
	{
	  pom=temp[i];
	  temp[i]=temp[j];
	  temp[j]=pom;
	}
    }
  
  temp[lewo]=temp[j];
  temp[j]=v;

   tab=temp;

  return j;
}

int Ltab::dziel2(int lewo, int prawo)
{
  int v,pom,i,j;

  long int *temp = new long int[ilosc];

 if(tab)
    {
      for(int k=0; k<ilosc; k++)
	temp[k]= tab[k];
    }

 delete [] tab;

 if( (lewo+prawo)%2 != 0)
   {
     if(temp[lewo] < temp[(lewo+prawo+1)/2])
       {
	 if(temp[(lewo+prawo+1)/2] < temp[prawo])
	   v=temp[(lewo+prawo+1)/2];
	 else if(temp[lewo] < temp[prawo])
	   v=temp[prawo];
	 else
	   v=temp[lewo];
       }
     else
       {
	 if(temp[(lewo+prawo+1)/2] > temp[prawo])
	   v=temp[(lewo+prawo+1)/2];
	 else if(temp[lewo] > temp[prawo])
	   v=temp[prawo];
	 else
	   v=temp[lewo];
       }
   }
 else
   {
     if(temp[lewo] < temp[(lewo+prawo)/2])
       {
	 if(temp[(lewo+prawo)/2] < temp[prawo])
	   v=temp[(lewo+prawo)/2];
	 else if(temp[lewo] < temp[prawo])
	   v=temp[prawo];
	 else
	   v=temp[lewo];
       }
     else
       {
	 if(temp[(lewo+prawo)/2] > temp[prawo])
	   v=temp[(lewo+prawo)/2];
	 else if(temp[lewo] > temp[prawo])
	   v=temp[prawo];
	 else
	   v=temp[lewo];
       }
   }

  i=lewo;
  j=prawo+1;

  while(i<j)
    {
      while(temp[++i]<v);
      while(v<temp[--j]);
      if(i<j)
	{
	  pom=temp[i];
	  temp[i]=temp[j];
	  temp[j]=pom;
	}
    }
  
  temp[lewo]=temp[j];
  temp[j]=v;

  tab=temp;

  return j;
}

void Ltab::sortuj(int lewo,int prawo)
{
   if(lewo<prawo)
    {
      int p = this->dziel(lewo,prawo);
      this->sortuj(lewo,p-1);
      this->sortuj(p+1, prawo);
    }

}

void Ltab::sortuj_opt(int lewo, int prawo)
{
   if(lewo<prawo)
    {
      int p = this->dziel2(lewo,prawo);
      this->sortuj_opt(lewo,p-1);
      this->sortuj_opt(p+1, prawo);
    }

}


void Ltab::sort_wst()
{
  int j,i,temp, roz=ilosc;
  long int *pom;
  pom = new long int[ilosc];

  if(tab)
    {
      for(int k=0; k<ilosc; k++)
	pom[k]= tab[k];
    }
  
  delete [] tab;

  for(j = roz-2; j>=0;--j)
    {
      temp = pom[j];
      i = j + 1;

      while((i < roz) && (temp > pom[i]))
	{
	  pom[i - 1] = pom[i];
	  i++;
	}

      pom[i - 1] = temp;
    }
  
  tab =pom;
}
