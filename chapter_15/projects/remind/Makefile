remind: remind.o readline.o
	gcc -o remind remind.o readline.o

remind.o: readline.h remind.c
	gcc -c remind.c

readline.o: readline.h readline.c
	gcc -c readline.c