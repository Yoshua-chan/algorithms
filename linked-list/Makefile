CC=gcc
objects=main.o double-list.o linked-list.o
main.out: $(objects) list.h 
	$(CC) $(objects) -o ./main.out

main.o: main.c list.h
	$(CC) main.c -c

linked-list.o: linked-list.c list.h
	$(CC) linked-list.c -c

double-list.o: double-list.c list.h
	$(CC) double-list.c -c

clean:
	rm *.o *.out