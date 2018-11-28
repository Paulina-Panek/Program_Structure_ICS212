#-*- Makefile -*-

all: hw9

hw9: hw9.class header.h libhw9.so
	java -Djava.library.path=. hw9

hw9.class: hw9.java
	javac hw9.java

header.h: hw9.java
	javah -jni hw9

libhw9.so: isDivisible.o
	gcc -I/usr/jdk/jdk1.7.0_51/include -I/usr/jdk/jdk1.7.0_51/include/solaris -shared -o libhw9.so isDivisible.o

isDivisible.o: isDivisible.c header.h
	gcc -fPIC -I/usr/jdk/jdk1.7.0_51/include -I/usr/jdk/jdk1.7.0_51/include/solaris -c isDivisible.c

clean:
	rm -f *.o
