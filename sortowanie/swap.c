#include "header.h"

void swap(int arr[], int x, int y) {
    int tmp;
    tmp = arr[x];
    arr[x] = arr[y];
    arr[y] = tmp;
}