#include "ListaAr.h"
#include "Stos.h"

using namespace std;

int main()
{

  int v,e;
  int v1,v2;
  Stos S;

  cout << "DFS" <<endl << endl;
  cout << "Podaj ilosc wierzcholkow:   " << endl;
  cin >> v;
  cout << "Podaj ilosc krawedzi:   " << endl;
  cin >> e;

  bool * visited = new bool [v];
  Ltab * A;

  A = new Ltab [v];

  cout << "Podaj krwawedzie na zasadzie:  " << endl;
  cout << "Jesli wierzcholek 3 laczy sie z 7 to wpisz " << endl;
  cout << "3 7" << endl << endl;

  for(int i = 0; i < e; i++)
    {
      cin >> v1;
      cin >> v2;
      
      A[v1].add(v2);

      if(v1 != v2)
	A[v2].add(v1);
    }

  for(int i=0; i<v; i++)
    visited[i]=false;

  cout << "Podaj wierzcholek startowy:   " << endl;
  cin >> v1;

  S.push_s(v1);

  while(!S.empty_s())
    {
      v1=S.top();
      S.pop_s();

      if(!visited[v1])
	{
	  visited[v1] = true;
	 
	  cout << "Nie odwiedzeni sasiedzi wierzcholka " << v1 << endl;

	  for(int i=0; i<A[v1].ile(); i++)
	    {
	      if(!visited[A[v1].element(i)])
		{
		  v2=A[v1].element(i);
		  S.push_s(v2);
		  cout << A[v1].element(i) << "  "; 
		}
	    }
	  cout << endl;
	  //cout << v1 << "  " ;
	}
    }
  cout << endl;

  

}

