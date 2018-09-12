#-*- Makefile -*-

#Paulina Panek
#ICS212 HW2b
#09/13/2018

#target: dependencies
#	action

all: practice

practice: practice.o
	gcc practice.o -o practice

practice.o: practice.c
	gcc -ansi -pedantic-errors -Wall -c practice.c

clean:
	rm -f *.o
