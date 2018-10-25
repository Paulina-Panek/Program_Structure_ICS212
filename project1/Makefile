#-*- Makefile -*-

all: main

main : main.o getaddress.o deleteRecord.o addRecord.o printRecord.o printAll.o iofunctions.o record.h
	gcc main.o getaddress.o addRecord.o deleteRecord.o printRecord.o printAll.o iofunctions.o -o main

main.o : main.c record.h
	gcc -ansi -pedantic-errors -Wall -c main.c

getaddress.o : getaddress.c  record.h
	gcc -ansi -pedantic-errors -Wall -c getaddress.c

deleteRecord.o : deleteRecord.c record.h
	gcc -ansi -pedantic-errors -Wall -c deleteRecord.c

addRecord.o : addRecord.c record.h
	gcc -ansi -pedantic-errors -Wall -c addRecord.c

printRecord.o : printRecord.c record.h
	gcc -ansi -pedantic-errors -Wall -c printRecord.c

printAll.o : printAll.c record.h
	gcc -ansi -pedantic-errors -Wall -c printAll.c

iofunctions.o : iofunctions.c record.h
	gcc -ansi -pedantic-errors -Wall -c iofunctions.c

clean:
	rm -f *.o


