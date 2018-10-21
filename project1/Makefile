#-*- Makefile -*-

all: main

main : main.o getaddress.o stubs.o deleteRecord.o addRecord.o record.h
	gcc main.o getaddress.o stubs.o addRecord.o deleteRecord.o -o main

main.o : main.c record.h
	gcc -ansi -pedantic-errors -Wall -c main.c

getaddress.o : getaddress.c  record.h
	gcc -ansi -pedantic-errors -Wall -c getaddress.c

stubs.o : stubs.c record.h
	gcc -ansi -pedantic-errors -Wall -c stubs.c

deleteRecord.o : deleteRecord.c record.h
	gcc -ansi -pedantic-errors -Wall -c deleteRecord.c

addRecord.o : addRecord.c record.h
	gcc -ansi -pedantic-errors -Wall -c addRecord.c

clean:
	rm -f *.o


