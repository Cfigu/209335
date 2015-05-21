#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic

__start__: Graf
	./Graf

Graf: obj/main.o obj/ListaAr.o obj/Stos.o obj/graff.o
	g++ -Wall -pedantic -o Graf obj/main.o obj/ListaAr.o obj/Stos.o obj/graff.o 

obj/main.o: src/main.cpp
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/graff.o: src/graff.cpp inc/graff.h
	g++ ${CPPFLAGS} -o obj/graff.o src/graff.cpp

obj/Stos.o: src/Stos.cpp inc/Stos.h
	g++ ${CPPFLAGS} -o obj/Stos.o src/Stos.cpp

obj/ListaAr.o: src/ListaAr.cpp inc/ListaAr.h 
	g++ ${CPPFLAGS} -o obj/ListaAr.o src/ListaAr.cpp

clean:
	rm -f obj/*.o Graf
