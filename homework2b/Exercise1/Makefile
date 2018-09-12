#-*- Makefile -*-

#Paulina Panek
#ICS212 HW2b
#09/13/2018

#target: dependencies
#	action

all: halfstring

halfstring: halfstring.o driver.o halfstring.h
	gcc halfstring.o driver.o -o halfstring

halfstring.o: halfstring.c halfstring.h
	gcc -ansi -pedantic-errors -Wall -c halfstring.c

driver.o: driver.c halfstring.h
	gcc -ansi -pedantic-errors -c driver.c

clean:
	rm -f *.o
