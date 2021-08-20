#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {
    time_t t;
    srand((unsigned) time(&t));

    int tab[20];
     
    for(int i = 0; i < 20; i++)
        tab[i] = rand() % 100;

    printf("\n");
    {
        bubblesort(tab, 20);

        for(int i = 0; i < 20; i++)
            printf("|%2d", tab[i]);
        putchar('|');
        printf(" - bubblesort");
    }
    return 0;
}