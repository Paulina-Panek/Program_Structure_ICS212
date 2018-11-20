#-*- Makefile -*-

all: main

main : main.o getaddress.o iofunctions.o record.h llist.h
	g++ main.o getaddress.o iofunctions.o llist.o -o main

main.o : main.cpp record.h llist.h
	g++ -ansi -pedantic-errors -Wall -c main.cpp

getaddress.o : getaddress.c record.h
	g++ -ansi -pedantic-errors -Wall -c getaddress.cpp

iofunctions.o : iofunctions.c record.h
	g++ -ansi -pedantic-errors -Wall -c iofunctions.cpp

llist.o : llist.cpp record.h
	g++  -ansi -pedantic-errors -Wall -c llist.cpp  
clean:
	rm -f *.o


