#include "header.h"
#include <stdio.h>

void insertionsort(int arr[], int size) {
    int last;
    int temp;
    int j;
    for(int i = 0; i < size; i++) {
        last = i;
        j = last + 1; //index of first unsorted element
        temp = arr[j]; //cache the first unsorted element

        while(j > 0) {
            if(arr[j - 1] > temp)
                arr[j] = arr[j - 1];
            else
                break;
            j--;
        }
    }
} 