exercise: ex7.o generate_fraction.o operation.o
	gcc -o exercise ex7.o generate_fraction.o operation.o
ex7.o: ex7.c ex7.h generate_fraction.h operation.h
	gcc -c ex7.c
generate_fraction.o: generate_fraction.c generate_fraction.h ex7.h
	gcc -c generate_fraction.c
operation.o: operation.c operation.h generate_fraction.h ex7.h
	gcc -c operation.c
clear:
	rm *.o exercise