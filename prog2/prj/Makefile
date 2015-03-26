#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic

__start__: struktury
	./struktury

struktury: obj/main.o obj/Stos.o obj/Kolejka.o obj/Lista.o obj/funkcje.o obj/metmain.o
	g++ -Wall -pedantic -o struktury obj/main.o obj/metmain.o obj/Stos.o obj/Kolejka.o obj/Lista.o obj/funkcje.o

obj/main.o: src/main.cpp inc/metmain.h
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/metmain.o: src/metmain.cpp inc/metmain.h
	g++ ${CPPFLAGS} -o obj/metmain.o src/metmain.cpp

obj/Stos.o: src/Stos.cpp inc/Stos.h
	g++ ${CPPFLAGS} -o obj/Stos.o src/Stos.cpp

obj/Kolejka.o: src/Kolejka.cpp inc/Kolejka.h
	g++ ${CPPFLAGS} -o obj/Kolejka.o src/Kolejka.cpp

obj/Lista.o: src/Lista.cpp inc/Lista.h 
	g++ ${CPPFLAGS} -o obj/Lista.o src/Lista.cpp

obj/funkcje.o: src/funkcje.cpp inc/funkcje.h
	g++ ${CPPFLAGS} -o obj/funkcje.o src/funkcje.cpp

clean:
	rm -f obj/*.o struktury
