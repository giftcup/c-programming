qsort: qsort.o quicksort.o
	gcc -o qsort qsort.o quicksort.o

qsort.o: qsort.c quicksort.h
	gcc -c qsort.c

quicksort.o: quicksort.h quicksort.c
	gcc -c quicksort.c