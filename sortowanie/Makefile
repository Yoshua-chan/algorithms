CC=gcc

main.out: main.o bubblesort.o swap.o
	$(CC) main.o bubblesort.o swap.o -o main.out

bubblesort.o: swap.o header.h bubblesort.c
	$(CC) bubblesort.c -c

swap.o: swap.c header.h
	$(CC) swap.c -c

main.o: main.c header.h
	$(CC) main.c -c

clean:
	rm *.o main.out