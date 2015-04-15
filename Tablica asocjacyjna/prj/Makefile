#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic

__start__: Aso
	./Aso

Aso: obj/main.o obj/AsoTab.o  obj/Lista.o 
	g++ -Wall -pedantic -o Aso obj/main.o obj/AsoTab.o  obj/Lista.o 

obj/main.o: src/main.cpp
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/AsoTab.o: src/AsoTab.cpp inc/AsoTab.h
	g++ ${CPPFLAGS} -o obj/AsoTab.o src/AsoTab.cpp

obj/Lista.o: src/Lista.cpp inc/Lista.h 
	g++ ${CPPFLAGS} -o obj/Lista.o src/Lista.cpp

clean:
	rm -f obj/*.o Aso
