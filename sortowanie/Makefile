CC=gcc

objects = quicksort.o bubblesort.o insertionsort.o selectsort.o mergesort.o

#main/common
main.out: main.o $(objects) swap.o test.o
	$(CC) main.o $(objects) swap.o test.o -o main.out

main.o: main.c header.h
	$(CC) main.c -c

swap.o: swap.c header.h
	$(CC) swap.c -c

test.o: test.c header.h
	$(CC) test.c -c

#pliki algorytmów sortujących
quicksort.o: swap.o header.h quicksort.c
	$(CC) quicksort.c -c

bubblesort.o: swap.o header.h bubblesort.c
	$(CC) bubblesort.c -c

insertionsort.o: swap.o header.h insertionsort.c
	$(CC) insertionsort.c -c

selectsort.o: swap.o header.h selectsort.c
	$(CC) selectsort.c -c

mergesort.o: swap.o header.h mergesort.c
	$(CC) mergesort.c -c


clean:
	rm *.o main.out