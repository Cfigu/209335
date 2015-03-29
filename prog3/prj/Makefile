#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic

__start__: listy
	./listy

listy: obj/main.o obj/metmain.o obj/ListaAr.o obj/Lista.o obj/funkcje.o
	g++ -Wall -pedantic -o listy obj/main.o obj/metmain.o obj/ListaAr.o obj/Lista.o obj/funkcje.o

obj/main.o: src/main.cpp
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/metmain.o: src/metmain.cpp inc/metmain.h
	g++ ${CPPFLAGS} -o obj/metmain.o src/metmain.cpp

obj/ListaAr.o: src/ListaAr.cpp inc/ListaAr.h
	g++ ${CPPFLAGS} -o obj/ListaAr.o src/ListaAr.cpp

obj/Lista.o: src/Lista.cpp inc/Lista.h 
	g++ ${CPPFLAGS} -o obj/Lista.o src/Lista.cpp

obj/funkcje.o: src/funkcje.cpp inc/funkcje.h
	g++ ${CPPFLAGS} -o obj/funkcje.o src/funkcje.cpp

clean:
	rm -f obj/*.o listy
