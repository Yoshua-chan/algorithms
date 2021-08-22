#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"


void test(int size, byte FLAGS) {

    int range = 10000000;
    int* tab  = malloc(size * sizeof(int));
    int* copy = malloc(size * sizeof(int));
    double seconds;
    unsigned long int ticks_before;
    unsigned long int ticks_after;
    
    time_t now;
    srand((unsigned) time(&now));

    
    char format[] = "|%7d |%15s|%9d |%13.6f s |\n";
     
    for(int i = 0; i < size; i++)
        tab[i] = rand() % range;

    printf("|%s|%s|%s|%s|\n", " SORTED " ,"   ALGORITHM   ", " ELEMENTS ", "      TIME      ");
    printf("|--------|---------------|----------|----------------|\n");

    // Quicksort
    if(FLAGS & QUICK){
        intcopy(tab, copy, size);

        ticks_before = clock();
        quicksort(copy, 0 , size);
        ticks_after = clock();

        seconds = (double)(ticks_after - ticks_before)/CLOCKS_PER_SEC;
        printf(format, validate(copy, size), "Quick sort", size, seconds);
    }

    // Quicksort - Kernighan
    if(FLAGS & QUICK_K){
        intcopy(tab, copy, size);

        ticks_before = clock();
        quicksort_kernighan(copy, 0 , size);
        ticks_after = clock();

        seconds = (double)(ticks_after - ticks_before)/CLOCKS_PER_SEC;
        printf(format, validate(copy, size),"Quick sort K&R", size, seconds);
    }

    // Merge sort
    if(FLAGS & MERGE){
        intcopy(tab, copy, size);

        ticks_before = clock();
        mergesort(copy, 0 , size - 1);
        ticks_after = clock();

        seconds = (double)(ticks_after - ticks_before)/CLOCKS_PER_SEC;
        printf(format, validate(copy, size), "Merge sort", size, seconds);
    }

    // Bubblesort
    if(FLAGS & BUBBLE){
        intcopy(tab, copy, size);

        ticks_before = clock();
        bubblesort(copy, size);
        ticks_after = clock();

        seconds = (double)(ticks_after - ticks_before)/CLOCKS_PER_SEC;
        printf(format, validate(copy, size), "Bubble sort", size, seconds);
    }

    // Insertion sort
    if(FLAGS & INSERT){
        intcopy(tab, copy, size);

        ticks_before = clock();
        insertionsort(copy, size);
        ticks_after = clock();

        seconds = (double)(ticks_after - ticks_before)/CLOCKS_PER_SEC;
        printf(format, validate(copy, size), "Insertion sort", size, seconds);
    }


    // Select sort
    if(FLAGS & SELECT){
        intcopy(tab, copy, size);

        ticks_before = clock();
        selectsort(copy, size);
        ticks_after = clock();

        seconds = (double)(ticks_after - ticks_before)/CLOCKS_PER_SEC;
        printf(format, validate(copy, size), "Select sort", size, seconds);
    }

}