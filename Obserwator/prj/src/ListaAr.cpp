#include "ListaAr.h"
#include <cstdlib>

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
  tab=new int;
}


Ltab::~Ltab()
{
  if(tab)
    delete [] tab;
}


void Ltab::add(const int& wart)
{
  int* pom;
  ilosc=ilosc+1;
  pom=new int[ilosc];

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
      int* pom = new int[max];
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
  tab = new int [w.ilosc];
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


int& Ltab::operator[](unsigned int index)
{
  return tab[index];
}


int Ltab::dziel(int lewo, int prawo)
{
  int v,pom,i,j;
  int* temp = new int[ilosc];

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

  int *temp = new int[ilosc];

 if(tab)
    {
      for(int k=0; k<ilosc; k++)
	temp[k]= tab[k];
    }

 delete [] tab;


 /*
 //if( (lewo+prawo)%2 != 0)
 // {
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
     // }
      else
   {
 */

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
  int *pom;
  pom = new int[ilosc];

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


void Ltab::scal(int lewo, int srodek, int prawo) 
{
  int i, j;

  int *pom,*temp;
  temp = new int[ilosc];
  pom = new int[ilosc];
  
  if(tab)
    {
      for(int k=0; k<ilosc; k++)
	temp[k]= tab[k];
    }

  delete [] tab;
 
  for(i = srodek + 1; i>lewo; i--) 
    pom[i-1] = temp[i-1]; 
 
  for(j = srodek; j<prawo; j++) 
    pom[prawo+srodek-j] = temp[j+1]; 
 
  for(int k=lewo;k<=prawo;k++) 
    if(pom[j]<pom[i])
      temp[k] = pom[j--];
    else
      temp[k] = pom[i++];

  tab=temp;
}
 
void Ltab::sort_scal(int lewo, int prawo)
{
  int srodek;

  if(prawo<=lewo) return; 
 
  srodek = (prawo+lewo)/2;
 
  sort_scal(lewo, srodek); 
  sort_scal(srodek+1, prawo);
 
  scal(lewo, srodek, prawo);
}

void Ltab::sortuj_QS_wst(int lewo, int prawo)
{
  if(lewo<prawo)
    {
      this->dziel(lewo,prawo);
      this->sort_wst();
    }

}

void Ltab::sort_hybr(int lewo,int prawo)
{
  if( prawo+1 < 100)
    this->sort_wst();
  else
    {
      this->sortuj_QS_wst(lewo,prawo);
    } 
}

void Ltab::wypelnij_losowymi(int roz)
{
  int T[roz];

  for(int i=0;i<roz;++i)
    T[i]=rand()%1000;
  
  for(int i=0;i<roz;++i)
    this->addx2(T[i]);
}

void Ltab::wypelnij_odwrotnie(int roz)
{
  int T[roz];

  for(int i=roz; i>0; --i)
    T[i]=i;
  
  for(int i=0;i<roz;++i)
    this->addx2(T[i]);

}

void Ltab::wypelnij_posortowane(int roz)
{
  int T[roz];

  for(int i=0; i<roz; ++i)
    T[i]=i;
  
  for(int i=0;i<roz;++i)
    this->addx2(T[i]);
}
