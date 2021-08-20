#include "header.h"

void selectsort(int arr[], int size) {
    int lowest; //index for current lowest number
    for(int i = 0; i < size - 1; i++) {
        lowest = i;
        for(int j = i + 1; j < size; j++)
            if(arr[lowest] > arr[j])
                lowest = j;
        swap(arr, i, lowest);
    }
}