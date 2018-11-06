#-*- Makefile -*-

all: hw7b

hw7b : hw7b.o printinfor.o writefile.o readfile.o changecolor.o header.h
	gcc hw7b.o printinfor.o writefile.o readfile.o changecolor.o -o hw7b

hw7b.o : hw7b.c header.h
	gcc -ansi -pedantic-errors -Wall -c hw7b.c

printinfor.o : printinfor.c header.h
	gcc -ansi -pedantic-errors -Wall -c printinfor.c

writefile.o : writefile.c header.h
	gcc -ansi -pedantic-errors -Wall -c writefile.c

readfile.o : readfile.c header.h
	gcc -ansi -pedantic-errors -Wall -c readfile.c

changecolor.o : changecolor.c header.h
	gcc -ansi -pedantic-errors -Wall -c changecolor.c

clean :
	rm -f *.o


