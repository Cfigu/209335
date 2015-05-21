#ifndef GRAF_H
#define GRAF_H
#include "ListaAr.h"
#include "Stos.h"
#include <iostream>

using namespace std;

class Graf {
private:

Ltab *A;
int v;

public:
Graf();
void stworz(int v, int e);
void DFS(int p);


};















#endif
