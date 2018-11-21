#-*- Makefile -*-

all: main

main : main.o llist.o record.h llist.h
	g++ main.o llist.o -o main

main.o : main.cpp record.h llist.h
	g++ -ansi -pedantic-errors -Wall -c main.cpp

llist.o : llist.cpp record.h llist.h
	g++  -ansi -pedantic-errors -Wall -c llist.cpp  
clean:
	rm -f *.o


