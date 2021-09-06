#include <stdio.h>
#include "header.h"

#define true (unsigned char)1
void quicksort(int arr[], int left, int right) {
    if(left >= right) return;

    int L = left, R = right;
    int pivot = arr[(left + right)/2];
    
    do {
        while(arr[L] < pivot) L++;
        while(arr[R] > pivot) R--;
        if(R >= L) {
            swap(arr, L, R);
            L++;
            R--;
        }
    } while(L <= R);
    if(L > left)  quicksort(arr, left, R);
    if(R < right) quicksort(arr, L, right);
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