#include "ListaAr.h"
#include <ctime>


using namespace std;

int main()
{
  int roz=100;
  Ltab A;
  clock_t czas1,czas2;
  double t;
  int l=0;
  int p=roz-1;

  for(int i=roz; i>0; --i)
    A.addx2(i);

  if(roz==100)
    A.wypisz();

  cout << endl;

  czas1=clock();
  A.sortuj_opt(l,p);
  czas2=clock();

  t = (double)(czas2-czas1)/CLOCKS_PER_SEC;
  cout << "Czas:  " << endl;
  cout << t << endl << endl;

  if(roz==100)
    A.wypisz();

}
