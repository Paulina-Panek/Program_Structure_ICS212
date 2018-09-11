#-*- Makefile -*-

#Paulina Panek
#09/10/2018
#ICS212 HW2a

#target: dependencies
#	action

all: exercise1

exercise1: exercise1.o isDivisible.o getInt.o exercise1.h
	gcc exercise1.o isDivisible.o getInt.o -o exercise1

exercise1.o: exercise1.c exercise1.h
	gcc -ansi -pedantic-errors -Wall -c exercise1.c

isDivisible.o: isDivisible.c
	gcc -ansi -pedantic-errors -Wall -c isDivisible.c

getInt.o: getInt.c
	gcc -ansi -pedantic-errors -Wall -c getInt.c

clean:
	rm -f *.o
