#include "header.h"

void bubblesort(int arr[], int size) {
    for(int i = size - 1; i > 0; i--) 
        for(int j = 0; j < i; j++)
            if(arr[j] > arr[j + 1])
                swap(arr, j, j+1);
}