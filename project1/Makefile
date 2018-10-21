#-*- Makefile -*-

all: main

main : main.o getaddress.o stubs.o record.h
	gcc -include record.h main.o getaddress.o stubs.o -o main

main.o : main.c record.h
	gcc -include record.h -ansi -pedantic-errors -Wall -c main.c

getaddress.o : getaddress.c  record.h
	gcc -include record.h -ansi -pedantic-errors -Wall -c getaddress.c

stubs.o : stubs.c record.h
	gcc -include record.h -ansi -pedantic-errors -Wall -c stubs.c

clean:
	rm -f *.o


