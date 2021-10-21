CC=gcc
objects=main.o matrix.o

main.out: $(objects)
	$(CC) $(objects) -o main.out

main.o: main.c
	$(CC) -c main.c 

matrix.o: matrix.c
	$(CC) -c matrix.c

clean:
	rm *.o *.out