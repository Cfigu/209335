#ifndef LISTA_ARR_H
#define LISTA_ARR_H
#include<iostream>

namespace arr
{
  class Lista
  {
    // Przechowuje adres do pierwszego elementu listy
    int *tablica;
    int rozmiar_ls;
    int pojemnosc_ls;
    /*!
      \brief Metoda zwiększa dwukrotnie pojemnosć listy.
    */
    void rozszerz_x2();
    /*!
      \brief Metoda zwiększa pojemnosć listy o 1.
    */
    void rozszerz_1();
  public:
    /*!
      \brief Konstruktor domyślny klasy arr::Lista.
    */
  Lista(): tablica(new int), rozmiar_ls(0), pojemnosc_ls(1){}
    /*!
      \brief Konstruktor kopiujący klasy arr::Lista.
      Bezużyteczny dla trzeciego zadania, ale na pewno kolega się ucieszy.
    */
    Lista(const Lista &lewy);
    /*!
      \brief Destruktor klasy arr::Lista.
    */
    ~Lista(){delete [] tablica;}
    /*!
      \brief Usuwa z listy element o wybranym indeksie.
      Zapisuje wartość przechowywaną pod danym indeksem a potem
      przesuwa całą zawartość tablicy młodszą od danego elementu
      o 1 w stronę starszych elementów. Zmniejsza licznik rozmiar_ls
      o 1.
      Przykład 1:
      Wyrażenie obj.erase(0) usuwa najmłodszy element kontenera.
      Przykład 2:
      Wyrażenie obj.erase(obj.size() - 1) usuwa najstarszy element.
      Przykład 3:
      Wyrażenie obj.erase(obj.size()) nie zmienia kontenera.
      \return Zwraca wartość przechowywaną w usuniętej cegiełce.
    */
    int erase(int);
    /*!
      \brief Umieszcza cegłę z wartością 'wartosc' w miejscu
      oddalonym o 'indeks' miejsc od początku kontenera.
      Zwiększa licznik rozmiar_ls o 1, odsuwa wszystkie elementy
      młodsze od danego indeksu o 1 od starszych i umieszcza
      wartość w odpowiednim indeksie. Może powodować realokację
      zawartości listy!
      UWAGA: Indeks liczony jest od zera, od najmłodszej cegły.
      Przykład 1:
      Wyrażenie obj.insert(5,0) jest równoważne wyrażeniu obj.push(5)
      - element zawierający wartość 5 jest teraz najmłodszym
      elementem.
      Przykład 2:
      Wyrażenie obj.insert(3,obj.size()) czyni element zawierający
      wartosć 3 najstarszym elementem.
    */
    void insert(int,int);
    /*!
      \brief Sprawdza, czy lista jest pusta.
      \return Zwraca prawdę, jeżeli lista jest pusta. W przeciwnym razie zwraca false.
    */
    bool empty();
    /*!
      \brief Zwraca rozmiar listy.
    */
    int size(){return rozmiar_ls;}

/*!
      \brief Dzieli liste na dwie czesci.
      \return Zwraca punkt podzialu listy.
    */
    int dziel(int lewo, int prawo);
/*!
      \brief Dzieli liste na dwie czesci oraz dobier pivot porownujac 3 elementy listy - pierwszy, srodkowy i ostatni.
      \return Zwraca punkt podzialu listy.
    */
int dziel2(int lewo, int prawo);
/*!
      \brief QuickSort - Sortuje elementy listy od najmniejszego do największego. Wykorzystuje metode dziel.
    */	
    void sortuj(int lewo,int prawo);
/*!
      \brief QuickSort(optymalizacja) - Sortuje elementy listy od najmniejszego do największego. Wykorzystuje metode dziel2.
    */
    void sortuj_opt(int lewo, int prawo);
/*!
      \brief Metoda oblicza czas posortowania listy o zadanej ilosci elementow. Powtarza ta operacje 10 razy i oblicza sredni czas sortowania.
Wyswietla poszczegolny czas oraz czas sredni. Wykorzystuje metode sortuj.
    */
void operacja_licz_qs(int roz);
/*!
      \brief Metoda oblicza czas posortowania listy o zadanej ilosci elementow. Powtarza ta operacje 10 razy i oblicza sredni czas sortowania.
Wyswietla poszczegolny czas oraz czas sredni. Wykorzystuje metode sortuj_opt.
    */
void operacja_licz_qs_opt(int roz);
  

    void show()
    {
      for(int i = 0; i < this->rozmiar_ls; ++i)
	std::cout << this->tablica[i] << ' ';
    }	
  };
}
  
#endif
