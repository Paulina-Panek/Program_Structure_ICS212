#-*- Makefile -*-

all: main

main : main.o iofunctions.o record.h llist.h
	g++ main.o iofunctions.o llist.o -o main

main.o : main.cpp record.h llist.h
	g++ -ansi -pedantic-errors -Wall -c main.cpp

iofunctions.o : iofunctions.c record.h
	g++ -ansi -pedantic-errors -Wall -c iofunctions.cpp

llist.o : llist.cpp record.h
	g++  -ansi -pedantic-errors -Wall -c llist.cpp  
clean:
	rm -f *.o


