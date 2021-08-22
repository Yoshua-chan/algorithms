#include <stdlib.h>
#include <stdio.h>
#include "header.h"

void merge(int arr[], int left, int middle, int right) {
  int i, j, k;
  int sizeL, sizeR;

  sizeL = middle - left + 1;
  sizeR = right - middle;

  int* L = malloc(sizeL * sizeof(int));
  int* R = malloc(sizeR * sizeof(int));

  //int L[sizeL];
  //int R[sizeR];

  //copy from main array to two auxilarry arrays
  for(i = 0; i < sizeL; i++)
    L[i] = arr[i + left];
  for(i = 0; i < sizeR; i++)
    R[i] = arr[i + middle + 1];

  i = 0;
  j = 0;
  k = left;

  while(i < sizeL && j < sizeR) {
    if(L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  while(i < sizeL) {
    arr[k] = L[i];
    i++;
    k++;
  }
  while(j < sizeR) {
    arr[k] = R[j];
    j++;
    k++;
  }

  free(L);
  free(R);
}

void mergesort(int arr[], int left, int right) {
  if(left < right) {
    int middle = left + (right - left)/2;

    mergesort(arr, left, middle);
    mergesort(arr, middle + 1, right);
    
    merge(arr, left, middle, right);
  }
}