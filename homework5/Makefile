#-*- Makefile -*-

all: driver

driver : driver.o iofunctions.o prototypes.h record.h
	gcc driver.o iofunctions.o -o driver

driver.o : driver.c record.h prototypes.h
	gcc -ansi -pedantic-errors -Wall -c driver.c

iofunctions.o : iofunctions.c  record.h
	gcc -ansi -pedantic-errors -Wall -c iofunctions.c

clean:
	rm -f *.o
