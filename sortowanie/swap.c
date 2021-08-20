#include <stdlib.h>
#include "header.h"

void swap(int arr[], int x, int y) {
    int tmp;
    tmp = arr[x];
    arr[x] = arr[y];
    arr[y] = tmp;
}

int validate(int arr[], int size) { /* sprawdza czy tablica jest posortowana */
    for(int i = 0; i < size - 1; i++) {
        if(arr[i] > arr[i + 1])
            return 0;
    }
    return 1;
}

void intcopy(int from[], int to[], int size) {
    for(int i = 0; i < size; i++)
        to[i] = from[i];
}