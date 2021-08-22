#include <stdio.h>
#include "header.h"

void quicksort(int arr[], int left, int right) {
        return;
}

void quicksort_kernighan(int arr[], int left, int right) {
    int i, last;
    void swap(int arr[], int x, int y);
    if(left >= right)
        return;
    swap(arr, left, (left + right)/2);
    last = left;
    for(i = left + 1; i <= right; i++)
        if(arr[i] < arr[left])
            swap(arr, ++last, i);
    swap(arr, left, last);
    quicksort_kernighan(arr, left, last - 1);
    quicksort_kernighan(arr, last + 1, right);
}