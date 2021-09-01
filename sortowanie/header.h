#pragma once

#define BUBBLE  0b00000001U
#define MERGE   0b00000010U
#define QUICK   0b00000100U
#define QUICK_K 0b00001000U
#define SELECT  0b00010000U
#define INSERT  0b00100000U
#define REVERSE 0b01000000U
#define SORTED  0b10000000U


#define ALL     0b00111111U

typedef unsigned char byte;
void swap(int arr[], int x, int y);
void bubblesort(int arr[], int size);
void selectsort(int arr[], int size);
void insertionsort(int arr[], int size);
void quicksort(int arr[], int left, int right);
void mergesort(int arr[], int left, int right);
void quicksort_kernighan(int arr[], int left, int right);
int validate(int arr[], int size);
void intcopy(int from[], int to[], int size);
void test(int size, byte FLAGS);
void merge(int arr[], int left, int middle, int right);
