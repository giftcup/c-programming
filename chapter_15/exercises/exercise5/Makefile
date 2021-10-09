demo: main.o f1.o f2.o
	gcc -o main.o f1.o f2.o
main.o: f1.h main.c
	gcc -c main.c
f1.o: f1.h f2.h f1.c
	gcc -c f1.c
f2.o: f1.h f2.h f2.c
	gcc -c f2.c