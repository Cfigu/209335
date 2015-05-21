#include "graff.h"

using namespace std;

Graf::Graf()
{
  v=0;
  A = new Ltab;
}

void Graf::stworz(int w, int e)
{
  v=w;
  int v1,v2;

  Ltab * pom;
  pom = new Ltab[w];

  cout << "Podaj krwawedzie na zasadzie:  " << endl;
  cout << "Jesli wierzcholek 3 laczy sie z 7 to wpisz " << endl;
  cout << "3 7" << endl << endl;

  for(int i = 0; i < e; i++)
    {
      cin >> v1;
      cin >> v2;
      
      pom[v1].add(v2);
      
      if(v1 != v2)
	pom[v2].add(v1);
    }

  A=pom;

}

void Graf::DFS(int p)
{
  bool visited[v];
  Stos S;
  int pom;

  for(int i=0; i<v; i++)
    visited[i]=false;

  S.push_s(p);

  while(!S.empty_s())
    {
      p=S.top();
      S.pop_s();

      if(!visited[p])
	{
	  visited[p] = true;
	 
	  cout << "Nie odwiedzeni sasiedzi wierzcholka " << p << endl;

	  for(int i=0; i<A[p].ile(); i++)
	    {
	      if(!visited[A[p].element(i)])
		{
		  pom=A[p].element(i);
		  S.push_s(pom);
		  cout << A[p].element(i) << "  "; 
		}
	    }
	  cout << endl;
	  //cout << v1 << "  " ;
	}
    }
}
