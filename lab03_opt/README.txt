LAB03 - implementacja podstawowych strukur danych z użyciem tablic.

0. W pliku .../lab03/prj/inc/ustawienia.h dostępne są makra regulujące pracę związaną z tworzeniem, wczytywaniem, zapisem i pomiarem danych.

1. W katalogu 'lab3' należy wywołać polecenie 'make' - utworzone powinny zostać dwa exe'y: 'generuj' oraz 'program'.

2. Należy uruchomić program 'generuj' - powinien on stworzyć plik z ciągiem danych o nazwie określonej w pliku ustawienia.h (domyślnie: dane.dat).

3. Należy uruchomić program 'program' - powinien on stworzyć plik z wynkiami pomiarów czasu wykonywanych operacji. Nazwa pliku określona jest w nagłówku ustawienia.h (domyślnie: wyniki.dat). 

4. Plik wyniki.dat można podać do Gnuplota, żeby narysować wykres. W ym celu należy w wierzu poleceń wprowadzić następujące polecenia:
	
$ gnuplot
> set logscale xy
> plot "wyniki.dat"

UWAGA: implementacja dostarcza zestaw odpowiednich metod służących do manipulowania strukturami danych, ale nie zabezpiecza przed nieodpowiednim ich użyciem! Dlatego należy mieć minimalne pojęcie na temat tego, co się robi - np. przed użyciem metody 'pop()' należałoby się upewnić, czy przypadkiem struktura danych nie jest pusta.
