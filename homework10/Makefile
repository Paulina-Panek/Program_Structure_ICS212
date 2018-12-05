#-*- Makefile -*-

all: main

main: main.o Pokemon.o Charizard.o Mew.o Pikachu.o Pokemon.h Charizard.h Mew.h Pikachu.h
	g++ main.o Pokemon.o Charizard.o Mew.o Pikachu.o -o main

main.o: main.cpp Pokemon.h Charizard.h Mew.h Pikachu.h
	g++ -ansi -pedantic-errors -Wall -c main.cpp

Pokemon.o: Pokemon.cpp Pokemon.h Charizard.h Mew.h Pikachu.h
	g++ -ansi -pedantic-errors -Wall -c Pokemon.cpp

Charizard.o: Charizard.cpp Pokemon.h Charizard.h Mew.h Pikachu.h
	g++ -ansi -pedantic-errors -Wall -c Charizard.cpp

Mew.o: Mew.cpp Pokemon.h Charizard.h Mew.h Pikachu.h
	g++ -ansi -pedantic-errors -Wall -c Mew.cpp

Pikachu.o: Pikachu.cpp Pokemon.h Charizard.h Mew.h Pikachu.h
	g++ -ansi -pedantic-errors -Wall -c Pikachu.cpp

clean:
	rm -f *.o
