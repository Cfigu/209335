#include "../inc/lista_arr.h"

bool arr::Lista::empty()
{
  return(this->rozmiar_ls == 0);
}

int arr::Lista::erase(int indeks)
{
  int zwracana = this->tablica[indeks];
  // Zmniejszanie indeksu częśći elementów o 1
  for(int i = indeks; i < this->rozmiar_ls; ++i)
    this->tablica[i] = this->tablica[i+1];
  --this->rozmiar_ls;
  return zwracana;
}

void arr::Lista::insert(int value, int indeks)
{
  // W razie braku miejsca na nowy element - rozszerzyć listę.
  if(this->rozmiar_ls == this->pojemnosc_ls)
    this->rozszerz_1();
  // Specjalne traktowanie na wypadek, gdy pusta
  if(this->empty())
    {
      tablica[0] = value;
      ++this->rozmiar_ls;
    }
  else
    {
      // Podnoszenie indeksu częśći elementów o 1
      for(int i = this->rozmiar_ls; i > indeks; --i)
	this->tablica[i] = this->tablica[i-1];
      // Wstawianie nowej wartości w odpowiednie miejsce
      tablica[indeks] = value;
      ++this->rozmiar_ls;
    }
}

void arr::Lista::rozszerz_x2()
{
  // Rezerwacja nowego bloku pamięci
  int *temp = new int[this->rozmiar_ls*2];
  // Kopiowanie dotychczas przechowywanych elementów
  for(int i = 0; i < this->rozmiar_ls; ++i)
    temp[i] =this->tablica[i];
  // Zwalnianie dotychczas używanej pamięci
  delete [] this->tablica;
  // Teraz tablica wskazywać będzie na nowy obszar
  this->tablica = temp;
  // Aktualizowanie wartości pojemności stosu
  this->pojemnosc_ls *= 2;
}

void arr::Lista::rozszerz_1()
{
  // Rezerwacja nowego bloku pamięci
  int *temp = new int[this->rozmiar_ls + 1];
  // Kopiowanie dotychczas przechowywanych elementów
  for(int i = 0; i < this->rozmiar_ls; ++i)
    temp[i] =this->tablica[i];
  // Zwalnianie dotychczas używanej pamięci
  delete [] this->tablica;
  // Teraz tablica wskazywać będzie na nowy obszar
  this->tablica = temp;
  // Aktualizowanie wartości pojemności stosu
  ++this->pojemnosc_ls;
}



int arr::Lista::dziel(int lewo, int prawo)
{
  int v,pom,i,j;
  
  v=this->tablica[lewo];
  i=lewo;
  j=prawo+1;

  while(i<j)
    {
      while(this->tablica[++i]<v);
      while(v<this->tablica[--j]);
      if(i<j)
	{
	  pom=this->tablica[i];
	  this->tablica[i]=this->tablica[j];
	  this->tablica[j]=pom;
	}
    }
  
  this->tablica[lewo]=this->tablica[j];
  this->tablica[j]=v;

  return j;
}

int arr::Lista::dziel2(int lewo, int prawo)
{
  int v,pom,i,j;

  if(this->tablica[lewo] < this->tablica[(lewo+prawo)/2])
    {
      if(this->tablica[(lewo+prawo)/2] < this->tablica[prawo])
	v=this->tablica[(lewo+prawo)/2];
      else if(this->tablica[lewo] < this->tablica[prawo])
	v=this->tablica[prawo];
      else
	v=this->tablica[lewo];
    }
  else
    {
      if(this->tablica[(lewo+prawo)/2] > this->tablica[prawo])
	v=this->tablica[(lewo+prawo)/2];
      else if(this->tablica[lewo] > this->tablica[prawo])
	v=this->tablica[prawo];
      else
	v=this->tablica[lewo];
    }

   
  i=lewo;
  j=prawo+1;

  while(i<j)
    {
      while(this->tablica[++i]<v);
      while(v<this->tablica[--j]);
      if(i<j)
	{
	  pom=this->tablica[i];
	  this->tablica[i]=this->tablica[j];
	  this->tablica[j]=pom;
	}
    }
  
  this->tablica[lewo]=this->tablica[j];
  this->tablica[j]=v;

  return j;
}

void arr::Lista::sortuj(int lewo,int prawo)
{
   if(lewo<prawo)
    {
      int p = this->dziel(lewo,prawo);
      this->sortuj(lewo,p-1);
      this->sortuj(p+1, prawo);
    }

}

void arr::Lista::sortuj_opt(int lewo, int prawo)
{
   if(lewo<prawo)
    {
      int p = this->dziel2(lewo,prawo);
      this->sortuj(lewo,p-1);
      this->sortuj(p+1, prawo);
    }

}

void arr::Lista::operacja_licz_qs(int roz)
{
  int p=0;
  clock_t czasA, czasB;
  double t[10];
  
  std::cout << "QS bez optymalizacji" << std::endl;

  for(int j=0; j<10;++j)
    {
      
      for(int i=roz; i>-1; i--)
      	this->insert(i,-(i-roz));
      
      czasA = clock();
      
      this->sortuj(p,roz);
      
      czasB = clock();
      
      t[j]= (double)(czasB-czasA)/CLOCKS_PER_SEC;
      
      for(int k=0; k<roz;++k)
	this->erase(k);
      
      std::cout << t[j] << std::endl;
    }
  std::cout << std::endl;
  std::cout << "Sredni czas w sekundach   " << std::endl;
 
  std::cout << (t[0]+t[1]+t[2]+t[3]+t[4]+t[5]+t[6]+t[7]+t[8]+t[9])/10 << std::endl;
}


void arr::Lista::operacja_licz_qs_opt(int roz)
{
  int p=0;
  clock_t czasA, czasB;
  double t[10];

  std::cout << "QS z optymalizacja" << std::endl;

  for(int j=0; j<10;++j)
    {
      
      for(int i=roz; i>-1; i--)
      	this->insert(i,-(i-roz));
      
      czasA = clock();
      
      this->sortuj_opt(p,roz);
      
      czasB = clock();
      
      t[j]= (double)(czasB-czasA)/CLOCKS_PER_SEC;
      
      for(int k=0; k<roz;++k)
	this->erase(k);
      
      std::cout << t[j] << std::endl;
    }
  std::cout << std::endl;
  std::cout << "Sredni czas w sekundach:   " << std::endl;
 
  std::cout << (t[0]+t[1]+t[2]+t[3]+t[4]+t[5]+t[6]+t[7]+t[8]+t[9])/10 << std::endl;
}