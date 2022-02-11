word_sort: read_word.o word_sort.o
	gcc -o word_sort read_word.o word_sort.o

read_word.o: read_word.h read_word.c
	gcc -c read_word.c

word_sort.o: read_word.h word_sort.c
	gcc -c word_sort.c

clean:
	rm *.o word_sort
