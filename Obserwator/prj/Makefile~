#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic

__start__: Sort
	./Sort

Sort: obj/main.o obj/ListaAr.o 
	g++ -Wall -pedantic -o Sort obj/main.o obj/ListaAr.o 

obj/main.o: src/main.cpp
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/ListaAr.o: src/ListaAr.cpp inc/ListaAr.h 
	g++ ${CPPFLAGS} -o obj/ListaAr.o src/ListaAr.cpp

clean:
	rm -f obj/*.o Sort
