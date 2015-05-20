#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic

__start__: RBTREE
	./RBTREE

RBTREE: obj/main.o obj/RBTree.o 
	g++ -Wall -pedantic -o RBTREE obj/main.o obj/RBTree.o  

obj/main.o: src/main.cpp
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/RBTree.o: src/RBTree.cpp inc/RBTree.h
	g++ ${CPPFLAGS} -o obj/RBTree.o src/RBTree.cpp

clean:
	rm -f obj/*.o RBTREE
