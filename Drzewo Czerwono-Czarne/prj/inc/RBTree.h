#ifndef RBTREE_H
#define RBTREE_H


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

/*!
*\file
*\brief Plik naglowkowy RBTree.h
*
*Zawiera strukture wezla RBT i klase jako cale drzewo RBTree
*/


/*!
*
*\brief Definicja wezla drzewa
*
*Zawiera wskazniki typu RBT na wezel wyjezj(up) na lewego(left) i prawego(right) syna
*oraz klucz i kolor wezla.
*/


struct RBT
{
  RBT * up;
  RBT * left;
  RBT * right;
  int klucz;
  char kolor;
};

/*!
*
*\brief Definicja klasy RBTree czyli drzewa czerwono-czarnego
*
*Zawiera prywatnie: wezel straznika typu RBT, wskaznik na korzen drzewa,lancuchy do znakow ramek
* oraz metode wypisz powniewaz jest ona wykorzystywana bezposrednio w metodzie pokaz().
*/

class RBTree
{
  private:
    RBT S;         
    RBT * korzen;        
    string cr,cl,cp;      

    void wypisz(string sp, string sn, RBT * p);

  public:

/*!
*\brief Konstruktor drzewa
*
*Inicjuje straznika. Korzen wskazuje na straznika. Okresla jakie znaki beda tworzyc ramke. 
*/

    RBTree();  

/*!
*\brief Destruktor drzewa
*
*Rekurencyjnie usuwa wezly 
*/
           
    ~RBTree();      

/*!
*\brief Metoda usun
*
*Usuwa po koleji poddrzewa(lewe i prawe) a potem sam wezel
*
*\param[in] p - wskaznik na usuwany wezel i to co jest pod nim
*/
      
    void usun(RBT * p);

/*!
*\brief Metoda pokaz
*
*Wypisuje drzewo na wyjsciu. Wykorzystuje metode wypisz z parametrami:
*sp="" sn="" p=korzen 
*/

    void pokaz();          

/*!
*\brief Metoda szukajRBT
*
*Wyszukuje wezel wykorzystujac jego klucz
*
*\param[in] k - klucz szukanego wezla
*
*\return Zwraca wskaznik na wezel lub NULL jesli wezel nie ostanie znaleziony
*/

    RBT * szukajRBT(int k); 

/*!
*\brief Metoda minRBT
*
*Wyszukuje najmniejszy wezel w poddrzewie o korzeniu p
*
*\param[in] p - wezel pod ktorym szukamy najmniejszego wezla
*
*\return Zwraca wskaznik na najmniejszy wezel
*/

    RBT * minRBT(RBT * p);

/*!
*\brief Metoda nastRBT
*
*Wyszukuje wezel po wezle p
*
*\param[in] p - wezel po ktorym szukamy kolejnego
*
*\return Zwraca wskaznik na wezel po wezle p
*/

    RBT * nastRBT(RBT * p);

/*!
*\brief Metoda obrocLewo
*
*Wykonuje rotacje w lewo wzgledem wezla A
*
*\param[in] A - wezel wzgledem ktorego robiona jest rotacja
*
*/

    void obrocLewo(RBT * A); 

/*!
*\brief Metoda obrocPrawo
*
*Wykonuje rotacje w prawo wzgledem wezla A
*
*\param[in] A - wezel wzgledem ktorego robiona jest rotacja
*
*/

    void obrocPrawo(RBT * A);

/*!
*\brief Metoda wstawRBT
*
*Wstawia wezel o kluczu k do drzewa
*
*	B - black	R - red 
*
*Rozpatruje 3 przypadki:
*
*	Przypadek 1:
*
* 		Wujek C (brat ojca B, czyli drugi syn węzła A) wstawionego węzła X jest czerwony.
*
*							........A(B)......
*							B(R)......	C(R)
*								X(R)
*
*Ojca B i wujka C kolorujemy na czarno. Dziadka A kolorujemy na czerwono. Jeśli węzeł A jest korzeniem drzewa,
*to zmieniamy jego kolor na czarny i kończymy. W przeciwnym razie za nowe X przyjmujemy A i sprawdzamy od początku kolejne przypadki na *wyższym poziomie drzewa.
*
*	Przypadek 2:
*
* 		Wujek C jest czarny, a węzeł X jest prawym dzieckiem węzła B
*
*							........A(B).....
*							B(R).....	C(B)
*								X(R)
*
*Wykonujemy rotację w lewo względem węzła B. Za X przyjmujemy węzeł B i przechodzimy do przypadku 3.
*	
*	Przypadek 3:
*
* 		Wujek C jest czarny, a węzeł X jest lewym dzieckiem węzła B
*
*							........A(B).....
*						........B(R)		C(B)
*						X(R)
*
*
*Wykonujemy rotację w prawo względem węzła A. Zmieniamy kolory węzłów A i B na przeciwne. Operacja wstawiania zostaje zakończona, ponieważ *węzeł B ma taki sam kolor jak poprzednio węzeł A. Zatem operacja rotacji przywróciła strukturę drzewa czerwono-czarnego.
*
*Przypadki lustrzane sa rowniez rozpatrzone w metodzie.
*
*\param[in] k - klucz wstawianego wezla
*
*/

    void wstawRBT(int k);   

/*!
*\brief Metoda usunRBT
*
*Usuwa wybrany wezel
*
*Metoda rozpartuje 4 przypadki:
*
*	Przypadek 1:
*	Usuwany węzeł X nie posiada lewego syna (jest nim węzeł strażnik).
*	Usuwamy z drzewa węzeł X, a na jego miejsce wstawiamy prawego syna Y.
*
*	Przypadek 2:
*	Usuwany węzeł X nie posiada prawego syna.
*	Jest to przypadek symetryczny do przypadku 1. Usuwamy węzeł X, zastępując go lewym synem.
*	Jeśli X był czarny, kolorujemy Y na czarno.
*
*	Przypadek 3:
*	Węzeł X posiada dwóch synów, z których prawy Z jest następnikiem.
*	Węzeł X zastępujemy następnikiem. Lewym synem Z staje się węzeł Y. Następnik otrzymuje kolor węzła X.
*
*	Przypadek 4:
*	Węzeł X posiada dwóch synów, jednak następnik nie jest jego prawym synem.
*	Następnik A zostaje zastąpiony w drzewie swoim prawym synem. Do węzła X kopiujemy zawartość następnika A bez pola koloru. 
*
*\param[in] X - wskaznik na usuwany wezel
*
*/

    void usunRBT(RBT * X); 
};


#endif
