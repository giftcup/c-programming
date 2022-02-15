word_sort: read_word.o word_sort.o sort.o
	gcc -o word_sort read_word.o sort.o word_sort.o

qword_sort: read_word.o word_sort.o qsortx.o
	gcc -o qword_sort read_word.o qsortx.o word_sort.o

read_word.o: read_word.h read_word.c
	gcc -c read_word.c

word_sort.o: read_word.h word_sort.c
	gcc -c word_sort.c

sort.o : sort.h sort.c
	gcc -c sort.c

qsortx.o: qsortx.h qsortx.c
	gcc -c qsortx.c

clean:
	rm *.o word_sort
