#include "../inc/benchmark.h"


int main()
{
  int roz = 100;
  arr::Lista L;
  int p,k;
  p=0;
  k=roz;

  for(int i=100; i>0; --i)
    L.insert(i,-(i-100));

  L.show();

  L.sortuj(p,k);

  std::cout << std::endl;

  L.show();


}
