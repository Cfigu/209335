#include "../inc/benchmark.h"
#include <cstdlib>

int main()
{
  int roz = 0;
  std::cout << "Podaj rozmiar: " << std::endl;
  std::cin >> roz;
  std::cout << std::endl;
  arr::Lista L,K;



 L.operacja_licz_qs(roz);
 std::cout << std::endl << std::endl << std::endl;
 K.operacja_licz_qs_opt(roz);
}


