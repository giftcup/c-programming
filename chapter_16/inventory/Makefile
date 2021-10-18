HEADERS = inventory.h readline.h insert.h search.h update.h 
inventory: inventory.o insert.o readline.o search.o update.o
	gcc -o inventory inventory.o insert.o readline.o search.o update.o -v
inventory.o: inventory.c $(HEADERS)
	gcc -c inventory.c
insert.o: insert.c $(HEADERS)
	gcc -c insert.c
search.o: search.c $(HEADERS)
	gcc -c search.c
update.o: update.c $(HEADERS)
	gcc -c update.c
readline.o: readline.c $(HEADERS)
	gcc -c readline.c
clear:
	rm *.o