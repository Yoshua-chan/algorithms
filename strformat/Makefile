main: main.o strformat.o
	gcc main.o strformat.o -o ./main.out -lm

main.o: main.c
	gcc -c main.c

strformat.o: strformat.c strformat.h
	gcc -c strformat.c

clean:
	rm *.o
	rm *.out