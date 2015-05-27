#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic

__start__: Graf
	./Graf

Graf: obj/main.o obj/ListaAr.o obj/Stos.o obj/Kolejka.o obj/graff.o obj/Benchmark.o obj/operacja.o
	g++ -Wall -pedantic -o Graf obj/main.o obj/ListaAr.o obj/Stos.o obj/graff.o obj/Kolejka.o obj/Benchmark.o obj/operacja.o

obj/main.o: src/main.cpp
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/graff.o: src/graff.cpp inc/graff.h
	g++ ${CPPFLAGS} -o obj/graff.o src/graff.cpp

obj/Kolejka.o: src/Kolejka.cpp inc/Kolejka.h
	g++ ${CPPFLAGS} -o obj/Kolejka.o src/Kolejka.cpp

obj/Stos.o: src/Stos.cpp inc/Stos.h
	g++ ${CPPFLAGS} -o obj/Stos.o src/Stos.cpp

obj/ListaAr.o: src/ListaAr.cpp inc/ListaAr.h 
	g++ ${CPPFLAGS} -o obj/ListaAr.o src/ListaAr.cpp

obj/Benchmark.o: src/Benchmark.cpp inc/Benchmark.h 
	g++ ${CPPFLAGS} -o obj/Benchmark.o src/Benchmark.cpp

obj/operacja.o: src/operacja.cpp inc/operacja.h 
	g++ ${CPPFLAGS} -o obj/operacja.o src/operacja.cpp

clean:
	rm -f obj/*.o Graf
