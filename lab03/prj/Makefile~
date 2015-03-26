CFLAGS = -c -pedantic -Wall
CMP = g++
OBJ = obj/main.o obj/benchmark.o obj/operacja.o obj/kontener.o \
	obj/stos_arr.o obj/kolejka_arr.o

../program: $(OBJ)
	$(CMP) $^ -o $@

obj/main.o: src/main.cpp
	$(CMP) $(CFLAGS) $< -o $@

obj/benchmark.o: src/benchmark.cpp inc/benchmark.h
	$(CMP) $(CFLAGS) $< -o $@

obj/operacja.o: src/operacja.cpp inc/operacja.h
	$(CMP) $(CFLAGS) $< -o $@

obj/kontener.o: src/kontener.cpp inc/kontener.h
	$(CMP) $(CFLAGS) $< -o $@

obj/stos_arr.o: src/stos_arr.cpp inc/stos_arr.h
	$(CMP) $(CFLAGS) $< -o $@

obj/kolejka_arr.o: src/kolejka_arr.cpp inc/kolejka_arr.h
	$(CMP) $(CFLAGS) $< -o $@
clean:
	rm -f obj/*.o
